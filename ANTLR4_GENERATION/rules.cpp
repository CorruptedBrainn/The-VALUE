#include "rules.h"

std::any ValuescriptRuntimeRules::visit(tree::ParseTree* tree)
{
	//std::cout << "Enter: " << tree->getText() << "\n\n";
	std::any ret = tree->accept(this);
	//std::cout << "Exit: " << tree->getText() << "\n\n";
	return ret;
}

std::any ValuescriptRuntimeRules::visitFile(ValuescriptParser::FileContext* ctx)
{
	globalBlock = std::make_shared<Runtime::BlockScope>("GLOBAL_BLOCK", nullptr, globalGeneric);
	callStack.push(globalBlock);
	std::vector<ValuescriptParser::ExtraContext*> addedImports = ctx->extra();
	for (ValuescriptParser::ExtraContext* curr : addedImports) {
		visit(curr);
	}
	std::vector<ValuescriptParser::StatementContext*> toVisit = ctx->statement();
	for (ValuescriptParser::StatementContext* curr : toVisit) {
		visit(curr);
		if (callStack.top()->getGeneric()->getRet() != nullptr) {
			callStack.top()->getGeneric()->setRet(nullptr);
			break;
		}
	}
	callStack.pop();
	globalBlock = nullptr;
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitExtra(ValuescriptParser::ExtraContext* ctx)
{
	std::string import = ctx->IDENTIFIER()->getText();
	if (imports.contains(import)) return defaultResult();
	std::string name = "../ValuescriptImports/" + import + ".vsef";
	std::ifstream file(name);
	std::string script((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	imports.emplace(std::make_pair(import, std::make_unique<ExtraImport>(script)));
	std::unordered_map<std::string, std::unique_ptr<ExtraImport>>::iterator library = imports.find(import);
	for (ValuescriptParser::StatementContext* curr : library->second->tree->statement()) {
		visit(curr);
	}
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementvardecl(ValuescriptParser::StatementvardeclContext* ctx)
{
	visit(ctx->variabledeclaration());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext* ctx)
{
	visit(ctx->functiondeclaration());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext* ctx)
{
	visit(ctx->classdeclaration());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementif(ValuescriptParser::StatementifContext* ctx)
{
	visit(ctx->ifstatement());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementwhile(ValuescriptParser::StatementwhileContext* ctx)
{
	visit(ctx->whilestatement());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementdo(ValuescriptParser::StatementdoContext* ctx)
{
	visit(ctx->dostatement());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementfor(ValuescriptParser::StatementforContext* ctx)
{
	visit(ctx->forstatement());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementnative(ValuescriptParser::StatementnativeContext* ctx)
{
	int key = std::stoi(ctx->INTEGER_LITERAL()->getText());
	std::shared_ptr<Runtime::AbstractObject> expr = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	switch (key) {
	case 1: { // Printing Pure Value
		std::cout << "Runtime Output: " << *expr.get() << "\n\n";
		break;
	}
	case 2: { // Breakpoint
		std::cout << " -- Runtime Breakpoint -- \n\n";
		break;
	}
	case 3: { // Enter Base Member
		importing = std::any_cast<std::string>(expr->getValue());
		break;
	}
	case 4: { // Exit Base Member
		importing = "";
		break;
	}
	case 5: { // Get Base Object
		importObject = expr;
		break;
	}
	case 6: { // Array Append
		if (importObject->getType().name == "Variable") {
			importObject = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(importObject->getValue());
		}
		std::shared_ptr<Runtime::ConcreteArray> obj = std::static_pointer_cast<Runtime::ConcreteArray>(importObject);
		obj->array_append_single(std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(expr->copy()->getValue()));
		break;
	}
	case 7: { // Array Clear
		if (importObject->getType().name == "Variable") {
			importObject = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(importObject->getValue());
		}
		std::shared_ptr<Runtime::ConcreteArray> obj = std::static_pointer_cast<Runtime::ConcreteArray>(importObject);
		obj->array_clear_elements();
		break;
	}
	case 8: { // Array Empty
		if (importObject->getType().name == "Variable") {
			importObject = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(importObject->getValue());
		}
		std::shared_ptr<Runtime::ConcreteArray> obj = std::static_pointer_cast<Runtime::ConcreteArray>(importObject);
		return obj->array_check_empty();
	}
	case 9: { // Array Size
		if (importObject->getType().name == "Variable") {
			importObject = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(importObject->getValue());
		}
		std::shared_ptr<Runtime::ConcreteArray> obj = std::static_pointer_cast<Runtime::ConcreteArray>(importObject);
		return obj->array_check_size();
	}
	}
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementexpr(ValuescriptParser::StatementexprContext* ctx)
{
	visit(ctx->expression());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementret(ValuescriptParser::StatementretContext* ctx)
{
	if (ctx->expression() == nullptr) {
		factory = new Runtime::VoidCreator;
		std::shared_ptr<Runtime::AbstractLiteral> ret = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject());
		delete factory;
		callStack.top()->getGeneric()->setRet(ret);
	}
	else {
		std::shared_ptr<Runtime::AbstractObject> oret = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
		std::shared_ptr<Runtime::AbstractLiteral> ret = std::static_pointer_cast<Runtime::AbstractLiteral>(oret->copy());
		callStack.top()->getGeneric()->setRet(ret);
	}
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementbreak(ValuescriptParser::StatementbreakContext* ctx)
{
	callStack.top()->setBroken(true);
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx)
{
	std::shared_ptr<Runtime::AbstractLiteral> val = nullptr;
	Runtime::TypeInformation ty = std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression()));
	std::shared_ptr<Runtime::AbstractObject> ocls = callStack.top()->getGeneric()->findMember(ty.name);
	if (ctx->expression() != nullptr) {
		std::shared_ptr<Runtime::AbstractObject> oval = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
		if (oval->getType().name == "Variable") {
			oval = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(oval->getValue())->copy();
		}
		val = std::static_pointer_cast<Runtime::AbstractLiteral>(oval);
		if (val->getType().name == "Object") {
			if (ocls != nullptr) {
				std::shared_ptr<Runtime::ConcreteClass> cls = std::static_pointer_cast<Runtime::ConcreteClass>(ocls);
				val->getType() = ty;
				val->getMembers() = cls->getScope()->getMembers();
			}
			else {
				if (ty.name == "Pair") factory = new Runtime::PairCreator;
				else if (ty.name == "Array") factory = new Runtime::ArrayCreator;
				else if (ty.name == "Set") factory = new Runtime::SetCreator;
				val = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject({ val, ty }));
				delete factory;
			}
		}
	}
	else if (ocls != nullptr) {
		std::shared_ptr<Runtime::ConcreteClass> cls = std::static_pointer_cast<Runtime::ConcreteClass>(ocls);
		factory = new Runtime::VoidCreator;
		std::shared_ptr<Runtime::AbstractLiteral> ret = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject());
		delete factory;
		val = std::make_shared<Runtime::AbstractContainer>(ty, ret);
		val->getMembers() = cls->getScope()->getMembers();
	}
	std::string name = ctx->IDENTIFIER()->getText();
	bool isConst = !ctx->CONSTANT().empty();
	bool isStatic = !ctx->STATIC().empty();
	factory = new Runtime::VariableCreator;
	std::shared_ptr<Runtime::ConcreteVariable> var = std::static_pointer_cast<Runtime::ConcreteVariable>(factory->createObject({ val, ty, name, isConst, isStatic }));
	delete factory;
	if (!isStatic) {
		callStack.top()->addVariable(name, var);
	}
	else if (!callStack.top()->getGeneric()->contains(name)) {
		callStack.top()->getGeneric()->addMember(name, var);
	}
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx)
{
	ValuescriptParser::CodeblockContext* block = ctx->codeblock();
	Runtime::TypeInformation ty = std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression()));
	std::string name = ctx->IDENTIFIER()->getText();
	if (currentGeneric->contains(name)) return defaultResult();
	std::unordered_set<std::string> templates = {};
	std::shared_ptr<Runtime::GenericScope> scope = std::make_shared<Runtime::GenericScope>(name, callStack.top()->getGeneric());
	currentGeneric = scope;
	std::vector<std::shared_ptr<Runtime::ConcreteVariable>> params = std::any_cast<std::vector<std::shared_ptr<Runtime::ConcreteVariable>>>(visit(ctx->functionparameters()));
	currentGeneric = currentGeneric->getParent();
	factory = new Runtime::FunctionCreator;
	if (importing == "") {
		callStack.top()->getGeneric()->addMember(name, factory->createObject({ block, ty, name, templates, params, scope }));
	}
	else if (importing == "Array") {
		Runtime::ConcreteArray::addRegistration(name, factory->createObject({ block, ty, name, templates, params, scope }));
	}
	delete factory;
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitFunctionparameters(ValuescriptParser::FunctionparametersContext* ctx)
{
	std::vector<ValuescriptParser::VariabledeclarationContext*> toVisit = ctx->variabledeclaration();
	std::vector<std::shared_ptr<Runtime::ConcreteVariable>> ret;
	for (ValuescriptParser::VariabledeclarationContext* curr : toVisit) {
		std::shared_ptr<Runtime::AbstractLiteral> val = nullptr;
		Runtime::TypeInformation ty = std::any_cast<Runtime::TypeInformation>(visit(curr->typenameexpression()));
		std::string name = curr->IDENTIFIER()->getText();
		bool isConst = !curr->CONSTANT().empty();
		bool isStatic = false;
		factory = new Runtime::VariableCreator;
		std::shared_ptr<Runtime::ConcreteVariable> var = std::static_pointer_cast<Runtime::ConcreteVariable>(factory->createObject({ val, ty, name, isConst, isStatic }));
		delete factory;
		if (!currentGeneric->contains(name)) {
			currentGeneric->addMember(name, var);
			ret.push_back(var);
		}
	}
	return ret;
}

std::any ValuescriptRuntimeRules::visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx)
{
	ValuescriptParser::CodeblockContext* block = ctx->codeblock();
	std::string name = ctx->IDENTIFIER()->getText();
	if (currentGeneric->contains(name)) return defaultResult();
	std::unordered_set<std::string> templates = {};
	std::shared_ptr<Runtime::GenericScope> scope = std::make_shared<Runtime::GenericScope>(name, callStack.top()->getGeneric());
	currentGeneric = scope;
	visit(block);
	currentGeneric->setRet(nullptr);
	currentGeneric = currentGeneric->getParent();
	factory = new Runtime::ClassCreator;
	callStack.top()->getGeneric()->addMember(name, factory->createObject({ block, name, templates, scope }));
	delete factory;
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTemplateexpression(ValuescriptParser::TemplateexpressionContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyvoid(ValuescriptParser::TyvoidContext* ctx)
{
	Runtime::TypeInformation ty = { "Void", {} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTyinteger(ValuescriptParser::TyintegerContext* ctx)
{
	Runtime::TypeInformation ty = { "Integer", {} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTydouble(ValuescriptParser::TydoubleContext* ctx)
{
	Runtime::TypeInformation ty = { "Double", {} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTystring(ValuescriptParser::TystringContext* ctx)
{
	Runtime::TypeInformation ty = { "String", {} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTyboolean(ValuescriptParser::TybooleanContext* ctx)
{
	Runtime::TypeInformation ty = { "Boolean", {} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTypair(ValuescriptParser::TypairContext* ctx)
{
	Runtime::TypeInformation ty = { "Pair", {
		std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression(0))),
		std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression(1)))
	} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTyarray(ValuescriptParser::TyarrayContext* ctx)
{
	Runtime::TypeInformation ty = { "Array", {
		std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression()))
	} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTyset(ValuescriptParser::TysetContext* ctx)
{
	Runtime::TypeInformation ty = { "Set", {
		std::any_cast<Runtime::TypeInformation>(visit(ctx->typenameexpression()))
	} };
	return ty;
}

std::any ValuescriptRuntimeRules::visitTymap(ValuescriptParser::TymapContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyuset(ValuescriptParser::TyusetContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyumap(ValuescriptParser::TyumapContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTystack(ValuescriptParser::TystackContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyqueue(ValuescriptParser::TyqueueContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTydeque(ValuescriptParser::TydequeContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyprior(ValuescriptParser::TypriorContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyident(ValuescriptParser::TyidentContext* ctx)
{
	Runtime::TypeInformation ty = { ctx->IDENTIFIER()->getText(), {}};
	return ty;
}

std::any ValuescriptRuntimeRules::visitTynested(ValuescriptParser::TynestedContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitIfstatement(ValuescriptParser::IfstatementContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::AbstractLiteral> cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	if (std::any_cast<bool>(cond->getValue())) {
		visit(ctx->codeblock()[0]);
	}
	else if (ctx->ifstatement() != nullptr) visit(ctx->ifstatement());
	else if (ctx->codeblock().size() > 1) visit(ctx->codeblock()[1]);
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitWhilestatement(ValuescriptParser::WhilestatementContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::AbstractLiteral> cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	while (std::any_cast<bool>(cond->getValue()) && !callStack.top()->getBroken() && !callStack.top()->getGeneric()->getRet()) {
		visit(ctx->codeblock());
		ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
		cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	}
	callStack.top()->setBroken(false);
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitDostatement(ValuescriptParser::DostatementContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> ocond;
	std::shared_ptr<Runtime::AbstractLiteral> cond;
	do {
		visit(ctx->codeblock());
		ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
		cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	} while (std::any_cast<bool>(cond->getValue()) && !callStack.top()->getBroken() && !callStack.top()->getGeneric()->getRet());
	callStack.top()->setBroken(false);
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitRangefor(ValuescriptParser::RangeforContext* ctx)
{
	std::shared_ptr<Runtime::BlockScope> parent = nullptr;
	if (callStack.top()->getGeneric() == currentGeneric) parent = callStack.top();
	callStack.push(std::make_shared<Runtime::BlockScope>("RANGE_FOR_LOOP", parent, currentGeneric));
	std::vector<ValuescriptParser::VariabledeclarationContext*> toVisit = ctx->variabledeclaration();
	std::vector<ValuescriptParser::ExpressionContext*> expr = ctx->expression();
	for (ValuescriptParser::VariabledeclarationContext* curr : toVisit) {
		visit(curr);
	}
	std::shared_ptr<Runtime::AbstractObject> ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(expr[0]));
	std::shared_ptr<Runtime::AbstractLiteral> cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	while (std::any_cast<bool>(cond->getValue()) && !callStack.top()->getBroken() && !callStack.top()->getGeneric()->getRet()) {
		visit(ctx->codeblock());
		for (size_t i = 1; i < expr.size(); i++) visit(expr[i]);
		ocond = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(expr[0]));
		cond = std::static_pointer_cast<Runtime::AbstractLiteral>(ocond);
	}
	callStack.pop();
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitItemfor(ValuescriptParser::ItemforContext* ctx)
{
	std::shared_ptr<Runtime::BlockScope> parent = nullptr;
	if (callStack.top()->getGeneric() == currentGeneric) parent = callStack.top();
	callStack.push(std::make_shared<Runtime::BlockScope>("ITEM_FOR_LOOP", parent, currentGeneric));
	visit(ctx->variabledeclaration());
	std::shared_ptr<Runtime::AbstractObject> ovar = callStack.top()->getFirstVar();
	std::shared_ptr<Runtime::AbstractObject> ocont = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::ConcreteVariable> var = std::static_pointer_cast<Runtime::ConcreteVariable>(ovar);
	std::shared_ptr<Runtime::AbstractLiteral> cont = std::static_pointer_cast<Runtime::AbstractLiteral>(ocont);
	for (std::shared_ptr<Runtime::AbstractLiteral> val : std::any_cast<std::vector<std::shared_ptr<Runtime::AbstractLiteral>>>(cont->getUnderlying())) {
		var->setValue(val);
		visit(ctx->codeblock());
		if (callStack.top()->getBroken() || callStack.top()->getGeneric()->getRet()) break;
	}
	callStack.pop();
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitCodeblock(ValuescriptParser::CodeblockContext* ctx)
{
	size_t objects = objectStack.size();
	std::shared_ptr<Runtime::BlockScope> parent = nullptr;
	if (callStack.top()->getGeneric() == currentGeneric) parent = callStack.top();
	callStack.push(std::make_shared<Runtime::BlockScope>("CODEBLOCK_SCOPE", parent, currentGeneric));
	std::vector<ValuescriptParser::StatementContext*> toVisit = ctx->statement();
	for (ValuescriptParser::StatementContext* curr : toVisit) {
		visit(curr);
		if (callStack.top()->getBroken()) {
			if (parent != nullptr) callStack.top()->getParent()->setBroken(true);
			break;
		}
		if (callStack.top()->getGeneric()->getRet()) break;
	}
	callStack.pop();
	while (objectStack.size() > objects) objectStack.pop();
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitNotexpr(ValuescriptParser::NotexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	return !(*rhs.get());
}

std::any ValuescriptRuntimeRules::visitCompexpr(ValuescriptParser::CompexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->comparisonoperator()->getText();
	if (op == "==") return (*lhs.get()) == rhs;
	if (op == "!=") return (*lhs.get()) != rhs;
	if (op == "<=") return (*lhs.get()) <= rhs;
	if (op == ">=") return (*lhs.get()) >= rhs;
	if (op == "<") return (*lhs.get()) < rhs;
	if (op == ">") return (*lhs.get()) > rhs;
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitAddexpr(ValuescriptParser::AddexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->additiveoperator()->getText();
	if (op == "+") return (*lhs.get()) + rhs;
	if (op == "-") return (*lhs.get()) - rhs;
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitMembexpr(ValuescriptParser::MembexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::string rhs = ctx->IDENTIFIER()->getText();
	std::unordered_map<std::string, std::shared_ptr<Runtime::AbstractObject>>::iterator ret = lhs->getMembers().find(rhs);
	if (ret != lhs->getMembers().end()) {
		objectStack.push(lhs);
		return (*ret).second;
	}
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitAssignexpr(ValuescriptParser::AssignexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->assignmentoperator()->getText();
	if (op == "=") return lhs->setValue(rhs->copy());
	if (op == "+=") return lhs->setValue((*lhs.get()) + rhs);
	if (op == "-=") return lhs->setValue((*lhs.get()) - rhs);
	if (op == "*=") return lhs->setValue((*lhs.get()) * rhs);
	if (op == "/=") return lhs->setValue((*lhs.get()) / rhs);
	if (op == "%=") return lhs->setValue((*lhs.get()) % rhs);
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitBoolexpr(ValuescriptParser::BoolexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->booleanoperator()->getText();
	if (op == "&&") return (*lhs.get()) && rhs;
	if (op == "||") return (*lhs.get()) || rhs;
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitAccessexpr(ValuescriptParser::AccessexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	return (*lhs.get())[rhs];
}

std::any ValuescriptRuntimeRules::visitBinexpr(ValuescriptParser::BinexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->binaryoperator()->getText();
	if (op == "&") return (*lhs.get()) & rhs;
	if (op == "|") return (*lhs.get()) | rhs;
	if (op == "^") return (*lhs.get()) ^ rhs;
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitMultexpr(ValuescriptParser::MultexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> lhs = std::static_pointer_cast<Runtime::AbstractLiteral>(olhs);
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->multiplicativeoperator()->getText();
	if (op == "*") return (*lhs.get()) * rhs;
	if (op == "/") return (*lhs.get()) / rhs;
	if (op == "%") return (*lhs.get()) % rhs;
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitIncexpr(ValuescriptParser::IncexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
	std::shared_ptr<Runtime::ConcreteVariable> lhs = std::static_pointer_cast<Runtime::ConcreteVariable>(olhs);
	factory = new Runtime::IntegerCreator;
	std::shared_ptr<Runtime::AbstractLiteral> one = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject({ (long)1 }));
	std::string op = ctx->incrementaloperator()->getText();
	if (op == "++") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) + one));
	if (op == "--") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) - one));
	return nullptr;
}

std::any ValuescriptRuntimeRules::visitTyparexpr(ValuescriptParser::TyparexprContext* ctx)
{
	return visitChildren(ctx);
}

std::any ValuescriptRuntimeRules::visitObjexpr(ValuescriptParser::ObjexprContext* ctx)
{
	std::vector<std::shared_ptr<Runtime::AbstractLiteral>> arr;
	std::vector<ValuescriptParser::ExpressionContext*> toVisit = ctx->expression();
	for (ValuescriptParser::ExpressionContext* curr : toVisit) {
		std::shared_ptr<Runtime::AbstractObject> oval = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(curr));
		arr.push_back(std::static_pointer_cast<Runtime::AbstractLiteral>(oval));
	}
	Runtime::TypeInformation ty = { "Object", {} };
	for (int i = 0; i < std::min(arr.size(), (size_t)2); i++) ty.children.push_back(arr[i]->getType());
	factory = new Runtime::ContainerCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ arr, ty });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitPrimexpr(ValuescriptParser::PrimexprContext* ctx)
{
	return visit(ctx->primaryexpression());
}

std::any ValuescriptRuntimeRules::visitParenexpr(ValuescriptParser::ParenexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> ofunc = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::ConcreteFunction> func = std::static_pointer_cast<Runtime::ConcreteFunction>(ofunc);
	std::vector<std::shared_ptr<Runtime::AbstractLiteral>> params(ctx->expression().size() - 1), former(params.size());
	for (int i = 0; i < params.size(); i++) {
		former[i] = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(func->getParam()[i]->getValue());
	}
	for (int i = 1; i < ctx->expression().size(); i++) {
		std::shared_ptr<Runtime::AbstractObject> oarg = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(i)));
		if (oarg->getType().name == "Variable") {
			oarg = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(oarg->getValue())->copy();
		}
		params[i - 1] = std::static_pointer_cast<Runtime::AbstractLiteral>(oarg);
	}
	for (int i = 0; i < params.size(); i++) {
		func->setParam(params[i], i);
	}
	std::shared_ptr<Runtime::GenericScope> store = currentGeneric;
	currentGeneric = func->getScope();
	ValuescriptParser::CodeblockContext* val = std::any_cast<ValuescriptParser::CodeblockContext*>(func->getValue());
	visit(val);
	std::shared_ptr<Runtime::AbstractObject> ret = currentGeneric->getRet();
	currentGeneric->setRet(nullptr);
	currentGeneric = callStack.top()->getGeneric();
	for (int j = 0; j < params.size(); j++) {
		if (former[j] == nullptr) continue;
		func->setParam(former[j], j);
	}
	return ret;
}

std::any ValuescriptRuntimeRules::visitIdent(ValuescriptParser::IdentContext* ctx)
{
	std::string ident = ctx->IDENTIFIER()->getText();
	return callStack.top()->findMember(ident);
}

std::any ValuescriptRuntimeRules::visitDecimal(ValuescriptParser::DecimalContext* ctx)
{
	factory = new Runtime::DoubleCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ std::stod(ctx->FLOATING_LITERAL()->getText()) });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitNumber(ValuescriptParser::NumberContext* ctx)
{
	factory = new Runtime::IntegerCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ std::stol(ctx->INTEGER_LITERAL()->getText()) });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitTrue(ValuescriptParser::TrueContext* ctx)
{
	factory = new Runtime::BooleanCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ true });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitFalse(ValuescriptParser::FalseContext* ctx)
{
	factory = new Runtime::BooleanCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ false });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitString(ValuescriptParser::StringContext* ctx)
{
	std::string str = ctx->STRING_LITERAL()->getText();
	str.erase(str.begin());
	str.erase(str.end() - 1);
	factory = new Runtime::StringCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ str });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitOrder(ValuescriptParser::OrderContext* ctx)
{
	return visit(ctx->expression());
}

std::any ValuescriptRuntimeRules::visitThis(ValuescriptParser::ThisContext* ctx)
{
	return objectStack.top();
}