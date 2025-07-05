
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

    virtual std::any visitStatement(ValuescriptParser::StatementContext *context) = 0;

    virtual std::any visitVariabledeclaration(ValuescriptParser::VariabledeclarationContext *context) = 0;

    virtual std::any visitFunctiondeclaration(ValuescriptParser::FunctiondeclarationContext *context) = 0;

    virtual std::any visitFunctionparameters(ValuescriptParser::FunctionparametersContext *context) = 0;

    virtual std::any visitClassdeclaration(ValuescriptParser::ClassdeclarationContext *context) = 0;

    virtual std::any visitTemplatedeclaration(ValuescriptParser::TemplatedeclarationContext *context) = 0;

    virtual std::any visitTypenameexpression(ValuescriptParser::TypenameexpressionContext *context) = 0;

    virtual std::any visitIfstatement(ValuescriptParser::IfstatementContext *context) = 0;

    virtual std::any visitWhilestatement(ValuescriptParser::WhilestatementContext *context) = 0;

    virtual std::any visitDostatement(ValuescriptParser::DostatementContext *context) = 0;

    virtual std::any visitForstatement(ValuescriptParser::ForstatementContext *context) = 0;

    virtual std::any visitCodeblock(ValuescriptParser::CodeblockContext *context) = 0;

    virtual std::any visitExpression(ValuescriptParser::ExpressionContext *context) = 0;

    virtual std::any visitAssignmentoperator(ValuescriptParser::AssignmentoperatorContext *context) = 0;

    virtual std::any visitBooleanoperator(ValuescriptParser::BooleanoperatorContext *context) = 0;

    virtual std::any visitComparisonoperator(ValuescriptParser::ComparisonoperatorContext *context) = 0;

    virtual std::any visitAdditiveoperator(ValuescriptParser::AdditiveoperatorContext *context) = 0;

    virtual std::any visitMultiplicativeoperator(ValuescriptParser::MultiplicativeoperatorContext *context) = 0;

    virtual std::any visitNotoperator(ValuescriptParser::NotoperatorContext *context) = 0;

    virtual std::any visitIncrementaloperator(ValuescriptParser::IncrementaloperatorContext *context) = 0;

    virtual std::any visitPrimaryexpression(ValuescriptParser::PrimaryexpressionContext *context) = 0;


};

}  // namespace valuescriptantlrgeneration
