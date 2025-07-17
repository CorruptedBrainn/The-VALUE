
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ValuescriptParserVisitor.h"


namespace valuescriptantlrgeneration {

/**
 * This class provides an empty implementation of ValuescriptParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ValuescriptParserBaseVisitor : public ValuescriptParserVisitor {
public:

  virtual std::any visitFile(ValuescriptParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtra(ValuescriptParser::ExtraContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementvardecl(ValuescriptParser::StatementvardeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementfuncdecl(ValuescriptParser::StatementfuncdeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementclassdecl(ValuescriptParser::StatementclassdeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementif(ValuescriptParser::StatementifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementwhile(ValuescriptParser::StatementwhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementdo(ValuescriptParser::StatementdoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementfor(ValuescriptParser::StatementforContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementprint(ValuescriptParser::StatementprintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementexpr(ValuescriptParser::StatementexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementret(ValuescriptParser::StatementretContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionparameters(ValuescriptParser::FunctionparametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemplateexpression(ValuescriptParser::TemplateexpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyinteger(ValuescriptParser::TyintegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTydouble(ValuescriptParser::TydoubleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTystring(ValuescriptParser::TystringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyboolean(ValuescriptParser::TybooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypair(ValuescriptParser::TypairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyarray(ValuescriptParser::TyarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyset(ValuescriptParser::TysetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTymap(ValuescriptParser::TymapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyuset(ValuescriptParser::TyusetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyumap(ValuescriptParser::TyumapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTystack(ValuescriptParser::TystackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyqueue(ValuescriptParser::TyqueueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTydeque(ValuescriptParser::TydequeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyprior(ValuescriptParser::TypriorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyident(ValuescriptParser::TyidentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTynested(ValuescriptParser::TynestedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfstatement(ValuescriptParser::IfstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhilestatement(ValuescriptParser::WhilestatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDostatement(ValuescriptParser::DostatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangefor(ValuescriptParser::RangeforContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemfor(ValuescriptParser::ItemforContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodeblock(ValuescriptParser::CodeblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotexpr(ValuescriptParser::NotexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompexpr(ValuescriptParser::CompexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddexpr(ValuescriptParser::AddexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMembexpr(ValuescriptParser::MembexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignexpr(ValuescriptParser::AssignexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolexpr(ValuescriptParser::BoolexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessexpr(ValuescriptParser::AccessexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinexpr(ValuescriptParser::BinexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultexpr(ValuescriptParser::MultexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncexpr(ValuescriptParser::IncexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyparexpr(ValuescriptParser::TyparexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjexpr(ValuescriptParser::ObjexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimexpr(ValuescriptParser::PrimexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenexpr(ValuescriptParser::ParenexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsseql(ValuescriptParser::AsseqlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssadd(ValuescriptParser::AssaddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsssub(ValuescriptParser::AsssubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssmul(ValuescriptParser::AssmulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssdiv(ValuescriptParser::AssdivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssmod(ValuescriptParser::AssmodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitand(ValuescriptParser::BitandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitor(ValuescriptParser::BitorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitxor(ValuescriptParser::BitxorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooland(ValuescriptParser::BoolandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolor(ValuescriptParser::BoolorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompeql(ValuescriptParser::CompeqlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompnon(ValuescriptParser::CompnonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompgoe(ValuescriptParser::CompgoeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComploe(ValuescriptParser::ComploeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComplss(ValuescriptParser::ComplssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompgre(ValuescriptParser::CompgreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlus(ValuescriptParser::PlusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMinus(ValuescriptParser::MinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimes(ValuescriptParser::TimesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDivide(ValuescriptParser::DivideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModulo(ValuescriptParser::ModuloContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotoperator(ValuescriptParser::NotoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlusplus(ValuescriptParser::PlusplusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMinusminus(ValuescriptParser::MinusminusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdent(ValuescriptParser::IdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimal(ValuescriptParser::DecimalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(ValuescriptParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrue(ValuescriptParser::TrueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalse(ValuescriptParser::FalseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(ValuescriptParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrder(ValuescriptParser::OrderContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace valuescriptantlrgeneration
