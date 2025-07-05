
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ValuescriptParser.h"


namespace valuescriptantlrgeneration {

/**
 * This interface defines an abstract listener for a parse tree produced by ValuescriptParser.
 */
class  ValuescriptParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(ValuescriptParser::FileContext *ctx) = 0;
  virtual void exitFile(ValuescriptParser::FileContext *ctx) = 0;

  virtual void enterExtra(ValuescriptParser::ExtraContext *ctx) = 0;
  virtual void exitExtra(ValuescriptParser::ExtraContext *ctx) = 0;

  virtual void enterStatement(ValuescriptParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ValuescriptParser::StatementContext *ctx) = 0;

  virtual void enterVariabledeclaration(ValuescriptParser::VariabledeclarationContext *ctx) = 0;
  virtual void exitVariabledeclaration(ValuescriptParser::VariabledeclarationContext *ctx) = 0;

  virtual void enterFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext *ctx) = 0;
  virtual void exitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext *ctx) = 0;

  virtual void enterFunctionparameters(ValuescriptParser::FunctionparametersContext *ctx) = 0;
  virtual void exitFunctionparameters(ValuescriptParser::FunctionparametersContext *ctx) = 0;

  virtual void enterClassdeclaration(ValuescriptParser::ClassdeclarationContext *ctx) = 0;
  virtual void exitClassdeclaration(ValuescriptParser::ClassdeclarationContext *ctx) = 0;

  virtual void enterTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *ctx) = 0;
  virtual void exitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *ctx) = 0;

  virtual void enterTypenameexpression(ValuescriptParser::TypenameexpressionContext *ctx) = 0;
  virtual void exitTypenameexpression(ValuescriptParser::TypenameexpressionContext *ctx) = 0;

  virtual void enterIfstatement(ValuescriptParser::IfstatementContext *ctx) = 0;
  virtual void exitIfstatement(ValuescriptParser::IfstatementContext *ctx) = 0;

  virtual void enterWhilestatement(ValuescriptParser::WhilestatementContext *ctx) = 0;
  virtual void exitWhilestatement(ValuescriptParser::WhilestatementContext *ctx) = 0;

  virtual void enterDostatement(ValuescriptParser::DostatementContext *ctx) = 0;
  virtual void exitDostatement(ValuescriptParser::DostatementContext *ctx) = 0;

  virtual void enterForstatement(ValuescriptParser::ForstatementContext *ctx) = 0;
  virtual void exitForstatement(ValuescriptParser::ForstatementContext *ctx) = 0;

  virtual void enterCodeblock(ValuescriptParser::CodeblockContext *ctx) = 0;
  virtual void exitCodeblock(ValuescriptParser::CodeblockContext *ctx) = 0;

  virtual void enterExpression(ValuescriptParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ValuescriptParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignmentoperator(ValuescriptParser::AssignmentoperatorContext *ctx) = 0;
  virtual void exitAssignmentoperator(ValuescriptParser::AssignmentoperatorContext *ctx) = 0;

  virtual void enterBooleanoperator(ValuescriptParser::BooleanoperatorContext *ctx) = 0;
  virtual void exitBooleanoperator(ValuescriptParser::BooleanoperatorContext *ctx) = 0;

  virtual void enterComparisonoperator(ValuescriptParser::ComparisonoperatorContext *ctx) = 0;
  virtual void exitComparisonoperator(ValuescriptParser::ComparisonoperatorContext *ctx) = 0;

  virtual void enterAdditiveoperator(ValuescriptParser::AdditiveoperatorContext *ctx) = 0;
  virtual void exitAdditiveoperator(ValuescriptParser::AdditiveoperatorContext *ctx) = 0;

  virtual void enterMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext *ctx) = 0;
  virtual void exitMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext *ctx) = 0;

  virtual void enterNotoperator(ValuescriptParser::NotoperatorContext *ctx) = 0;
  virtual void exitNotoperator(ValuescriptParser::NotoperatorContext *ctx) = 0;

  virtual void enterIncrementaloperator(ValuescriptParser::IncrementaloperatorContext *ctx) = 0;
  virtual void exitIncrementaloperator(ValuescriptParser::IncrementaloperatorContext *ctx) = 0;

  virtual void enterPrimaryexpression(ValuescriptParser::PrimaryexpressionContext *ctx) = 0;
  virtual void exitPrimaryexpression(ValuescriptParser::PrimaryexpressionContext *ctx) = 0;


};

}  // namespace valuescriptantlrgeneration
