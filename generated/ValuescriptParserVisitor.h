
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ValuescriptParser.h"


namespace valuescriptantlrgeneration {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by ValuescriptParser.
 */
class  ValuescriptParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ValuescriptParser.
   */
    virtual std::any visitFile(ValuescriptParser::FileContext *context) = 0;

    virtual std::any visitExtra(ValuescriptParser::ExtraContext *context) = 0;

    virtual std::any visitStatementvardecl(ValuescriptParser::StatementvardeclContext *context) = 0;

    virtual std::any visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext *context) = 0;

    virtual std::any visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext *context) = 0;

    virtual std::any visitStatementif(ValuescriptParser::StatementifContext *context) = 0;

    virtual std::any visitStatementwhile(ValuescriptParser::StatementwhileContext *context) = 0;

    virtual std::any visitStatementdo(ValuescriptParser::StatementdoContext *context) = 0;

    virtual std::any visitStatementfor(ValuescriptParser::StatementforContext *context) = 0;

    virtual std::any visitStatementexpr(ValuescriptParser::StatementexprContext *context) = 0;

    virtual std::any visitStatementret(ValuescriptParser::StatementretContext *context) = 0;

    virtual std::any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext *context) = 0;

    virtual std::any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext *context) = 0;

    virtual std::any visitFunctionparameters(ValuescriptParser::FunctionparametersContext *context) = 0;

    virtual std::any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext *context) = 0;

    virtual std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *context) = 0;

    virtual std::any visitTyinteger(ValuescriptParser::TyintegerContext *context) = 0;

    virtual std::any visitTydouble(ValuescriptParser::TydoubleContext *context) = 0;

    virtual std::any visitTystring(ValuescriptParser::TystringContext *context) = 0;

    virtual std::any visitTyboolean(ValuescriptParser::TybooleanContext *context) = 0;

    virtual std::any visitTyident(ValuescriptParser::TyidentContext *context) = 0;

    virtual std::any visitTynested(ValuescriptParser::TynestedContext *context) = 0;

    virtual std::any visitIfstatement(ValuescriptParser::IfstatementContext *context) = 0;

    virtual std::any visitWhilestatement(ValuescriptParser::WhilestatementContext *context) = 0;

    virtual std::any visitDostatement(ValuescriptParser::DostatementContext *context) = 0;

    virtual std::any visitRangefor(ValuescriptParser::RangeforContext *context) = 0;

    virtual std::any visitItemfor(ValuescriptParser::ItemforContext *context) = 0;

    virtual std::any visitCodeblock(ValuescriptParser::CodeblockContext *context) = 0;

    virtual std::any visitNotexpr(ValuescriptParser::NotexprContext *context) = 0;

    virtual std::any visitCompexpr(ValuescriptParser::CompexprContext *context) = 0;

    virtual std::any visitAddexpr(ValuescriptParser::AddexprContext *context) = 0;

    virtual std::any visitMembexpr(ValuescriptParser::MembexprContext *context) = 0;

    virtual std::any visitAssignexpr(ValuescriptParser::AssignexprContext *context) = 0;

    virtual std::any visitBoolexpr(ValuescriptParser::BoolexprContext *context) = 0;

    virtual std::any visitAccessexpr(ValuescriptParser::AccessexprContext *context) = 0;

    virtual std::any visitBinexpr(ValuescriptParser::BinexprContext *context) = 0;

    virtual std::any visitMultexpr(ValuescriptParser::MultexprContext *context) = 0;

    virtual std::any visitIncexpr(ValuescriptParser::IncexprContext *context) = 0;

    virtual std::any visitObjexpr(ValuescriptParser::ObjexprContext *context) = 0;

    virtual std::any visitPrimexpr(ValuescriptParser::PrimexprContext *context) = 0;

    virtual std::any visitParenexpr(ValuescriptParser::ParenexprContext *context) = 0;

    virtual std::any visitAsseql(ValuescriptParser::AsseqlContext *context) = 0;

    virtual std::any visitAssadd(ValuescriptParser::AssaddContext *context) = 0;

    virtual std::any visitAsssub(ValuescriptParser::AsssubContext *context) = 0;

    virtual std::any visitAssmul(ValuescriptParser::AssmulContext *context) = 0;

    virtual std::any visitAssdiv(ValuescriptParser::AssdivContext *context) = 0;

    virtual std::any visitAssmod(ValuescriptParser::AssmodContext *context) = 0;

    virtual std::any visitBitand(ValuescriptParser::BitandContext *context) = 0;

    virtual std::any visitBitor(ValuescriptParser::BitorContext *context) = 0;

    virtual std::any visitBitxor(ValuescriptParser::BitxorContext *context) = 0;

    virtual std::any visitBooland(ValuescriptParser::BoolandContext *context) = 0;

    virtual std::any visitBoolor(ValuescriptParser::BoolorContext *context) = 0;

    virtual std::any visitCompeql(ValuescriptParser::CompeqlContext *context) = 0;

    virtual std::any visitCompnon(ValuescriptParser::CompnonContext *context) = 0;

    virtual std::any visitCompgoe(ValuescriptParser::CompgoeContext *context) = 0;

    virtual std::any visitComploe(ValuescriptParser::ComploeContext *context) = 0;

    virtual std::any visitComplss(ValuescriptParser::ComplssContext *context) = 0;

    virtual std::any visitCompgre(ValuescriptParser::CompgreContext *context) = 0;

    virtual std::any visitPlus(ValuescriptParser::PlusContext *context) = 0;

    virtual std::any visitMinus(ValuescriptParser::MinusContext *context) = 0;

    virtual std::any visitTimes(ValuescriptParser::TimesContext *context) = 0;

    virtual std::any visitDivide(ValuescriptParser::DivideContext *context) = 0;

    virtual std::any visitModulo(ValuescriptParser::ModuloContext *context) = 0;

    virtual std::any visitNotoperator(ValuescriptParser::NotoperatorContext *context) = 0;

    virtual std::any visitPlusplus(ValuescriptParser::PlusplusContext *context) = 0;

    virtual std::any visitMinusminus(ValuescriptParser::MinusminusContext *context) = 0;

    virtual std::any visitIdent(ValuescriptParser::IdentContext *context) = 0;

    virtual std::any visitDecimal(ValuescriptParser::DecimalContext *context) = 0;

    virtual std::any visitNumber(ValuescriptParser::NumberContext *context) = 0;

    virtual std::any visitTrue(ValuescriptParser::TrueContext *context) = 0;

    virtual std::any visitFalse(ValuescriptParser::FalseContext *context) = 0;

    virtual std::any visitString(ValuescriptParser::StringContext *context) = 0;

    virtual std::any visitOrder(ValuescriptParser::OrderContext *context) = 0;


};

}  // namespace valuescriptantlrgeneration
