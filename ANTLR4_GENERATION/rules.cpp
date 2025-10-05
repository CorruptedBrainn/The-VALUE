#include "rules.h"

std::any ValuescriptRuntimeRules::visitFile(ValuescriptParser::FileContext* ctx)
{
	globalBlock = std::make_shared<Runtime::BlockScope>(nullptr, globalGeneric);
	callStack.push(globalBlock);
	std::vector<ValuescriptParser::StatementContext*> toVisit = ctx->statement();
	for (ValuescriptParser::StatementContext* curr : toVisit) {
		visit(curr);
		if (callStack.top()->getGeneric()->getRet() != nullptr) {
			break;
		}
	}
	callStack.pop();
	globalBlock = nullptr;
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementvardecl(ValuescriptParser::StatementvardeclContext* ctx)
{
	visit(ctx->variabledeclaration());
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext* ctx)
{
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
	std::any expr = visit(ctx->expression());
	switch (key) {
	case 1: {
		std::cout << "Runtime Output: " << *std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(expr).get() << "\n\n";
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
		std::shared_ptr<Runtime::AbstractLiteral> ret = std::static_pointer_cast<Runtime::AbstractLiteral>(oret);
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
	if (ctx->expression() != nullptr) {
		std::shared_ptr<Runtime::AbstractObject> oval = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression()));
		val = std::static_pointer_cast<Runtime::AbstractLiteral>(oval);
		std::any atype = visit(ctx->typenameexpression());
		if (atype.has_value()) {
			std::string type = std::any_cast<std::string>(atype);
			if (type == "array") factory = new Runtime::ArrayCreator;
			val = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject({ val }));
			delete factory;
		}
	}
	std::string name = ctx->IDENTIFIER()->getText();
	bool isConst = !ctx->CONSTANT().empty();
	bool isStatic = !ctx->STATIC().empty();
	factory = new Runtime::VariableCreator;
	std::shared_ptr<Runtime::ConcreteVariable> var = std::static_pointer_cast<Runtime::ConcreteVariable>(factory->createObject({ val, name, isConst, isStatic }));
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
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitFunctionparameters(ValuescriptParser::FunctionparametersContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx)
{
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

std::any ValuescriptRuntimeRules::visitTyinteger(ValuescriptParser::TyintegerContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTydouble(ValuescriptParser::TydoubleContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTystring(ValuescriptParser::TystringContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyboolean(ValuescriptParser::TybooleanContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTypair(ValuescriptParser::TypairContext* ctx)
{
	return defaultResult();
}

std::any ValuescriptRuntimeRules::visitTyarray(ValuescriptParser::TyarrayContext* ctx)
{
	return (std::string)"array";
}

std::any ValuescriptRuntimeRules::visitTyset(ValuescriptParser::TysetContext* ctx)
{
	return defaultResult();
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
	return defaultResult();
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
	// ee
}

std::any ValuescriptRuntimeRules::visitItemfor(ValuescriptParser::ItemforContext* ctx)
{
	return visitChildren(ctx);
}

std::any ValuescriptRuntimeRules::visitCodeblock(ValuescriptParser::CodeblockContext* ctx)
{
	std::shared_ptr<Runtime::BlockScope> parent = nullptr;
	if (callStack.top()->getGeneric() == currentGeneric) parent = callStack.top();
	callStack.push(std::make_shared<Runtime::BlockScope>(parent, currentGeneric));
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
	return visitChildren(ctx);
}

std::any ValuescriptRuntimeRules::visitAssignexpr(ValuescriptParser::AssignexprContext* ctx)
{
	std::shared_ptr<Runtime::AbstractObject> olhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(0)));
	std::shared_ptr<Runtime::ConcreteVariable> lhs = std::static_pointer_cast<Runtime::ConcreteVariable>(olhs);
	std::shared_ptr<Runtime::AbstractObject> orhs = std::any_cast<std::shared_ptr<Runtime::AbstractObject>>(visit(ctx->expression(1)));
	std::shared_ptr<Runtime::AbstractLiteral> rhs = std::static_pointer_cast<Runtime::AbstractLiteral>(orhs);
	std::string op = ctx->assignmentoperator()->getText();
	if (op == "=") return lhs->setValue(rhs);
	if (op == "+=") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) + rhs));
	if (op == "-=") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) - rhs));
	if (op == "*=") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) * rhs));
	if (op == "/=") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) / rhs));
	if (op == "%=") return lhs->setValue(std::static_pointer_cast<Runtime::AbstractLiteral>((*lhs.get()) % rhs));
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
	factory = new Runtime::ContainerCreator;
	std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ arr });
	delete factory;
	return ret;
}

std::any ValuescriptRuntimeRules::visitPrimexpr(ValuescriptParser::PrimexprContext* ctx)
{
	return visit(ctx->primaryexpression());
}

std::any ValuescriptRuntimeRules::visitParenexpr(ValuescriptParser::ParenexprContext* ctx)
{
	return visitChildren(ctx);
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
	return visitChildren(ctx);
}