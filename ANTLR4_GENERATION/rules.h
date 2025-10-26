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

	/// ========== PRINTING FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> console_output_raw(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> console_output_normal(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> console_output_pretty(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	/// ========== DEBUGGING FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> valuescript_breakpoint(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	/// ========== LIBRARY FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> enter_base_file(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> get_base_object(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> exit_base_file(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	/// ========== PAIR FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> pair_first(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> pair_second(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	/// ========== ARRAY FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> array_append(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_insert(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_pop(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_remove(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_clear(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_empty(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> array_size(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	/// ========== ORDERED LIST FUNCTIONS ==========
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_insert(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_remove(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_clear(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_empty(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_size(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_count(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_contains(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_find(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_find_greater_or_equal(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	static std::shared_ptr<Runtime::AbstractObject> ordered_list_find_greater(ValuescriptRuntimeRules* obj, std::shared_ptr<Runtime::AbstractObject> expr);
	Runtime::BaseCreator* factory = nullptr;
	std::shared_ptr<Runtime::GenericScope> globalGeneric, currentGeneric;
	std::shared_ptr<Runtime::BlockScope> globalBlock = nullptr;
	std::stack<std::shared_ptr<Runtime::BlockScope>> callStack;
	std::stack<std::shared_ptr<Runtime::AbstractObject>> objectStack;
	std::unordered_map<std::string, std::unique_ptr<ExtraImport>> imports;
	std::string importing = "";
	std::shared_ptr<Runtime::AbstractObject> importObject = nullptr;
	inline static const std::unordered_map<int, std::unordered_map<int, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>>> nativeFunctions = {
		{1, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(console_output_raw)},
			{2, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(console_output_normal)},
			{3, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(console_output_pretty)}
		}},
		{2, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(valuescript_breakpoint)}
		}},
		{3, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(enter_base_file)},
			{2, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(get_base_object)},
			{3, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(exit_base_file)}
		}},
		{4, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(pair_first)},
			{2, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(pair_second)}
		}},
		{5, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_append)},
			{2, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_insert)},
			{3, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_pop)},
			{4, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_remove)},
			{5, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_clear)},
			{6, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_empty)},
			{7, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(array_size)}
		}},
		{6, {
			{1, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_insert)},
			{2, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_remove)},
			{3, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_clear)},
			{4, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_empty)},
			{5, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_size)},
			{6, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_count)},
			{7, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_contains)},
			{8, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_find)},
			{9, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_find_greater_or_equal)},
			{10, std::function<std::shared_ptr<Runtime::AbstractObject>(ValuescriptRuntimeRules*, std::shared_ptr<Runtime::AbstractObject>)>(ordered_list_find_greater)}
		}}
	};
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
	std::any visitThis(ValuescriptParser::ThisContext* ctx) override;
};