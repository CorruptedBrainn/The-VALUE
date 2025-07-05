
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

  virtual std::any visitStatement(ValuescriptParser::StatementContext *ctx) override {
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

  virtual std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypenameexpression(ValuescriptParser::TypenameexpressionContext *ctx) override {
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

  virtual std::any visitForstatement(ValuescriptParser::ForstatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodeblock(ValuescriptParser::CodeblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(ValuescriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentoperator(ValuescriptParser::AssignmentoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanoperator(ValuescriptParser::BooleanoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonoperator(ValuescriptParser::ComparisonoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveoperator(ValuescriptParser::AdditiveoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotoperator(ValuescriptParser::NotoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncrementaloperator(ValuescriptParser::IncrementaloperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryexpression(ValuescriptParser::PrimaryexpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace valuescriptantlrgeneration
