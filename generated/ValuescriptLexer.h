
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
    TYPENAMES = 7, TEMPLATE = 8, IMPORT = 9, DBGOUT = 10, INTEGER = 11, 
    DOUBLE = 12, BOOLEAN = 13, STRING = 14, VOID = 15, PAIR = 16, ARRAY = 17, 
    ORD_LIST = 18, ORD_MAP = 19, HASH_LIST = 20, HASH_MAP = 21, STACK = 22, 
    QUEUE = 23, DEQUE = 24, PRIOR_QUE = 25, TRUE = 26, FALSE = 27, IF = 28, 
    ELSE = 29, DO = 30, WHILE = 31, FOR = 32, OPEN_PARENTHESES = 33, CLOSED_PARENTHESES = 34, 
    OPEN_CURLY_BRACE = 35, CLOSED_CURLY_BRACE = 36, OPEN_ANGLE_BRACKET = 37, 
    CLOSED_ANGLE_BRACKET = 38, OPEN_SQUARE = 39, CLOSED_SQUARE = 40, PERIOD = 41, 
    COMMA = 42, COLON = 43, SEMICOLON = 44, EXCLAMATION_POINT = 45, ARROW_OPERATOR = 46, 
    BITWISE_AND = 47, BOOLEAN_AND = 48, BITWISE_OR = 49, BOOLEAN_OR = 50, 
    BITWISE_XOR = 51, ADDITION = 52, SUBTRACTION = 53, MULTIPLICATION = 54, 
    DIVISION = 55, MODULUS = 56, INCREMENT = 57, DECREMENT = 58, ASSIGNMENT_GENERIC = 59, 
    ASSIGNMENT_ADD = 60, ASSIGNMENT_SUB = 61, ASSIGNMENT_MULTI = 62, ASSIGNMENT_DIV = 63, 
    ASSIGNMENT_MOD = 64, EQUALITY = 65, NON_EQUALITY = 66, GREATER_OR_EQUAL = 67, 
    LESS_OR_EQUAL = 68, SINGLE_LINE_COMMENT = 69, MULTI_LINE_COMMENT = 70, 
    WHITESPACE = 71, FLOATING_LITERAL = 72, INTEGER_LITERAL = 73, STRING_LITERAL = 74, 
    IDENTIFIER = 75, LETTER = 76, ESCAPE = 77
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
