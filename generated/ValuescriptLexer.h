
// Generated from ../ValuescriptLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


namespace valuescriptantlrgeneration {


class  ValuescriptLexer : public antlr4::Lexer {
public:
  enum {
    STATIC = 1, CONSTANT = 2, VARIABLE = 3, FUNCTION = 4, CLASS = 5, RETURN = 6, 
    TYPENAMES = 7, TEMPLATE = 8, IMPORT = 9, DBGOUT = 10, EXPORTVAR = 11, 
    IMPORTVAR = 12, CLASSSCOPE = 13, INTEGER = 14, DOUBLE = 15, BOOLEAN = 16, 
    STRING = 17, VOID = 18, PAIR = 19, ARRAY = 20, ORD_LIST = 21, ORD_MAP = 22, 
    HASH_LIST = 23, HASH_MAP = 24, STACK = 25, QUEUE = 26, DEQUE = 27, PRIOR_QUE = 28, 
    TRUE = 29, FALSE = 30, IF = 31, ELSE = 32, DO = 33, WHILE = 34, FOR = 35, 
    OPEN_PARENTHESES = 36, CLOSED_PARENTHESES = 37, OPEN_CURLY_BRACE = 38, 
    CLOSED_CURLY_BRACE = 39, OPEN_ANGLE_BRACKET = 40, CLOSED_ANGLE_BRACKET = 41, 
    OPEN_SQUARE = 42, CLOSED_SQUARE = 43, PERIOD = 44, COMMA = 45, COLON = 46, 
    SEMICOLON = 47, EXCLAMATION_POINT = 48, ARROW_OPERATOR = 49, BITWISE_AND = 50, 
    BOOLEAN_AND = 51, BITWISE_OR = 52, BOOLEAN_OR = 53, BITWISE_XOR = 54, 
    ADDITION = 55, SUBTRACTION = 56, MULTIPLICATION = 57, DIVISION = 58, 
    MODULUS = 59, INCREMENT = 60, DECREMENT = 61, ASSIGNMENT_GENERIC = 62, 
    ASSIGNMENT_ADD = 63, ASSIGNMENT_SUB = 64, ASSIGNMENT_MULTI = 65, ASSIGNMENT_DIV = 66, 
    ASSIGNMENT_MOD = 67, EQUALITY = 68, NON_EQUALITY = 69, GREATER_OR_EQUAL = 70, 
    LESS_OR_EQUAL = 71, SINGLE_LINE_COMMENT = 72, MULTI_LINE_COMMENT = 73, 
    WHITESPACE = 74, FLOATING_LITERAL = 75, INTEGER_LITERAL = 76, STRING_LITERAL = 77, 
    IDENTIFIER = 78, LETTER = 79, ESCAPE = 80
  };

  explicit ValuescriptLexer(antlr4::CharStream *input);

  ~ValuescriptLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace valuescriptantlrgeneration
