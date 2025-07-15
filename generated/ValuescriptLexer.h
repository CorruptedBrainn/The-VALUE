
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
