
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
    BREAK = 7, TYPENAMES = 8, TEMPLATE = 9, IMPORT = 10, NATIVECALL = 11, 
    CLASSSCOPE = 12, INTEGER = 13, DOUBLE = 14, BOOLEAN = 15, STRING = 16, 
    VOID = 17, PAIR = 18, ARRAY = 19, ORD_LIST = 20, ORD_MAP = 21, HASH_LIST = 22, 
    HASH_MAP = 23, STACK = 24, QUEUE = 25, DEQUE = 26, PRIOR_QUE = 27, TRUE = 28, 
    FALSE = 29, IF = 30, ELSE = 31, DO = 32, WHILE = 33, FOR = 34, OPEN_PARENTHESES = 35, 
    CLOSED_PARENTHESES = 36, OPEN_CURLY_BRACE = 37, CLOSED_CURLY_BRACE = 38, 
    OPEN_ANGLE_BRACKET = 39, CLOSED_ANGLE_BRACKET = 40, OPEN_SQUARE = 41, 
    CLOSED_SQUARE = 42, PERIOD = 43, COMMA = 44, COLON = 45, SEMICOLON = 46, 
    EXCLAMATION_POINT = 47, ARROW_OPERATOR = 48, BITWISE_AND = 49, BOOLEAN_AND = 50, 
    BITWISE_OR = 51, BOOLEAN_OR = 52, BITWISE_XOR = 53, ADDITION = 54, SUBTRACTION = 55, 
    MULTIPLICATION = 56, DIVISION = 57, MODULUS = 58, INCREMENT = 59, DECREMENT = 60, 
    ASSIGNMENT_GENERIC = 61, ASSIGNMENT_ADD = 62, ASSIGNMENT_SUB = 63, ASSIGNMENT_MULTI = 64, 
    ASSIGNMENT_DIV = 65, ASSIGNMENT_MOD = 66, EQUALITY = 67, NON_EQUALITY = 68, 
    GREATER_OR_EQUAL = 69, LESS_OR_EQUAL = 70, SINGLE_LINE_COMMENT = 71, 
    MULTI_LINE_COMMENT = 72, WHITESPACE = 73, FLOATING_LITERAL = 74, INTEGER_LITERAL = 75, 
    STRING_LITERAL = 76, IDENTIFIER = 77, LETTER = 78, ESCAPE = 79
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
