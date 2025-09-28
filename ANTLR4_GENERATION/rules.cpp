#include "runtime.h"

#include "ValuescriptParserBaseVisitor.h"
#include "antlr4-runtime.h"
#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"

using namespace valuescriptantlrgeneration;
using namespace antlr4;

class  ValuescriptRuntimeRules : public ValuescriptParserBaseVisitor {
private:
	Runtime::BaseCreator* factory = nullptr;
	std::shared_ptr<Runtime::GenericScope> globalGeneric, currentGeneric;
	std::shared_ptr<Runtime::BlockScope> globalBlock;
	std::stack<std::shared_ptr<Runtime::BlockScope>> callStack;
public:
	ValuescriptRuntimeRules(std::shared_ptr<Runtime::GenericScope> global) :
		globalGeneric{ global },
		currentGeneric{ global }
	{ }
	~ValuescriptRuntimeRules() {}

	std::any visitFile(ValuescriptParser::FileContext* ctx) override {
		globalBlock = std::make_shared<Runtime::BlockScope>(nullptr, globalGeneric);
		callStack.push(globalBlock);
		std::vector<ValuescriptParser::StatementContext*> toVisit = ctx->statement();
		for (ValuescriptParser::StatementContext* curr : toVisit) {
			visit(curr);
			if (callStack.top()->getRet() != nullptr) {
				break;
			}
		}
		callStack.pop();
		globalBlock = nullptr;
		return defaultResult();
	}

	std::any visitStatementvardecl(ValuescriptParser::StatementvardeclContext* ctx) override {
		visit(ctx->variabledeclaration());
		return defaultResult();
	}

	std::any visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext* ctx) override {
		return defaultResult();
	}

	std::any visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext* ctx) override {
		return defaultResult();
	}

	std::any visitStatementif(ValuescriptParser::StatementifContext* ctx) override {
		visit(ctx->ifstatement());
		return defaultResult();
	}

	std::any visitStatementwhile(ValuescriptParser::StatementwhileContext* ctx) override {
		visit(ctx->whilestatement());
		return defaultResult();
	}

	std::any visitStatementdo(ValuescriptParser::StatementdoContext* ctx) override {
		visit(ctx->dostatement());
		return defaultResult();
	}

	std::any visitStatementfor(ValuescriptParser::StatementforContext* ctx) override {
		visit(ctx->forstatement());
		return defaultResult();
	}

	std::any visitStatementnative(ValuescriptParser::StatementnativeContext* ctx) override {
		int key = std::stoi(ctx->INTEGER_LITERAL()->getText());
		// visit expression, then have list of commands to perform :P
		return defaultResult();
	}

	std::any visitStatementexpr(ValuescriptParser::StatementexprContext* ctx) override {
		visit(ctx->expression());
		return defaultResult();
	}

	std::any visitStatementret(ValuescriptParser::StatementretContext* ctx) override {
		if (ctx->expression() == nullptr) {
			factory = new Runtime::VoidCreator;
			std::shared_ptr<Runtime::AbstractLiteral> ret = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject());
			delete factory;
			callStack.top()->setRet(ret);
		}
		else {
			std::shared_ptr<Runtime::AbstractLiteral> ret = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
			callStack.top()->setRet(ret);
		}
		return defaultResult();
	}

	std::any visitStatementbreak(ValuescriptParser::StatementbreakContext* ctx) override {
		callStack.top()->setBroken(true);
		return defaultResult();
	}

	std::any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> val = nullptr;
		if (ctx->expression() != nullptr) val = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		std::string name = ctx->IDENTIFIER()->getText();
		bool isConst = !ctx->CONSTANT().empty();
		bool isStatic = !ctx->STATIC().empty();
		factory = new Runtime::VariableCreator;
		std::shared_ptr<Runtime::ConcreteVariable> var = std::static_pointer_cast<Runtime::ConcreteVariable>(factory->createObject({val, name, isConst, isStatic}));
		delete factory;
		if (!isStatic) {
			callStack.top()->addVariable(name, var);
		}
		else if (!callStack.top()->getGeneric()->contains(name)) {
			callStack.top()->getGeneric()->addMember(name, var);
		}
		return defaultResult();
	}

	std::any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx) override {
		return defaultResult();
	}

	std::any visitFunctionparameters(ValuescriptParser::FunctionparametersContext* ctx) override {
		return defaultResult();
	}

	std::any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx) override {
		return defaultResult();
	}

	std::any visitTemplateexpression(ValuescriptParser::TemplateexpressionContext* ctx) override {
		return defaultResult();
	}

	std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override {
		return defaultResult();
	}

	std::any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override {
		return defaultResult();
	}

	std::any visitTystring(ValuescriptParser::TystringContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override {
		return defaultResult();
	}

	std::any visitTypair(ValuescriptParser::TypairContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyarray(ValuescriptParser::TyarrayContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyset(ValuescriptParser::TysetContext* ctx) override {
		return defaultResult();
	}

	std::any visitTymap(ValuescriptParser::TymapContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyuset(ValuescriptParser::TyusetContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyumap(ValuescriptParser::TyumapContext* ctx) override {
		return defaultResult();
	}

	std::any visitTystack(ValuescriptParser::TystackContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyqueue(ValuescriptParser::TyqueueContext* ctx) override {
		return defaultResult();
	}

	std::any visitTydeque(ValuescriptParser::TydequeContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyprior(ValuescriptParser::TypriorContext* ctx) override {
		return defaultResult();
	}

	std::any visitTyident(ValuescriptParser::TyidentContext* ctx) override {
		return defaultResult();
	}

	std::any visitTynested(ValuescriptParser::TynestedContext* ctx) override {
		return defaultResult();
	}

	std::any visitIfstatement(ValuescriptParser::IfstatementContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> cond = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		if (std::any_cast<bool>(cond->getValue())) {
			visit(ctx->codeblock()[0]);
		}
		else if (ctx->ifstatement() != nullptr) visit(ctx->ifstatement());
		else if (ctx->codeblock().size() > 1) visit(ctx->codeblock()[1]);
		return defaultResult();
	}

	std::any visitWhilestatement(ValuescriptParser::WhilestatementContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> cond = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		while (std::any_cast<bool>(cond->getValue()) && !currentScope.top()->getBroken() && !currentScope.top()->getRet()) {
			visit(ctx->codeblock());
			cond = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		}
		currentScope.top()->setBroken(false);
		return defaultResult();
	}

	std::any visitDostatement(ValuescriptParser::DostatementContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> cond;
		do {
			visit(ctx->codeblock());
			cond = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		} while (std::any_cast<bool>(cond->getValue()) && !currentScope.top()->getBroken() && !currentScope.top()->getRet());
		currentScope.top()->setBroken(false);
		return defaultResult();
	}

	virtual std::any visitRangefor(ValuescriptParser::RangeforContext* ctx) override {
		return visitChildren(ctx);
	}

	virtual std::any visitItemfor(ValuescriptParser::ItemforContext* ctx) override {
		return visitChildren(ctx);
	}

	std::any visitCodeblock(ValuescriptParser::CodeblockContext* ctx) override {
		globalScope = std::make_shared<Runtime::GenericScope>(globalNamespace);
		currentScope.push(globalScope);
		std::vector<ValuescriptParser::StatementContext*> toVisit = ctx->statement();
		for (ValuescriptParser::StatementContext* curr : toVisit) {
			visit(curr);
			if (currentScope.top()->getRet() || currentScope.top()->getBroken()) {
				break;
			}
		}
		currentScope.pop();
		globalScope = nullptr;
		return defaultResult();
	}

	std::any visitNotexpr(ValuescriptParser::NotexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression()));
		return !(*rhs.get());
	}

	std::any visitCompexpr(ValuescriptParser::CompexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> lhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->comparisonoperator()->getText();
		if (op == "==") return (*lhs.get()) == rhs;
		if (op == "!=") return (*lhs.get()) != rhs;
		if (op == "<=") return (*lhs.get()) <= rhs;
		if (op == ">=") return (*lhs.get()) >= rhs;
		if (op == "<") return (*lhs.get()) < rhs;
		if (op == ">") return (*lhs.get()) > rhs;
		return nullptr;
	}

	std::any visitAddexpr(ValuescriptParser::AddexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> lhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->additiveoperator()->getText();
		if (op == "+") return (*lhs.get()) + rhs;
		if (op == "-") return (*lhs.get()) - rhs;
		return nullptr;
	}

	virtual std::any visitMembexpr(ValuescriptParser::MembexprContext* ctx) override {
		return visitChildren(ctx);
	}

	std::any visitAssignexpr(ValuescriptParser::AssignexprContext* ctx) override {
		std::shared_ptr<Runtime::ConcreteVariable> lhs = std::any_cast<std::shared_ptr<Runtime::ConcreteVariable>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->assignmentoperator()->getText();
		if (op == "=") return lhs->setValue(rhs);
		if (op == "+=") return lhs->setValue((*lhs.get()) + rhs);
		if (op == "-=") return lhs->setValue((*lhs.get()) - rhs);
		if (op == "*=") return lhs->setValue((*lhs.get()) * rhs);
		if (op == "/=") return lhs->setValue((*lhs.get()) / rhs);
		if (op == "%=") return lhs->setValue((*lhs.get()) % rhs);
		return nullptr;
	}

	std::any visitBoolexpr(ValuescriptParser::BoolexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> lhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->booleanoperator()->getText();
		if (op == "&&") return (*lhs.get()) && rhs;
		if (op == "||") return (*lhs.get()) || rhs;
		return nullptr;
	}

	virtual std::any visitAccessexpr(ValuescriptParser::AccessexprContext* ctx) override {
		return visitChildren(ctx);
	}

	std::any visitBinexpr(ValuescriptParser::BinexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> lhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->binaryoperator()->getText();
		if (op == "&") return (*lhs.get()) & rhs;
		if (op == "|") return (*lhs.get()) | rhs;
		if (op == "^") return (*lhs.get()) ^ rhs;
		return nullptr;
	}

	std::any visitMultexpr(ValuescriptParser::MultexprContext* ctx) override {
		std::shared_ptr<Runtime::AbstractLiteral> lhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(0)));
		std::shared_ptr<Runtime::AbstractLiteral> rhs = std::any_cast<std::shared_ptr<Runtime::AbstractLiteral>>(visit(ctx->expression(1)));
		std::string op = ctx->multiplicativeoperator()->getText();
		if (op == "*") return (*lhs.get()) * rhs;
		if (op == "/") return (*lhs.get()) / rhs;
		if (op == "%") return (*lhs.get()) % rhs;
		return nullptr;
	}

	std::any visitIncexpr(ValuescriptParser::IncexprContext* ctx) override {
		std::shared_ptr<Runtime::ConcreteVariable> lhs = std::any_cast<std::shared_ptr<Runtime::ConcreteVariable>>(visit(ctx->expression()));
		factory = new Runtime::IntegerCreator;
		std::shared_ptr<Runtime::AbstractLiteral> one = std::static_pointer_cast<Runtime::AbstractLiteral>(factory->createObject({ 1 }));
		std::string op = ctx->incrementaloperator()->getText();
		if (op == "++") return lhs->setValue((*lhs.get()) + one);
		if (op == "--") return lhs->setValue((*lhs.get()) - one);
		return nullptr;
	}

	virtual std::any visitTyparexpr(ValuescriptParser::TyparexprContext* ctx) override {
		return visitChildren(ctx);
	}

	virtual std::any visitObjexpr(ValuescriptParser::ObjexprContext* ctx) override {
		return visitChildren(ctx);
	}

	std::any visitPrimexpr(ValuescriptParser::PrimexprContext* ctx) override {
		return visit(ctx->primaryexpression());
	}

	virtual std::any visitParenexpr(ValuescriptParser::ParenexprContext* ctx) override {
		return visitChildren(ctx);
	}

	std::any visitIdent(ValuescriptParser::IdentContext* ctx) override {
		std::string ident = ctx->IDENTIFIER()->getText();

	}

	std::any visitDecimal(ValuescriptParser::DecimalContext* ctx) override {
		factory = new Runtime::DoubleCreator;
		std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ std::stod(ctx->FLOATING_LITERAL()->getText()) });
		delete factory;
		return ret;
	}

	std::any visitNumber(ValuescriptParser::NumberContext* ctx) override {
		factory = new Runtime::IntegerCreator;
		std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ std::stoi(ctx->INTEGER_LITERAL()->getText()) });
		delete factory;
		return ret;
	}

	std::any visitTrue(ValuescriptParser::TrueContext* ctx) override {
		factory = new Runtime::BooleanCreator;
		std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ true });
		delete factory;
		return ret;
	}

	std::any visitFalse(ValuescriptParser::FalseContext* ctx) override {
		factory = new Runtime::BooleanCreator;
		std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ false });
		delete factory;
		return ret;
	}

	std::any visitString(ValuescriptParser::StringContext* ctx) override {
		factory = new Runtime::StringCreator;
		std::shared_ptr<Runtime::AbstractObject> ret = factory->createObject({ ctx->STRING_LITERAL()->getText() });
		delete factory;
		return ret;
	}

	std::any visitOrder(ValuescriptParser::OrderContext* ctx) override {
		return visit(ctx->expression());
	}

	virtual std::any visitThis(ValuescriptParser::ThisContext* ctx) override {
		return visitChildren(ctx);
	}

};