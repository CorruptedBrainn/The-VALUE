
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
    TYPENAMES = 7, IMPORT = 8, AS = 9, INTEGER = 10, DOUBLE = 11, BOOLEAN = 12, 
    STRING = 13, VOID = 14, TRUE = 15, FALSE = 16, IF = 17, ELSE = 18, DO = 19, 
    WHILE = 20, FOR = 21, OPEN_PARENTHESES = 22, CLOSED_PARENTHESES = 23, 
    OPEN_CURLY_BRACE = 24, CLOSED_CURLY_BRACE = 25, OPEN_ANGLE_BRACKET = 26, 
    CLOSED_ANGLE_BRACKET = 27, OPEN_SQUARE = 28, CLOSED_SQUARE = 29, PERIOD = 30, 
    COMMA = 31, COLON = 32, SEMICOLON = 33, EXCLAMATION_POINT = 34, ARROW_OPERATOR = 35, 
    BITWISE_AND = 36, BOOLEAN_AND = 37, BITWISE_OR = 38, BOOLEAN_OR = 39, 
    BITWISE_XOR = 40, ADDITION = 41, SUBTRACTION = 42, MULTIPLICATION = 43, 
    DIVISION = 44, MODULUS = 45, INCREMENT = 46, DECREMENT = 47, ASSIGNMENT_GENERIC = 48, 
    ASSIGNMENT_ADD = 49, ASSIGNMENT_SUB = 50, ASSIGNMENT_MULTI = 51, ASSIGNMENT_DIV = 52, 
    ASSIGNMENT_MOD = 53, EQUALITY = 54, NON_EQUALITY = 55, GREATER_OR_EQUAL = 56, 
    LESS_OR_EQUAL = 57, SINGLE_LINE_COMMENT = 58, MULTI_LINE_COMMENT = 59, 
    WHITESPACE = 60, FLOATING_LITERAL = 61, INTEGER_LITERAL = 62, STRING_LITERAL = 63, 
    IDENTIFIER = 64, LETTER = 65, ESCAPE = 66
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
