
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
    TYPENAMES = 7, TEMPLATE = 8, IMPORT = 9, AS = 10, INTEGER = 11, DOUBLE = 12, 
    BOOLEAN = 13, STRING = 14, VOID = 15, TRUE = 16, FALSE = 17, IF = 18, 
    ELSE = 19, DO = 20, WHILE = 21, FOR = 22, OPEN_PARENTHESES = 23, CLOSED_PARENTHESES = 24, 
    OPEN_CURLY_BRACE = 25, CLOSED_CURLY_BRACE = 26, OPEN_ANGLE_BRACKET = 27, 
    CLOSED_ANGLE_BRACKET = 28, OPEN_SQUARE = 29, CLOSED_SQUARE = 30, PERIOD = 31, 
    COMMA = 32, COLON = 33, SEMICOLON = 34, EXCLAMATION_POINT = 35, ARROW_OPERATOR = 36, 
    BITWISE_AND = 37, BOOLEAN_AND = 38, BITWISE_OR = 39, BOOLEAN_OR = 40, 
    BITWISE_XOR = 41, ADDITION = 42, SUBTRACTION = 43, MULTIPLICATION = 44, 
    DIVISION = 45, MODULUS = 46, INCREMENT = 47, DECREMENT = 48, ASSIGNMENT_GENERIC = 49, 
    ASSIGNMENT_ADD = 50, ASSIGNMENT_SUB = 51, ASSIGNMENT_MULTI = 52, ASSIGNMENT_DIV = 53, 
    ASSIGNMENT_MOD = 54, EQUALITY = 55, NON_EQUALITY = 56, GREATER_OR_EQUAL = 57, 
    LESS_OR_EQUAL = 58, SINGLE_LINE_COMMENT = 59, MULTI_LINE_COMMENT = 60, 
    WHITESPACE = 61, FLOATING_LITERAL = 62, INTEGER_LITERAL = 63, STRING_LITERAL = 64, 
    IDENTIFIER = 65, LETTER = 66, ESCAPE = 67
  };

  enum {
    RuleFile = 0, RuleExtra = 1, RuleStatement = 2, RuleVariabledeclaration = 3, 
    RuleFunctiondeclaration = 4, RuleFunctionparameters = 5, RuleClassdeclaration = 6, 
    RuleTemplateexpression = 7, RuleTemplatedeclaration = 8, RuleTypenameexpression = 9, 
    RuleIfstatement = 10, RuleWhilestatement = 11, RuleDostatement = 12, 
    RuleForstatement = 13, RuleCodeblock = 14, RuleExpression = 15, RuleAssignmentoperator = 16, 
    RuleBinaryoperator = 17, RuleBooleanoperator = 18, RuleComparisonoperator = 19, 
    RuleAdditiveoperator = 20, RuleMultiplicativeoperator = 21, RuleNotoperator = 22, 
    RuleIncrementaloperator = 23, RulePrimaryexpression = 24
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
  class TemplateexpressionContext;
  class TemplatedeclarationContext;
  class TypenameexpressionContext;
  class IfstatementContext;
  class WhilestatementContext;
  class DostatementContext;
  class ForstatementContext;
  class CodeblockContext;
  class ExpressionContext;
  class AssignmentoperatorContext;
  class BinaryoperatorContext;
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExtraContext* extra();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatementwhileContext : public StatementContext {
  public:
    StatementwhileContext(StatementContext *ctx);

    WhilestatementContext *whilestatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementclassdeclContext : public StatementContext {
  public:
    StatementclassdeclContext(StatementContext *ctx);

    ClassdeclarationContext *classdeclaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementexprContext : public StatementContext {
  public:
    StatementexprContext(StatementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementretContext : public StatementContext {
  public:
    StatementretContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementvardeclContext : public StatementContext {
  public:
    StatementvardeclContext(StatementContext *ctx);

    VariabledeclarationContext *variabledeclaration();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementdoContext : public StatementContext {
  public:
    StatementdoContext(StatementContext *ctx);

    DostatementContext *dostatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementforContext : public StatementContext {
  public:
    StatementforContext(StatementContext *ctx);

    ForstatementContext *forstatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementifContext : public StatementContext {
  public:
    StatementifContext(StatementContext *ctx);

    IfstatementContext *ifstatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementfuncdeclContext : public StatementContext {
  public:
    StatementfuncdeclContext(StatementContext *ctx);

    FunctiondeclarationContext *functiondeclaration();

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassdeclarationContext* classdeclaration();

  class  TemplateexpressionContext : public antlr4::ParserRuleContext {
  public:
    TemplateexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEMPLATE();
    antlr4::tree::TerminalNode *ARROW_OPERATOR();
    std::vector<TypenameexpressionContext *> typenameexpression();
    TypenameexpressionContext* typenameexpression(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateexpressionContext* templateexpression();

  class  TemplatedeclarationContext : public antlr4::ParserRuleContext {
  public:
    TemplatedeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPENAMES();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplatedeclarationContext* templatedeclaration();

  class  TypenameexpressionContext : public antlr4::ParserRuleContext {
  public:
    TypenameexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypenameexpressionContext() = default;
    void copyFrom(TypenameexpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TydoubleContext : public TypenameexpressionContext {
  public:
    TydoubleContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TybooleanContext : public TypenameexpressionContext {
  public:
    TybooleanContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *BOOLEAN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TyidentContext : public TypenameexpressionContext {
  public:
    TyidentContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TynestedContext : public TypenameexpressionContext {
  public:
    TynestedContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_ANGLE_BRACKET();
    std::vector<TypenameexpressionContext *> typenameexpression();
    TypenameexpressionContext* typenameexpression(size_t i);
    antlr4::tree::TerminalNode *CLOSED_ANGLE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TystringContext : public TypenameexpressionContext {
  public:
    TystringContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TyintegerContext : public TypenameexpressionContext {
  public:
    TyintegerContext(TypenameexpressionContext *ctx);

    antlr4::tree::TerminalNode *INTEGER();

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DostatementContext* dostatement();

  class  ForstatementContext : public antlr4::ParserRuleContext {
  public:
    ForstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ForstatementContext() = default;
    void copyFrom(ForstatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ItemforContext : public ForstatementContext {
  public:
    ItemforContext(ForstatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    VariabledeclarationContext *variabledeclaration();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    CodeblockContext *codeblock();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RangeforContext : public ForstatementContext {
  public:
    RangeforContext(ForstatementContext *ctx);

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeblockContext* codeblock();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NotexprContext : public ExpressionContext {
  public:
    NotexprContext(ExpressionContext *ctx);

    NotoperatorContext *notoperator();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompexprContext : public ExpressionContext {
  public:
    CompexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    ComparisonoperatorContext *comparisonoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddexprContext : public ExpressionContext {
  public:
    AddexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    AdditiveoperatorContext *additiveoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MembexprContext : public ExpressionContext {
  public:
    MembexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PERIOD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignexprContext : public ExpressionContext {
  public:
    AssignexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    AssignmentoperatorContext *assignmentoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolexprContext : public ExpressionContext {
  public:
    BoolexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    BooleanoperatorContext *booleanoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AccessexprContext : public ExpressionContext {
  public:
    AccessexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPEN_SQUARE();
    antlr4::tree::TerminalNode *CLOSED_SQUARE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinexprContext : public ExpressionContext {
  public:
    BinexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    BinaryoperatorContext *binaryoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultexprContext : public ExpressionContext {
  public:
    MultexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    MultiplicativeoperatorContext *multiplicativeoperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IncexprContext : public ExpressionContext {
  public:
    IncexprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    IncrementaloperatorContext *incrementaloperator();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TyparexprContext : public ExpressionContext {
  public:
    TyparexprContext(ExpressionContext *ctx);

    TemplateexpressionContext *templateexpression();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ObjexprContext : public ExpressionContext {
  public:
    ObjexprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *OPEN_CURLY_BRACE();
    antlr4::tree::TerminalNode *CLOSED_CURLY_BRACE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimexprContext : public ExpressionContext {
  public:
    PrimexprContext(ExpressionContext *ctx);

    PrimaryexpressionContext *primaryexpression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenexprContext : public ExpressionContext {
  public:
    ParenexprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  AssignmentoperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AssignmentoperatorContext() = default;
    void copyFrom(AssignmentoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AssaddContext : public AssignmentoperatorContext {
  public:
    AssaddContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_ADD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssdivContext : public AssignmentoperatorContext {
  public:
    AssdivContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_DIV();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssmodContext : public AssignmentoperatorContext {
  public:
    AssmodContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_MOD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssmulContext : public AssignmentoperatorContext {
  public:
    AssmulContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_MULTI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsseqlContext : public AssignmentoperatorContext {
  public:
    AsseqlContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_GENERIC();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AsssubContext : public AssignmentoperatorContext {
  public:
    AsssubContext(AssignmentoperatorContext *ctx);

    antlr4::tree::TerminalNode *ASSIGNMENT_SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AssignmentoperatorContext* assignmentoperator();

  class  BinaryoperatorContext : public antlr4::ParserRuleContext {
  public:
    BinaryoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BinaryoperatorContext() = default;
    void copyFrom(BinaryoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitandContext : public BinaryoperatorContext {
  public:
    BitandContext(BinaryoperatorContext *ctx);

    antlr4::tree::TerminalNode *BITWISE_AND();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitorContext : public BinaryoperatorContext {
  public:
    BitorContext(BinaryoperatorContext *ctx);

    antlr4::tree::TerminalNode *BITWISE_OR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitxorContext : public BinaryoperatorContext {
  public:
    BitxorContext(BinaryoperatorContext *ctx);

    antlr4::tree::TerminalNode *BITWISE_XOR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BinaryoperatorContext* binaryoperator();

  class  BooleanoperatorContext : public antlr4::ParserRuleContext {
  public:
    BooleanoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BooleanoperatorContext() = default;
    void copyFrom(BooleanoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BoolandContext : public BooleanoperatorContext {
  public:
    BoolandContext(BooleanoperatorContext *ctx);

    antlr4::tree::TerminalNode *BOOLEAN_AND();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolorContext : public BooleanoperatorContext {
  public:
    BoolorContext(BooleanoperatorContext *ctx);

    antlr4::tree::TerminalNode *BOOLEAN_OR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BooleanoperatorContext* booleanoperator();

  class  ComparisonoperatorContext : public antlr4::ParserRuleContext {
  public:
    ComparisonoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ComparisonoperatorContext() = default;
    void copyFrom(ComparisonoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ComploeContext : public ComparisonoperatorContext {
  public:
    ComploeContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *LESS_OR_EQUAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompeqlContext : public ComparisonoperatorContext {
  public:
    CompeqlContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *EQUALITY();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompnonContext : public ComparisonoperatorContext {
  public:
    CompnonContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *NON_EQUALITY();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompgoeContext : public ComparisonoperatorContext {
  public:
    CompgoeContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *GREATER_OR_EQUAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComplssContext : public ComparisonoperatorContext {
  public:
    ComplssContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *OPEN_ANGLE_BRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompgreContext : public ComparisonoperatorContext {
  public:
    CompgreContext(ComparisonoperatorContext *ctx);

    antlr4::tree::TerminalNode *CLOSED_ANGLE_BRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ComparisonoperatorContext* comparisonoperator();

  class  AdditiveoperatorContext : public antlr4::ParserRuleContext {
  public:
    AdditiveoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AdditiveoperatorContext() = default;
    void copyFrom(AdditiveoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MinusContext : public AdditiveoperatorContext {
  public:
    MinusContext(AdditiveoperatorContext *ctx);

    antlr4::tree::TerminalNode *SUBTRACTION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusContext : public AdditiveoperatorContext {
  public:
    PlusContext(AdditiveoperatorContext *ctx);

    antlr4::tree::TerminalNode *ADDITION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AdditiveoperatorContext* additiveoperator();

  class  MultiplicativeoperatorContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MultiplicativeoperatorContext() = default;
    void copyFrom(MultiplicativeoperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TimesContext : public MultiplicativeoperatorContext {
  public:
    TimesContext(MultiplicativeoperatorContext *ctx);

    antlr4::tree::TerminalNode *MULTIPLICATION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DivideContext : public MultiplicativeoperatorContext {
  public:
    DivideContext(MultiplicativeoperatorContext *ctx);

    antlr4::tree::TerminalNode *DIVISION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModuloContext : public MultiplicativeoperatorContext {
  public:
    ModuloContext(MultiplicativeoperatorContext *ctx);

    antlr4::tree::TerminalNode *MODULUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MultiplicativeoperatorContext* multiplicativeoperator();

  class  NotoperatorContext : public antlr4::ParserRuleContext {
  public:
    NotoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCLAMATION_POINT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotoperatorContext* notoperator();

  class  IncrementaloperatorContext : public antlr4::ParserRuleContext {
  public:
    IncrementaloperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IncrementaloperatorContext() = default;
    void copyFrom(IncrementaloperatorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PlusplusContext : public IncrementaloperatorContext {
  public:
    PlusplusContext(IncrementaloperatorContext *ctx);

    antlr4::tree::TerminalNode *INCREMENT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MinusminusContext : public IncrementaloperatorContext {
  public:
    MinusminusContext(IncrementaloperatorContext *ctx);

    antlr4::tree::TerminalNode *DECREMENT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IncrementaloperatorContext* incrementaloperator();

  class  PrimaryexpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryexpressionContext() = default;
    void copyFrom(PrimaryexpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberContext : public PrimaryexpressionContext {
  public:
    NumberContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *INTEGER_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public PrimaryexpressionContext {
  public:
    StringContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentContext : public PrimaryexpressionContext {
  public:
    IdentContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueContext : public PrimaryexpressionContext {
  public:
    TrueContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseContext : public PrimaryexpressionContext {
  public:
    FalseContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecimalContext : public PrimaryexpressionContext {
  public:
    DecimalContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *FLOATING_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrderContext : public PrimaryexpressionContext {
  public:
    OrderContext(PrimaryexpressionContext *ctx);

    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CLOSED_PARENTHESES();

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
