
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


namespace valuescriptantlrgeneration {


class  ValuescriptParser : public antlr4::Parser {
public:
  enum {
    STATIC = 1, CONSTANT = 2, VARIABLE = 3, FUNCTION = 4, CLASS = 5, RETURN = 6, 
    TYPENAMES = 7, IMPORT = 8, AS = 9, INTEGER = 10, DOUBLE = 11, BOOLEAN = 12, 
    STRING = 13, VOID = 14, TRUE = 15, FALSE = 16, IF = 17, ELSE = 18, DO = 19, 
    WHILE = 20, FOR = 21, OPEN_PARENTHESES = 22, CLOSED_PARENTHESES = 23, 
    OPEN_CURLY_BRACE = 24, CLOSED_CURLY_BRACE = 25, OPEN_ANGLE_BRACKET = 26, 
    CLOSED_ANGLE_BRACKET = 27, OPEN_SQUARE = 28, CLOSED_SQUARE = 29, PERIOD = 30, 
    COMMA = 31, AT_SYMBOL = 32, COLON = 33, SEMICOLON = 34, EXCLAMATION_POINT = 35, 
    ARROW_OPERATOR = 36, BITWISE_AND = 37, BOOLEAN_AND = 38, BITWISE_OR = 39, 
    BOOLEAN_OR = 40, BITWISE_XOR = 41, ADDITION = 42, SUBTRACTION = 43, 
    MULTIPLICATION = 44, DIVISION = 45, MODULUS = 46, INCREMENT = 47, DECREMENT = 48, 
    ASSIGNMENT_GENERIC = 49, ASSIGNMENT_ADD = 50, ASSIGNMENT_SUB = 51, ASSIGNMENT_MULTI = 52, 
    ASSIGNMENT_DIV = 53, ASSIGNMENT_MOD = 54, EQUALITY = 55, NON_EQUALITY = 56, 
    GREATER_OR_EQUAL = 57, LESS_OR_EQUAL = 58, SINGLE_LINE_COMMENT = 59, 
    MULTI_LINE_COMMENT = 60, WHITESPACE = 61, INTEGER_LITERAL = 62, STRING_LITERAL = 63, 
    IDENTIFIER = 64
  };

  enum {
    RuleFile = 0, RuleExtra = 1, RuleStatement = 2, RuleVariabledeclaration = 3, 
    RuleFunctiondeclaration = 4, RuleFunctionparameters = 5, RuleClassdeclaration = 6, 
    RuleTemplatedeclaration = 7, RuleTypenameexpression = 8, RuleIfstatement = 9, 
    RuleWhilestatement = 10, RuleDostatement = 11, RuleForstatement = 12, 
    RuleCodeblock = 13, RuleExpression = 14, RuleAssignmentoperator = 15, 
    RuleBooleanoperator = 16, RuleComparisonoperator = 17, RuleAdditiveoperator = 18, 
    RuleMultiplicativeoperator = 19, RuleNotoperator = 20, RuleIncrementaloperator = 21, 
    RulePrimaryexpression = 22
  };

  explicit ValuescriptParser(antlr4::TokenStream *input);

  ValuescriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ValuescriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class ExtraContext;
  class StatementContext;
  class VariabledeclarationContext;
  class FunctiondeclarationContext;
  class FunctionparametersContext;
  class ClassdeclarationContext;
  class TemplatedeclarationContext;
  class TypenameexpressionContext;
  class IfstatementContext;
  class WhilestatementContext;
  class DostatementContext;
  class ForstatementContext;
  class CodeblockContext;
  class ExpressionContext;
  class AssignmentoperatorContext;
  class BooleanoperatorContext;
  class ComparisonoperatorContext;
  class AdditiveoperatorContext;
  class MultiplicativeoperatorContext;
  class NotoperatorContext;
  class IncrementaloperatorContext;
  class PrimaryexpressionContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ExtraContext *> extra();
    ExtraContext* extra(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  ExtraContext : public antlr4::ParserRuleContext {
  public:
    ExtraContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtraContext* extra();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariabledeclarationContext *variabledeclaration();
    antlr4::tree::TerminalNode *SEMICOLON();
    FunctiondeclarationContext *functiondeclaration();
    ClassdeclarationContext *classdeclaration();
    IfstatementContext *ifstatement();
    WhilestatementContext *whilestatement();
    DostatementContext *dostatement();
    ForstatementContext *forstatement();
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  VariabledeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariabledeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ARROW_OPERATOR();
    TypenameexpressionContext *typenameexpression();
    std::vector<antlr4::tree::TerminalNode *> STATIC();
    antlr4::tree::TerminalNode* STATIC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VARIABLE();
    antlr4::tree::TerminalNode* VARIABLE(size_t i);
    antlr4::tree::TerminalNode *ASSIGNMENT_GENERIC();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> CONSTANT();
    antlr4::tree::TerminalNode* CONSTANT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariabledeclarationContext* variabledeclaration();

  class  FunctiondeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctiondeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    FunctionparametersContext *functionparameters();
    antlr4::tree::TerminalNode *ARROW_OPERATOR();
    TypenameexpressionContext *typenameexpression();
    CodeblockContext *codeblock();
    TemplatedeclarationContext *templatedeclaration();
    antlr4::tree::TerminalNode *FUNCTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctiondeclarationContext* functiondeclaration();

  class  FunctionparametersContext : public antlr4::ParserRuleContext {
  public:
    FunctionparametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    std::vector<VariabledeclarationContext *> variabledeclaration();
    VariabledeclarationContext* variabledeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionparametersContext* functionparameters();

  class  ClassdeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassdeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    CodeblockContext *codeblock();
    TemplatedeclarationContext *templatedeclaration();
    antlr4::tree::TerminalNode *CLASS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassdeclarationContext* classdeclaration();

  class  TemplatedeclarationContext : public antlr4::ParserRuleContext {
  public:
    TemplatedeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT_SYMBOL();
    antlr4::tree::TerminalNode *TYPENAMES();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplatedeclarationContext* templatedeclaration();

  class  TypenameexpressionContext : public antlr4::ParserRuleContext {
  public:
    TypenameexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_ANGLE_BRACKET();
    std::vector<TypenameexpressionContext *> typenameexpression();
    TypenameexpressionContext* typenameexpression(size_t i);
    antlr4::tree::TerminalNode *CLOSED_ANGLE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypenameexpressionContext* typenameexpression();

  class  IfstatementContext : public antlr4::ParserRuleContext {
  public:
    IfstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    std::vector<CodeblockContext *> codeblock();
    CodeblockContext* codeblock(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    IfstatementContext *ifstatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfstatementContext* ifstatement();

  class  WhilestatementContext : public antlr4::ParserRuleContext {
  public:
    WhilestatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    CodeblockContext *codeblock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhilestatementContext* whilestatement();

  class  DostatementContext : public antlr4::ParserRuleContext {
  public:
    DostatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    CodeblockContext *codeblock();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DostatementContext* dostatement();

  class  ForstatementContext : public antlr4::ParserRuleContext {
  public:
    ForstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    std::vector<VariabledeclarationContext *> variabledeclaration();
    VariabledeclarationContext* variabledeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    CodeblockContext *codeblock();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForstatementContext* forstatement();

  class  CodeblockContext : public antlr4::ParserRuleContext {
  public:
    CodeblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_CURLY_BRACE();
    antlr4::tree::TerminalNode *CLOSED_CURLY_BRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeblockContext* codeblock();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryexpressionContext *primaryexpression();
    NotoperatorContext *notoperator();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPEN_CURLY_BRACE();
    antlr4::tree::TerminalNode *CLOSED_CURLY_BRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *PERIOD();
    MultiplicativeoperatorContext *multiplicativeoperator();
    AdditiveoperatorContext *additiveoperator();
    ComparisonoperatorContext *comparisonoperator();
    BooleanoperatorContext *booleanoperator();
    AssignmentoperatorContext *assignmentoperator();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    antlr4::tree::TerminalNode *OPEN_SQUARE();
    antlr4::tree::TerminalNode *CLOSED_SQUARE();
    IncrementaloperatorContext *incrementaloperator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  AssignmentoperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGNMENT_GENERIC();
    antlr4::tree::TerminalNode *ASSIGNMENT_ADD();
    antlr4::tree::TerminalNode *ASSIGNMENT_SUB();
    antlr4::tree::TerminalNode *ASSIGNMENT_MULTI();
    antlr4::tree::TerminalNode *ASSIGNMENT_DIV();
    antlr4::tree::TerminalNode *ASSIGNMENT_MOD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentoperatorContext* assignmentoperator();

  class  BooleanoperatorContext : public antlr4::ParserRuleContext {
  public:
    BooleanoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN_AND();
    antlr4::tree::TerminalNode *BOOLEAN_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanoperatorContext* booleanoperator();

  class  ComparisonoperatorContext : public antlr4::ParserRuleContext {
  public:
    ComparisonoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUALITY();
    antlr4::tree::TerminalNode *NON_EQUALITY();
    antlr4::tree::TerminalNode *GREATER_OR_EQUAL();
    antlr4::tree::TerminalNode *LESS_OR_EQUAL();
    antlr4::tree::TerminalNode *OPEN_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *CLOSED_ANGLE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonoperatorContext* comparisonoperator();

  class  AdditiveoperatorContext : public antlr4::ParserRuleContext {
  public:
    AdditiveoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDITION();
    antlr4::tree::TerminalNode *SUBTRACTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveoperatorContext* additiveoperator();

  class  MultiplicativeoperatorContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULTIPLICATION();
    antlr4::tree::TerminalNode *DIVISION();
    antlr4::tree::TerminalNode *MODULUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeoperatorContext* multiplicativeoperator();

  class  NotoperatorContext : public antlr4::ParserRuleContext {
  public:
    NotoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCLAMATION_POINT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotoperatorContext* notoperator();

  class  IncrementaloperatorContext : public antlr4::ParserRuleContext {
  public:
    IncrementaloperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *DECREMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncrementaloperatorContext* incrementaloperator();

  class  PrimaryexpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<antlr4::tree::TerminalNode *> INTEGER_LITERAL();
    antlr4::tree::TerminalNode* INTEGER_LITERAL(size_t i);
    antlr4::tree::TerminalNode *PERIOD();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryexpressionContext* primaryexpression();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace valuescriptantlrgeneration
