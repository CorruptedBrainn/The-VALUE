
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
    TYPENAMES = 7, TEMPLATE = 8, IMPORT = 9, NATIVECALL = 10, CLASSSCOPE = 11, 
    INTEGER = 12, DOUBLE = 13, BOOLEAN = 14, STRING = 15, VOID = 16, PAIR = 17, 
    ARRAY = 18, ORD_LIST = 19, ORD_MAP = 20, HASH_LIST = 21, HASH_MAP = 22, 
    STACK = 23, QUEUE = 24, DEQUE = 25, PRIOR_QUE = 26, TRUE = 27, FALSE = 28, 
    IF = 29, ELSE = 30, DO = 31, WHILE = 32, FOR = 33, OPEN_PARENTHESES = 34, 
    CLOSED_PARENTHESES = 35, OPEN_CURLY_BRACE = 36, CLOSED_CURLY_BRACE = 37, 
    OPEN_ANGLE_BRACKET = 38, CLOSED_ANGLE_BRACKET = 39, OPEN_SQUARE = 40, 
    CLOSED_SQUARE = 41, PERIOD = 42, COMMA = 43, COLON = 44, SEMICOLON = 45, 
    EXCLAMATION_POINT = 46, ARROW_OPERATOR = 47, BITWISE_AND = 48, BOOLEAN_AND = 49, 
    BITWISE_OR = 50, BOOLEAN_OR = 51, BITWISE_XOR = 52, ADDITION = 53, SUBTRACTION = 54, 
    MULTIPLICATION = 55, DIVISION = 56, MODULUS = 57, INCREMENT = 58, DECREMENT = 59, 
    ASSIGNMENT_GENERIC = 60, ASSIGNMENT_ADD = 61, ASSIGNMENT_SUB = 62, ASSIGNMENT_MULTI = 63, 
    ASSIGNMENT_DIV = 64, ASSIGNMENT_MOD = 65, EQUALITY = 66, NON_EQUALITY = 67, 
    GREATER_OR_EQUAL = 68, LESS_OR_EQUAL = 69, SINGLE_LINE_COMMENT = 70, 
    MULTI_LINE_COMMENT = 71, WHITESPACE = 72, FLOATING_LITERAL = 73, INTEGER_LITERAL = 74, 
    STRING_LITERAL = 75, IDENTIFIER = 76, LETTER = 77, ESCAPE = 78
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
