#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#pragma execution_character_set("utf-8")

#include <string>
#include <unordered_map>
#include <any>
#include <typeindex>
#include <typeinfo>
#include <memory>
#include <iostream>
#include <algorithm>

#include "runtime.h"

#include "ValuescriptParserBaseVisitor.h"
#include "antlr4-runtime.h"
#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"

using namespace valuescriptantlrgeneration;
using namespace antlr4;

class  ValuescriptRuntimeRules : public ValuescriptParserBaseVisitor {
private:
	struct ExtraImport {
	private:
		ANTLRInputStream* input;
		ValuescriptLexer* lexer;
		CommonTokenStream* tokens;
		ValuescriptParser* parser;
	public:
		ValuescriptParser::FileContext* tree;
		ExtraImport(std::string file) {
			input = new ANTLRInputStream(file);
			lexer = new ValuescriptLexer(input);
			tokens = new CommonTokenStream(lexer);
			parser = new ValuescriptParser(tokens);
			tree = parser->file();
		}

		~ExtraImport() {
			delete input;
			delete lexer;
			delete tokens;
			delete parser;
		}
	};
	Runtime::BaseCreator* factory = nullptr;
	std::shared_ptr<Runtime::GenericScope> globalGeneric, currentGeneric;
	std::shared_ptr<Runtime::BlockScope> globalBlock = nullptr;
	std::stack<std::shared_ptr<Runtime::BlockScope>> callStack;
	std::stack<std::shared_ptr<Runtime::AbstractObject>> objectStack;
	std::unordered_map<std::string, std::unique_ptr<ExtraImport>> imports;
	std::string importing = "";
	std::shared_ptr<Runtime::AbstractObject> importObject = nullptr;
public:
	ValuescriptRuntimeRules(std::shared_ptr<Runtime::GenericScope> global) :
		globalGeneric{ global },
		currentGeneric{ global }
	{
	}
	~ValuescriptRuntimeRules() {}

	std::any visit(tree::ParseTree* tree) override;
	std::any visitFile(ValuescriptParser::FileContext* ctx) override;
	std::any visitExtra(ValuescriptParser::ExtraContext* ctx) override;
	std::any visitStatementvardecl(ValuescriptParser::StatementvardeclContext* ctx) override;
	std::any visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext* ctx) override;
	std::any visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext* ctx) override;
	std::any visitStatementif(ValuescriptParser::StatementifContext* ctx) override;
	std::any visitStatementwhile(ValuescriptParser::StatementwhileContext* ctx) override;
	std::any visitStatementdo(ValuescriptParser::StatementdoContext* ctx) override;
	std::any visitStatementfor(ValuescriptParser::StatementforContext* ctx) override;
	std::any visitStatementnative(ValuescriptParser::StatementnativeContext* ctx) override;
	std::any visitStatementexpr(ValuescriptParser::StatementexprContext* ctx) override;
	std::any visitStatementret(ValuescriptParser::StatementretContext* ctx) override;
	std::any visitStatementbreak(ValuescriptParser::StatementbreakContext* ctx) override;
	std::any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext* ctx) override;
	std::any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext* ctx) override;
	std::any visitFunctionparameters(ValuescriptParser::FunctionparametersContext* ctx) override;
	std::any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext* ctx) override;
	std::any visitTemplateexpression(ValuescriptParser::TemplateexpressionContext* ctx) override;
	std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext* ctx) override;
	std::any visitTyvoid(ValuescriptParser::TyvoidContext* ctx) override;
	std::any visitTyinteger(ValuescriptParser::TyintegerContext* ctx) override;
	std::any visitTydouble(ValuescriptParser::TydoubleContext* ctx) override;
	std::any visitTystring(ValuescriptParser::TystringContext* ctx) override;
	std::any visitTyboolean(ValuescriptParser::TybooleanContext* ctx) override;
	std::any visitTypair(ValuescriptParser::TypairContext* ctx) override;
	std::any visitTyarray(ValuescriptParser::TyarrayContext* ctx) override;
	std::any visitTyset(ValuescriptParser::TysetContext* ctx) override;
	std::any visitTymap(ValuescriptParser::TymapContext* ctx) override;
	std::any visitTyuset(ValuescriptParser::TyusetContext* ctx) override;
	std::any visitTyumap(ValuescriptParser::TyumapContext* ctx) override;
	std::any visitTystack(ValuescriptParser::TystackContext* ctx) override;
	std::any visitTyqueue(ValuescriptParser::TyqueueContext* ctx) override;
	std::any visitTydeque(ValuescriptParser::TydequeContext* ctx) override;
	std::any visitTyprior(ValuescriptParser::TypriorContext* ctx) override;
	std::any visitTyident(ValuescriptParser::TyidentContext* ctx) override;
	std::any visitTynested(ValuescriptParser::TynestedContext* ctx) override;
	std::any visitIfstatement(ValuescriptParser::IfstatementContext* ctx) override;
	std::any visitWhilestatement(ValuescriptParser::WhilestatementContext* ctx) override;
	std::any visitDostatement(ValuescriptParser::DostatementContext* ctx) override;
	std::any visitRangefor(ValuescriptParser::RangeforContext* ctx) override;
	std::any visitItemfor(ValuescriptParser::ItemforContext* ctx) override;
	std::any visitCodeblock(ValuescriptParser::CodeblockContext* ctx) override;
	std::any visitNotexpr(ValuescriptParser::NotexprContext* ctx) override;
	std::any visitCompexpr(ValuescriptParser::CompexprContext* ctx) override;
	std::any visitAddexpr(ValuescriptParser::AddexprContext* ctx) override;
	std::any visitMembexpr(ValuescriptParser::MembexprContext* ctx) override;
	std::any visitAssignexpr(ValuescriptParser::AssignexprContext* ctx) override;
	std::any visitBoolexpr(ValuescriptParser::BoolexprContext* ctx) override;
	std::any visitAccessexpr(ValuescriptParser::AccessexprContext* ctx) override;
	std::any visitBinexpr(ValuescriptParser::BinexprContext* ctx) override;
	std::any visitMultexpr(ValuescriptParser::MultexprContext* ctx) override;
	std::any visitIncexpr(ValuescriptParser::IncexprContext* ctx) override;
	virtual std::any visitTyparexpr(ValuescriptParser::TyparexprContext* ctx) override;
	std::any visitObjexpr(ValuescriptParser::ObjexprContext* ctx) override;
	std::any visitPrimexpr(ValuescriptParser::PrimexprContext* ctx) override;
	std::any visitParenexpr(ValuescriptParser::ParenexprContext* ctx) override;
	std::any visitIdent(ValuescriptParser::IdentContext* ctx) override;
	std::any visitDecimal(ValuescriptParser::DecimalContext* ctx) override;
	std::any visitNumber(ValuescriptParser::NumberContext* ctx) override;
	std::any visitTrue(ValuescriptParser::TrueContext* ctx) override;
	std::any visitFalse(ValuescriptParser::FalseContext* ctx) override;
	std::any visitString(ValuescriptParser::StringContext* ctx) override;
	std::any visitOrder(ValuescriptParser::OrderContext* ctx) override;
	virtual std::any visitThis(ValuescriptParser::ThisContext* ctx) override;
};