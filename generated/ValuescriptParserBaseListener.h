
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ValuescriptParserListener.h"


namespace valuescriptantlrgeneration {

/**
 * This class provides an empty implementation of ValuescriptParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ValuescriptParserBaseListener : public ValuescriptParserListener {
public:

  virtual void enterFile(ValuescriptParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(ValuescriptParser::FileContext * /*ctx*/) override { }

  virtual void enterExtra(ValuescriptParser::ExtraContext * /*ctx*/) override { }
  virtual void exitExtra(ValuescriptParser::ExtraContext * /*ctx*/) override { }

  virtual void enterStatement(ValuescriptParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ValuescriptParser::StatementContext * /*ctx*/) override { }

  virtual void enterVariabledeclaration(ValuescriptParser::VariabledeclarationContext * /*ctx*/) override { }
  virtual void exitVariabledeclaration(ValuescriptParser::VariabledeclarationContext * /*ctx*/) override { }

  virtual void enterFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext * /*ctx*/) override { }
  virtual void exitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionparameters(ValuescriptParser::FunctionparametersContext * /*ctx*/) override { }
  virtual void exitFunctionparameters(ValuescriptParser::FunctionparametersContext * /*ctx*/) override { }

  virtual void enterClassdeclaration(ValuescriptParser::ClassdeclarationContext * /*ctx*/) override { }
  virtual void exitClassdeclaration(ValuescriptParser::ClassdeclarationContext * /*ctx*/) override { }

  virtual void enterTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext * /*ctx*/) override { }
  virtual void exitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext * /*ctx*/) override { }

  virtual void enterTypenameexpression(ValuescriptParser::TypenameexpressionContext * /*ctx*/) override { }
  virtual void exitTypenameexpression(ValuescriptParser::TypenameexpressionContext * /*ctx*/) override { }

  virtual void enterIfstatement(ValuescriptParser::IfstatementContext * /*ctx*/) override { }
  virtual void exitIfstatement(ValuescriptParser::IfstatementContext * /*ctx*/) override { }

  virtual void enterWhilestatement(ValuescriptParser::WhilestatementContext * /*ctx*/) override { }
  virtual void exitWhilestatement(ValuescriptParser::WhilestatementContext * /*ctx*/) override { }

  virtual void enterDostatement(ValuescriptParser::DostatementContext * /*ctx*/) override { }
  virtual void exitDostatement(ValuescriptParser::DostatementContext * /*ctx*/) override { }

  virtual void enterForstatement(ValuescriptParser::ForstatementContext * /*ctx*/) override { }
  virtual void exitForstatement(ValuescriptParser::ForstatementContext * /*ctx*/) override { }

  virtual void enterCodeblock(ValuescriptParser::CodeblockContext * /*ctx*/) override { }
  virtual void exitCodeblock(ValuescriptParser::CodeblockContext * /*ctx*/) override { }

  virtual void enterExpression(ValuescriptParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ValuescriptParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentoperator(ValuescriptParser::AssignmentoperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentoperator(ValuescriptParser::AssignmentoperatorContext * /*ctx*/) override { }

  virtual void enterBooleanoperator(ValuescriptParser::BooleanoperatorContext * /*ctx*/) override { }
  virtual void exitBooleanoperator(ValuescriptParser::BooleanoperatorContext * /*ctx*/) override { }

  virtual void enterComparisonoperator(ValuescriptParser::ComparisonoperatorContext * /*ctx*/) override { }
  virtual void exitComparisonoperator(ValuescriptParser::ComparisonoperatorContext * /*ctx*/) override { }

  virtual void enterAdditiveoperator(ValuescriptParser::AdditiveoperatorContext * /*ctx*/) override { }
  virtual void exitAdditiveoperator(ValuescriptParser::AdditiveoperatorContext * /*ctx*/) override { }

  virtual void enterMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext * /*ctx*/) override { }
  virtual void exitMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext * /*ctx*/) override { }

  virtual void enterNotoperator(ValuescriptParser::NotoperatorContext * /*ctx*/) override { }
  virtual void exitNotoperator(ValuescriptParser::NotoperatorContext * /*ctx*/) override { }

  virtual void enterIncrementaloperator(ValuescriptParser::IncrementaloperatorContext * /*ctx*/) override { }
  virtual void exitIncrementaloperator(ValuescriptParser::IncrementaloperatorContext * /*ctx*/) override { }

  virtual void enterPrimaryexpression(ValuescriptParser::PrimaryexpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryexpression(ValuescriptParser::PrimaryexpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace valuescriptantlrgeneration
