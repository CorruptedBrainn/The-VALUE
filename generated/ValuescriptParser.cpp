
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2


#include "ValuescriptParserVisitor.h"

#include "ValuescriptParser.h"


/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


using namespace antlrcpp;
using namespace valuescriptantlrgeneration;

using namespace antlr4;

namespace {

struct ValuescriptParserStaticData final {
  ValuescriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ValuescriptParserStaticData(const ValuescriptParserStaticData&) = delete;
  ValuescriptParserStaticData(ValuescriptParserStaticData&&) = delete;
  ValuescriptParserStaticData& operator=(const ValuescriptParserStaticData&) = delete;
  ValuescriptParserStaticData& operator=(ValuescriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag valuescriptparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ValuescriptParserStaticData> valuescriptparserParserStaticData = nullptr;

void valuescriptparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (valuescriptparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(valuescriptparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ValuescriptParserStaticData>(
    std::vector<std::string>{
      "file", "extra", "statement", "variabledeclaration", "functiondeclaration", 
      "functionparameters", "classdeclaration", "templatedeclaration", "typenameexpression", 
      "ifstatement", "whilestatement", "dostatement", "forstatement", "codeblock", 
      "expression", "assignmentoperator", "binaryoperator", "booleanoperator", 
      "comparisonoperator", "additiveoperator", "multiplicativeoperator", 
      "notoperator", "incrementaloperator", "primaryexpression"
    },
    std::vector<std::string>{
      "", "'static'", "'const'", "'var'", "'func'", "'class'", "'return'", 
      "'typenames'", "'import'", "'as'", "'int'", "'double'", "'bool'", 
      "'str'", "'void'", "'true'", "'false'", "'if'", "'else'", "'do'", 
      "'while'", "'for'", "'('", "')'", "'{'", "'}'", "'<'", "'>'", "'['", 
      "']'", "'.'", "','", "':'", "';'", "'!'", "'->'", "'&'", "'&&'", "'|'", 
      "'||'", "'^'", "'+'", "'-'", "'*'", "'/'", "'%'", "'++'", "'--'", 
      "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'=='", "'!='", "'>='", 
      "'<='"
    },
    std::vector<std::string>{
      "", "STATIC", "CONSTANT", "VARIABLE", "FUNCTION", "CLASS", "RETURN", 
      "TYPENAMES", "IMPORT", "AS", "INTEGER", "DOUBLE", "BOOLEAN", "STRING", 
      "VOID", "TRUE", "FALSE", "IF", "ELSE", "DO", "WHILE", "FOR", "OPEN_PARENTHESES", 
      "CLOSED_PARENTHESES", "OPEN_CURLY_BRACE", "CLOSED_CURLY_BRACE", "OPEN_ANGLE_BRACKET", 
      "CLOSED_ANGLE_BRACKET", "OPEN_SQUARE", "CLOSED_SQUARE", "PERIOD", 
      "COMMA", "COLON", "SEMICOLON", "EXCLAMATION_POINT", "ARROW_OPERATOR", 
      "BITWISE_AND", "BOOLEAN_AND", "BITWISE_OR", "BOOLEAN_OR", "BITWISE_XOR", 
      "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULUS", 
      "INCREMENT", "DECREMENT", "ASSIGNMENT_GENERIC", "ASSIGNMENT_ADD", 
      "ASSIGNMENT_SUB", "ASSIGNMENT_MULTI", "ASSIGNMENT_DIV", "ASSIGNMENT_MOD", 
      "EQUALITY", "NON_EQUALITY", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "SINGLE_LINE_COMMENT", 
      "MULTI_LINE_COMMENT", "WHITESPACE", "FLOATING_LITERAL", "INTEGER_LITERAL", 
      "STRING_LITERAL", "IDENTIFIER", "LETTER", "ESCAPE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,66,368,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,5,0,50,8,0,10,0,12,0,53,9,0,1,0,4,0,56,8,0,
  	11,0,12,0,57,1,0,1,0,1,1,1,1,1,1,1,1,3,1,66,8,1,1,1,1,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,84,8,2,1,2,3,2,87,8,2,1,
  	3,5,3,90,8,3,10,3,12,3,93,9,3,1,3,1,3,1,3,1,3,5,3,99,8,3,10,3,12,3,102,
  	9,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,110,8,3,1,4,3,4,113,8,4,1,4,3,4,116,8,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,3,5,126,8,5,1,5,1,5,5,5,130,8,5,10,
  	5,12,5,133,9,5,1,5,1,5,1,6,3,6,138,8,6,1,6,3,6,141,8,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,7,5,7,151,8,7,10,7,12,7,154,9,7,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,5,8,166,8,8,10,8,12,8,169,9,8,1,8,1,8,3,8,173,8,8,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,183,8,9,3,9,185,8,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,
  	1,12,5,12,205,8,12,10,12,12,12,208,9,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	5,12,216,8,12,10,12,12,12,219,9,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,3,12,232,8,12,1,13,1,13,4,13,236,8,13,11,13,12,13,
  	237,1,13,1,13,1,13,3,13,243,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,5,14,254,8,14,10,14,12,14,257,9,14,3,14,259,8,14,1,14,3,14,262,
  	8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,5,14,296,8,14,10,14,12,14,299,9,14,3,14,301,
  	8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,311,8,14,10,14,12,14,
  	314,9,14,1,15,1,15,1,15,1,15,1,15,1,15,3,15,322,8,15,1,16,1,16,1,16,3,
  	16,327,8,16,1,17,1,17,3,17,331,8,17,1,18,1,18,1,18,1,18,1,18,1,18,3,18,
  	339,8,18,1,19,1,19,3,19,343,8,19,1,20,1,20,1,20,3,20,348,8,20,1,21,1,
  	21,1,22,1,22,3,22,354,8,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,3,23,366,8,23,1,23,0,1,28,24,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,0,2,2,0,1,1,3,3,1,0,1,3,417,0,51,1,0,
  	0,0,2,61,1,0,0,0,4,86,1,0,0,0,6,109,1,0,0,0,8,112,1,0,0,0,10,123,1,0,
  	0,0,12,137,1,0,0,0,14,145,1,0,0,0,16,172,1,0,0,0,18,174,1,0,0,0,20,186,
  	1,0,0,0,22,192,1,0,0,0,24,231,1,0,0,0,26,242,1,0,0,0,28,261,1,0,0,0,30,
  	321,1,0,0,0,32,326,1,0,0,0,34,330,1,0,0,0,36,338,1,0,0,0,38,342,1,0,0,
  	0,40,347,1,0,0,0,42,349,1,0,0,0,44,353,1,0,0,0,46,365,1,0,0,0,48,50,3,
  	2,1,0,49,48,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,55,1,
  	0,0,0,53,51,1,0,0,0,54,56,3,4,2,0,55,54,1,0,0,0,56,57,1,0,0,0,57,55,1,
  	0,0,0,57,58,1,0,0,0,58,59,1,0,0,0,59,60,5,0,0,1,60,1,1,0,0,0,61,62,5,
  	8,0,0,62,65,5,64,0,0,63,64,5,9,0,0,64,66,5,64,0,0,65,63,1,0,0,0,65,66,
  	1,0,0,0,66,67,1,0,0,0,67,68,5,33,0,0,68,3,1,0,0,0,69,70,3,6,3,0,70,71,
  	5,33,0,0,71,87,1,0,0,0,72,87,3,8,4,0,73,87,3,12,6,0,74,87,3,18,9,0,75,
  	87,3,20,10,0,76,87,3,22,11,0,77,87,3,24,12,0,78,79,3,28,14,0,79,80,5,
  	33,0,0,80,87,1,0,0,0,81,83,5,6,0,0,82,84,3,28,14,0,83,82,1,0,0,0,83,84,
  	1,0,0,0,84,85,1,0,0,0,85,87,5,33,0,0,86,69,1,0,0,0,86,72,1,0,0,0,86,73,
  	1,0,0,0,86,74,1,0,0,0,86,75,1,0,0,0,86,76,1,0,0,0,86,77,1,0,0,0,86,78,
  	1,0,0,0,86,81,1,0,0,0,87,5,1,0,0,0,88,90,7,0,0,0,89,88,1,0,0,0,90,93,
  	1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,95,
  	5,64,0,0,95,96,5,35,0,0,96,110,3,16,8,0,97,99,7,1,0,0,98,97,1,0,0,0,99,
  	102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,103,1,0,0,0,102,100,1,
  	0,0,0,103,104,5,64,0,0,104,105,5,35,0,0,105,106,3,16,8,0,106,107,5,48,
  	0,0,107,108,3,28,14,0,108,110,1,0,0,0,109,91,1,0,0,0,109,100,1,0,0,0,
  	110,7,1,0,0,0,111,113,3,14,7,0,112,111,1,0,0,0,112,113,1,0,0,0,113,115,
  	1,0,0,0,114,116,5,4,0,0,115,114,1,0,0,0,115,116,1,0,0,0,116,117,1,0,0,
  	0,117,118,5,64,0,0,118,119,3,10,5,0,119,120,5,35,0,0,120,121,3,16,8,0,
  	121,122,3,26,13,0,122,9,1,0,0,0,123,125,5,22,0,0,124,126,3,6,3,0,125,
  	124,1,0,0,0,125,126,1,0,0,0,126,131,1,0,0,0,127,128,5,31,0,0,128,130,
  	3,6,3,0,129,127,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,
  	0,132,134,1,0,0,0,133,131,1,0,0,0,134,135,5,23,0,0,135,11,1,0,0,0,136,
  	138,3,14,7,0,137,136,1,0,0,0,137,138,1,0,0,0,138,140,1,0,0,0,139,141,
  	5,5,0,0,140,139,1,0,0,0,140,141,1,0,0,0,141,142,1,0,0,0,142,143,5,64,
  	0,0,143,144,3,26,13,0,144,13,1,0,0,0,145,146,5,7,0,0,146,147,5,32,0,0,
  	147,152,5,64,0,0,148,149,5,31,0,0,149,151,5,64,0,0,150,148,1,0,0,0,151,
  	154,1,0,0,0,152,150,1,0,0,0,152,153,1,0,0,0,153,15,1,0,0,0,154,152,1,
  	0,0,0,155,173,5,10,0,0,156,173,5,11,0,0,157,173,5,13,0,0,158,173,5,12,
  	0,0,159,173,5,64,0,0,160,161,5,64,0,0,161,162,5,26,0,0,162,167,3,16,8,
  	0,163,164,5,31,0,0,164,166,3,16,8,0,165,163,1,0,0,0,166,169,1,0,0,0,167,
  	165,1,0,0,0,167,168,1,0,0,0,168,170,1,0,0,0,169,167,1,0,0,0,170,171,5,
  	27,0,0,171,173,1,0,0,0,172,155,1,0,0,0,172,156,1,0,0,0,172,157,1,0,0,
  	0,172,158,1,0,0,0,172,159,1,0,0,0,172,160,1,0,0,0,173,17,1,0,0,0,174,
  	175,5,17,0,0,175,176,5,22,0,0,176,177,3,28,14,0,177,178,5,23,0,0,178,
  	184,3,26,13,0,179,182,5,18,0,0,180,183,3,26,13,0,181,183,3,18,9,0,182,
  	180,1,0,0,0,182,181,1,0,0,0,183,185,1,0,0,0,184,179,1,0,0,0,184,185,1,
  	0,0,0,185,19,1,0,0,0,186,187,5,20,0,0,187,188,5,22,0,0,188,189,3,28,14,
  	0,189,190,5,23,0,0,190,191,3,26,13,0,191,21,1,0,0,0,192,193,5,19,0,0,
  	193,194,3,26,13,0,194,195,5,20,0,0,195,196,5,22,0,0,196,197,3,28,14,0,
  	197,198,5,23,0,0,198,23,1,0,0,0,199,200,5,21,0,0,200,201,5,22,0,0,201,
  	206,3,6,3,0,202,203,5,31,0,0,203,205,3,6,3,0,204,202,1,0,0,0,205,208,
  	1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,209,1,0,0,0,208,206,1,0,0,
  	0,209,210,5,33,0,0,210,211,3,28,14,0,211,212,5,33,0,0,212,217,3,28,14,
  	0,213,214,5,31,0,0,214,216,3,28,14,0,215,213,1,0,0,0,216,219,1,0,0,0,
  	217,215,1,0,0,0,217,218,1,0,0,0,218,220,1,0,0,0,219,217,1,0,0,0,220,221,
  	5,23,0,0,221,222,3,26,13,0,222,232,1,0,0,0,223,224,5,21,0,0,224,225,5,
  	22,0,0,225,226,3,6,3,0,226,227,5,32,0,0,227,228,3,28,14,0,228,229,5,23,
  	0,0,229,230,3,26,13,0,230,232,1,0,0,0,231,199,1,0,0,0,231,223,1,0,0,0,
  	232,25,1,0,0,0,233,235,5,24,0,0,234,236,3,4,2,0,235,234,1,0,0,0,236,237,
  	1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,239,1,0,0,0,239,240,5,25,
  	0,0,240,243,1,0,0,0,241,243,3,4,2,0,242,233,1,0,0,0,242,241,1,0,0,0,243,
  	27,1,0,0,0,244,245,6,14,-1,0,245,262,3,46,23,0,246,247,3,42,21,0,247,
  	248,3,28,14,8,248,262,1,0,0,0,249,258,5,24,0,0,250,255,3,28,14,0,251,
  	252,5,31,0,0,252,254,3,28,14,0,253,251,1,0,0,0,254,257,1,0,0,0,255,253,
  	1,0,0,0,255,256,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,258,250,1,0,0,
  	0,258,259,1,0,0,0,259,260,1,0,0,0,260,262,5,25,0,0,261,244,1,0,0,0,261,
  	246,1,0,0,0,261,249,1,0,0,0,262,312,1,0,0,0,263,264,10,12,0,0,264,265,
  	5,30,0,0,265,311,3,28,14,13,266,267,10,7,0,0,267,268,3,40,20,0,268,269,
  	3,28,14,8,269,311,1,0,0,0,270,271,10,6,0,0,271,272,3,38,19,0,272,273,
  	3,28,14,7,273,311,1,0,0,0,274,275,10,5,0,0,275,276,3,36,18,0,276,277,
  	3,28,14,6,277,311,1,0,0,0,278,279,10,4,0,0,279,280,3,34,17,0,280,281,
  	3,28,14,5,281,311,1,0,0,0,282,283,10,3,0,0,283,284,3,32,16,0,284,285,
  	3,28,14,4,285,311,1,0,0,0,286,287,10,1,0,0,287,288,3,30,15,0,288,289,
  	3,28,14,2,289,311,1,0,0,0,290,291,10,11,0,0,291,300,5,22,0,0,292,297,
  	3,28,14,0,293,294,5,31,0,0,294,296,3,28,14,0,295,293,1,0,0,0,296,299,
  	1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,
  	0,300,292,1,0,0,0,300,301,1,0,0,0,301,302,1,0,0,0,302,311,5,23,0,0,303,
  	304,10,10,0,0,304,305,5,28,0,0,305,306,3,28,14,0,306,307,5,29,0,0,307,
  	311,1,0,0,0,308,309,10,9,0,0,309,311,3,44,22,0,310,263,1,0,0,0,310,266,
  	1,0,0,0,310,270,1,0,0,0,310,274,1,0,0,0,310,278,1,0,0,0,310,282,1,0,0,
  	0,310,286,1,0,0,0,310,290,1,0,0,0,310,303,1,0,0,0,310,308,1,0,0,0,311,
  	314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,29,1,0,0,0,314,312,1,
  	0,0,0,315,322,5,48,0,0,316,322,5,49,0,0,317,322,5,50,0,0,318,322,5,51,
  	0,0,319,322,5,52,0,0,320,322,5,53,0,0,321,315,1,0,0,0,321,316,1,0,0,0,
  	321,317,1,0,0,0,321,318,1,0,0,0,321,319,1,0,0,0,321,320,1,0,0,0,322,31,
  	1,0,0,0,323,327,5,36,0,0,324,327,5,38,0,0,325,327,5,40,0,0,326,323,1,
  	0,0,0,326,324,1,0,0,0,326,325,1,0,0,0,327,33,1,0,0,0,328,331,5,37,0,0,
  	329,331,5,39,0,0,330,328,1,0,0,0,330,329,1,0,0,0,331,35,1,0,0,0,332,339,
  	5,54,0,0,333,339,5,55,0,0,334,339,5,56,0,0,335,339,5,57,0,0,336,339,5,
  	26,0,0,337,339,5,27,0,0,338,332,1,0,0,0,338,333,1,0,0,0,338,334,1,0,0,
  	0,338,335,1,0,0,0,338,336,1,0,0,0,338,337,1,0,0,0,339,37,1,0,0,0,340,
  	343,5,41,0,0,341,343,5,42,0,0,342,340,1,0,0,0,342,341,1,0,0,0,343,39,
  	1,0,0,0,344,348,5,43,0,0,345,348,5,44,0,0,346,348,5,45,0,0,347,344,1,
  	0,0,0,347,345,1,0,0,0,347,346,1,0,0,0,348,41,1,0,0,0,349,350,5,34,0,0,
  	350,43,1,0,0,0,351,354,5,46,0,0,352,354,5,47,0,0,353,351,1,0,0,0,353,
  	352,1,0,0,0,354,45,1,0,0,0,355,366,5,64,0,0,356,366,5,61,0,0,357,366,
  	5,62,0,0,358,366,5,15,0,0,359,366,5,16,0,0,360,366,5,63,0,0,361,362,5,
  	22,0,0,362,363,3,28,14,0,363,364,5,23,0,0,364,366,1,0,0,0,365,355,1,0,
  	0,0,365,356,1,0,0,0,365,357,1,0,0,0,365,358,1,0,0,0,365,359,1,0,0,0,365,
  	360,1,0,0,0,365,361,1,0,0,0,366,47,1,0,0,0,39,51,57,65,83,86,91,100,109,
  	112,115,125,131,137,140,152,167,172,182,184,206,217,231,237,242,255,258,
  	261,297,300,310,312,321,326,330,338,342,347,353,365
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  valuescriptparserParserStaticData = std::move(staticData);
}

}

ValuescriptParser::ValuescriptParser(TokenStream *input) : ValuescriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ValuescriptParser::ValuescriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ValuescriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *valuescriptparserParserStaticData->atn, valuescriptparserParserStaticData->decisionToDFA, valuescriptparserParserStaticData->sharedContextCache, options);
}

ValuescriptParser::~ValuescriptParser() {
  delete _interpreter;
}

const atn::ATN& ValuescriptParser::getATN() const {
  return *valuescriptparserParserStaticData->atn;
}

std::string ValuescriptParser::getGrammarFileName() const {
  return "ValuescriptParser.g4";
}

const std::vector<std::string>& ValuescriptParser::getRuleNames() const {
  return valuescriptparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& ValuescriptParser::getVocabulary() const {
  return valuescriptparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ValuescriptParser::getSerializedATN() const {
  return valuescriptparserParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

ValuescriptParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::FileContext::EOF() {
  return getToken(ValuescriptParser::EOF, 0);
}

std::vector<ValuescriptParser::ExtraContext *> ValuescriptParser::FileContext::extra() {
  return getRuleContexts<ValuescriptParser::ExtraContext>();
}

ValuescriptParser::ExtraContext* ValuescriptParser::FileContext::extra(size_t i) {
  return getRuleContext<ValuescriptParser::ExtraContext>(i);
}

std::vector<ValuescriptParser::StatementContext *> ValuescriptParser::FileContext::statement() {
  return getRuleContexts<ValuescriptParser::StatementContext>();
}

ValuescriptParser::StatementContext* ValuescriptParser::FileContext::statement(size_t i) {
  return getRuleContext<ValuescriptParser::StatementContext>(i);
}


size_t ValuescriptParser::FileContext::getRuleIndex() const {
  return ValuescriptParser::RuleFile;
}


std::any ValuescriptParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::FileContext* ValuescriptParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, ValuescriptParser::RuleFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::IMPORT) {
      setState(48);
      extra();
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(54);
      statement();
      setState(57); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -1152921496004476801) != 0));
    setState(59);
    match(ValuescriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExtraContext ------------------------------------------------------------------

ValuescriptParser::ExtraContext::ExtraContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::ExtraContext::IMPORT() {
  return getToken(ValuescriptParser::IMPORT, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ExtraContext::IDENTIFIER() {
  return getTokens(ValuescriptParser::IDENTIFIER);
}

tree::TerminalNode* ValuescriptParser::ExtraContext::IDENTIFIER(size_t i) {
  return getToken(ValuescriptParser::IDENTIFIER, i);
}

tree::TerminalNode* ValuescriptParser::ExtraContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

tree::TerminalNode* ValuescriptParser::ExtraContext::AS() {
  return getToken(ValuescriptParser::AS, 0);
}


size_t ValuescriptParser::ExtraContext::getRuleIndex() const {
  return ValuescriptParser::RuleExtra;
}


std::any ValuescriptParser::ExtraContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitExtra(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::ExtraContext* ValuescriptParser::extra() {
  ExtraContext *_localctx = _tracker.createInstance<ExtraContext>(_ctx, getState());
  enterRule(_localctx, 2, ValuescriptParser::RuleExtra);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(ValuescriptParser::IMPORT);
    setState(62);
    match(ValuescriptParser::IDENTIFIER);
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::AS) {
      setState(63);
      match(ValuescriptParser::AS);
      setState(64);
      match(ValuescriptParser::IDENTIFIER);
    }
    setState(67);
    match(ValuescriptParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ValuescriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::StatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleStatement;
}

void ValuescriptParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementwhileContext ------------------------------------------------------------------

ValuescriptParser::WhilestatementContext* ValuescriptParser::StatementwhileContext::whilestatement() {
  return getRuleContext<ValuescriptParser::WhilestatementContext>(0);
}

ValuescriptParser::StatementwhileContext::StatementwhileContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementwhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementwhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementclassdeclContext ------------------------------------------------------------------

ValuescriptParser::ClassdeclarationContext* ValuescriptParser::StatementclassdeclContext::classdeclaration() {
  return getRuleContext<ValuescriptParser::ClassdeclarationContext>(0);
}

ValuescriptParser::StatementclassdeclContext::StatementclassdeclContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementclassdeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementclassdecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementexprContext ------------------------------------------------------------------

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementexprContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementexprContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::StatementexprContext::StatementexprContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementretContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::StatementretContext::RETURN() {
  return getToken(ValuescriptParser::RETURN, 0);
}

tree::TerminalNode* ValuescriptParser::StatementretContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementretContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

ValuescriptParser::StatementretContext::StatementretContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementretContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementret(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementvardeclContext ------------------------------------------------------------------

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::StatementvardeclContext::variabledeclaration() {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementvardeclContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::StatementvardeclContext::StatementvardeclContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementvardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementvardecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementdoContext ------------------------------------------------------------------

ValuescriptParser::DostatementContext* ValuescriptParser::StatementdoContext::dostatement() {
  return getRuleContext<ValuescriptParser::DostatementContext>(0);
}

ValuescriptParser::StatementdoContext::StatementdoContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementdoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementdo(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementforContext ------------------------------------------------------------------

ValuescriptParser::ForstatementContext* ValuescriptParser::StatementforContext::forstatement() {
  return getRuleContext<ValuescriptParser::ForstatementContext>(0);
}

ValuescriptParser::StatementforContext::StatementforContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementforContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementfor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementifContext ------------------------------------------------------------------

ValuescriptParser::IfstatementContext* ValuescriptParser::StatementifContext::ifstatement() {
  return getRuleContext<ValuescriptParser::IfstatementContext>(0);
}

ValuescriptParser::StatementifContext::StatementifContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementif(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementfuncdeclContext ------------------------------------------------------------------

ValuescriptParser::FunctiondeclarationContext* ValuescriptParser::StatementfuncdeclContext::functiondeclaration() {
  return getRuleContext<ValuescriptParser::FunctiondeclarationContext>(0);
}

ValuescriptParser::StatementfuncdeclContext::StatementfuncdeclContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementfuncdeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementfuncdecl(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::StatementContext* ValuescriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ValuescriptParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementvardeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(69);
      variabledeclaration();
      setState(70);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementfuncdeclContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(72);
      functiondeclaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementclassdeclContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(73);
      classdeclaration();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementifContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(74);
      ifstatement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementwhileContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(75);
      whilestatement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementdoContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(76);
      dostatement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementforContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(77);
      forstatement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementexprContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(78);
      expression(0);
      setState(79);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementretContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(81);
      match(ValuescriptParser::RETURN);
      setState(83);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 15) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 15)) & 1055531163189891) != 0)) {
        setState(82);
        expression(0);
      }
      setState(85);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariabledeclarationContext ------------------------------------------------------------------

ValuescriptParser::VariabledeclarationContext::VariabledeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::ARROW_OPERATOR() {
  return getToken(ValuescriptParser::ARROW_OPERATOR, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::VariabledeclarationContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::VariabledeclarationContext::STATIC() {
  return getTokens(ValuescriptParser::STATIC);
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::STATIC(size_t i) {
  return getToken(ValuescriptParser::STATIC, i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::VariabledeclarationContext::VARIABLE() {
  return getTokens(ValuescriptParser::VARIABLE);
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::VARIABLE(size_t i) {
  return getToken(ValuescriptParser::VARIABLE, i);
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::ASSIGNMENT_GENERIC() {
  return getToken(ValuescriptParser::ASSIGNMENT_GENERIC, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::VariabledeclarationContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::VariabledeclarationContext::CONSTANT() {
  return getTokens(ValuescriptParser::CONSTANT);
}

tree::TerminalNode* ValuescriptParser::VariabledeclarationContext::CONSTANT(size_t i) {
  return getToken(ValuescriptParser::CONSTANT, i);
}


size_t ValuescriptParser::VariabledeclarationContext::getRuleIndex() const {
  return ValuescriptParser::RuleVariabledeclaration;
}


std::any ValuescriptParser::VariabledeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitVariabledeclaration(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::variabledeclaration() {
  VariabledeclarationContext *_localctx = _tracker.createInstance<VariabledeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, ValuescriptParser::RuleVariabledeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::STATIC

      || _la == ValuescriptParser::VARIABLE) {
        setState(88);
        _la = _input->LA(1);
        if (!(_la == ValuescriptParser::STATIC

        || _la == ValuescriptParser::VARIABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(93);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(94);
      match(ValuescriptParser::IDENTIFIER);
      setState(95);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(96);
      typenameexpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 14) != 0)) {
        setState(97);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 14) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(103);
      match(ValuescriptParser::IDENTIFIER);
      setState(104);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(105);
      typenameexpression();
      setState(106);
      match(ValuescriptParser::ASSIGNMENT_GENERIC);
      setState(107);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctiondeclarationContext ------------------------------------------------------------------

ValuescriptParser::FunctiondeclarationContext::FunctiondeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::FunctiondeclarationContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

ValuescriptParser::FunctionparametersContext* ValuescriptParser::FunctiondeclarationContext::functionparameters() {
  return getRuleContext<ValuescriptParser::FunctionparametersContext>(0);
}

tree::TerminalNode* ValuescriptParser::FunctiondeclarationContext::ARROW_OPERATOR() {
  return getToken(ValuescriptParser::ARROW_OPERATOR, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::FunctiondeclarationContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::FunctiondeclarationContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

ValuescriptParser::TemplatedeclarationContext* ValuescriptParser::FunctiondeclarationContext::templatedeclaration() {
  return getRuleContext<ValuescriptParser::TemplatedeclarationContext>(0);
}

tree::TerminalNode* ValuescriptParser::FunctiondeclarationContext::FUNCTION() {
  return getToken(ValuescriptParser::FUNCTION, 0);
}


size_t ValuescriptParser::FunctiondeclarationContext::getRuleIndex() const {
  return ValuescriptParser::RuleFunctiondeclaration;
}


std::any ValuescriptParser::FunctiondeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctiondeclaration(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::FunctiondeclarationContext* ValuescriptParser::functiondeclaration() {
  FunctiondeclarationContext *_localctx = _tracker.createInstance<FunctiondeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, ValuescriptParser::RuleFunctiondeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(111);
      templatedeclaration();
    }
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::FUNCTION) {
      setState(114);
      match(ValuescriptParser::FUNCTION);
    }
    setState(117);
    match(ValuescriptParser::IDENTIFIER);
    setState(118);
    functionparameters();
    setState(119);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(120);
    typenameexpression();
    setState(121);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionparametersContext ------------------------------------------------------------------

ValuescriptParser::FunctionparametersContext::FunctionparametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::FunctionparametersContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::FunctionparametersContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

std::vector<ValuescriptParser::VariabledeclarationContext *> ValuescriptParser::FunctionparametersContext::variabledeclaration() {
  return getRuleContexts<ValuescriptParser::VariabledeclarationContext>();
}

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::FunctionparametersContext::variabledeclaration(size_t i) {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::FunctionparametersContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::FunctionparametersContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}


size_t ValuescriptParser::FunctionparametersContext::getRuleIndex() const {
  return ValuescriptParser::RuleFunctionparameters;
}


std::any ValuescriptParser::FunctionparametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionparameters(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::FunctionparametersContext* ValuescriptParser::functionparameters() {
  FunctionparametersContext *_localctx = _tracker.createInstance<FunctionparametersContext>(_ctx, getState());
  enterRule(_localctx, 10, ValuescriptParser::RuleFunctionparameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9223372036854775801) != 0)) {
      setState(124);
      variabledeclaration();
    }
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(127);
      match(ValuescriptParser::COMMA);
      setState(128);
      variabledeclaration();
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
    match(ValuescriptParser::CLOSED_PARENTHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassdeclarationContext ------------------------------------------------------------------

ValuescriptParser::ClassdeclarationContext::ClassdeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::ClassdeclarationContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::ClassdeclarationContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

ValuescriptParser::TemplatedeclarationContext* ValuescriptParser::ClassdeclarationContext::templatedeclaration() {
  return getRuleContext<ValuescriptParser::TemplatedeclarationContext>(0);
}

tree::TerminalNode* ValuescriptParser::ClassdeclarationContext::CLASS() {
  return getToken(ValuescriptParser::CLASS, 0);
}


size_t ValuescriptParser::ClassdeclarationContext::getRuleIndex() const {
  return ValuescriptParser::RuleClassdeclaration;
}


std::any ValuescriptParser::ClassdeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitClassdeclaration(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::ClassdeclarationContext* ValuescriptParser::classdeclaration() {
  ClassdeclarationContext *_localctx = _tracker.createInstance<ClassdeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, ValuescriptParser::RuleClassdeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(136);
      templatedeclaration();
    }
    setState(140);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::CLASS) {
      setState(139);
      match(ValuescriptParser::CLASS);
    }
    setState(142);
    match(ValuescriptParser::IDENTIFIER);
    setState(143);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplatedeclarationContext ------------------------------------------------------------------

ValuescriptParser::TemplatedeclarationContext::TemplatedeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::TemplatedeclarationContext::TYPENAMES() {
  return getToken(ValuescriptParser::TYPENAMES, 0);
}

tree::TerminalNode* ValuescriptParser::TemplatedeclarationContext::COLON() {
  return getToken(ValuescriptParser::COLON, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TemplatedeclarationContext::IDENTIFIER() {
  return getTokens(ValuescriptParser::IDENTIFIER);
}

tree::TerminalNode* ValuescriptParser::TemplatedeclarationContext::IDENTIFIER(size_t i) {
  return getToken(ValuescriptParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TemplatedeclarationContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::TemplatedeclarationContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}


size_t ValuescriptParser::TemplatedeclarationContext::getRuleIndex() const {
  return ValuescriptParser::RuleTemplatedeclaration;
}


std::any ValuescriptParser::TemplatedeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTemplatedeclaration(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::TemplatedeclarationContext* ValuescriptParser::templatedeclaration() {
  TemplatedeclarationContext *_localctx = _tracker.createInstance<TemplatedeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, ValuescriptParser::RuleTemplatedeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(ValuescriptParser::TYPENAMES);
    setState(146);
    match(ValuescriptParser::COLON);
    setState(147);
    match(ValuescriptParser::IDENTIFIER);
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(148);
      match(ValuescriptParser::COMMA);
      setState(149);
      match(ValuescriptParser::IDENTIFIER);
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypenameexpressionContext ------------------------------------------------------------------

ValuescriptParser::TypenameexpressionContext::TypenameexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::TypenameexpressionContext::getRuleIndex() const {
  return ValuescriptParser::RuleTypenameexpression;
}

void ValuescriptParser::TypenameexpressionContext::copyFrom(TypenameexpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TydoubleContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TydoubleContext::DOUBLE() {
  return getToken(ValuescriptParser::DOUBLE, 0);
}

ValuescriptParser::TydoubleContext::TydoubleContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TydoubleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTydouble(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TybooleanContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TybooleanContext::BOOLEAN() {
  return getToken(ValuescriptParser::BOOLEAN, 0);
}

ValuescriptParser::TybooleanContext::TybooleanContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TybooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyboolean(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TyidentContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyidentContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

ValuescriptParser::TyidentContext::TyidentContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyidentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyident(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TynestedContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TynestedContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ValuescriptParser::TynestedContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TynestedContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TynestedContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TynestedContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TynestedContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::TynestedContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

ValuescriptParser::TynestedContext::TynestedContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TynestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTynested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TystringContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TystringContext::STRING() {
  return getToken(ValuescriptParser::STRING, 0);
}

ValuescriptParser::TystringContext::TystringContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TystringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTystring(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TyintegerContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyintegerContext::INTEGER() {
  return getToken(ValuescriptParser::INTEGER, 0);
}

ValuescriptParser::TyintegerContext::TyintegerContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyintegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyinteger(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::TypenameexpressionContext* ValuescriptParser::typenameexpression() {
  TypenameexpressionContext *_localctx = _tracker.createInstance<TypenameexpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, ValuescriptParser::RuleTypenameexpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyintegerContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(ValuescriptParser::INTEGER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::TydoubleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(ValuescriptParser::DOUBLE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValuescriptParser::TystringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(157);
      match(ValuescriptParser::STRING);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValuescriptParser::TybooleanContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(158);
      match(ValuescriptParser::BOOLEAN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyidentContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(159);
      match(ValuescriptParser::IDENTIFIER);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValuescriptParser::TynestedContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(160);
      match(ValuescriptParser::IDENTIFIER);
      setState(161);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(162);
      typenameexpression();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(163);
        match(ValuescriptParser::COMMA);
        setState(164);
        typenameexpression();
        setState(169);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(170);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstatementContext ------------------------------------------------------------------

ValuescriptParser::IfstatementContext::IfstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::IfstatementContext::IF() {
  return getToken(ValuescriptParser::IF, 0);
}

tree::TerminalNode* ValuescriptParser::IfstatementContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::IfstatementContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::IfstatementContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

std::vector<ValuescriptParser::CodeblockContext *> ValuescriptParser::IfstatementContext::codeblock() {
  return getRuleContexts<ValuescriptParser::CodeblockContext>();
}

ValuescriptParser::CodeblockContext* ValuescriptParser::IfstatementContext::codeblock(size_t i) {
  return getRuleContext<ValuescriptParser::CodeblockContext>(i);
}

tree::TerminalNode* ValuescriptParser::IfstatementContext::ELSE() {
  return getToken(ValuescriptParser::ELSE, 0);
}

ValuescriptParser::IfstatementContext* ValuescriptParser::IfstatementContext::ifstatement() {
  return getRuleContext<ValuescriptParser::IfstatementContext>(0);
}


size_t ValuescriptParser::IfstatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleIfstatement;
}


std::any ValuescriptParser::IfstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitIfstatement(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::IfstatementContext* ValuescriptParser::ifstatement() {
  IfstatementContext *_localctx = _tracker.createInstance<IfstatementContext>(_ctx, getState());
  enterRule(_localctx, 18, ValuescriptParser::RuleIfstatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(ValuescriptParser::IF);
    setState(175);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(176);
    expression(0);
    setState(177);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(178);
    codeblock();
    setState(184);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(179);
      match(ValuescriptParser::ELSE);
      setState(182);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(180);
        codeblock();
        break;
      }

      case 2: {
        setState(181);
        ifstatement();
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhilestatementContext ------------------------------------------------------------------

ValuescriptParser::WhilestatementContext::WhilestatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::WhilestatementContext::WHILE() {
  return getToken(ValuescriptParser::WHILE, 0);
}

tree::TerminalNode* ValuescriptParser::WhilestatementContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::WhilestatementContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::WhilestatementContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::WhilestatementContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}


size_t ValuescriptParser::WhilestatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleWhilestatement;
}


std::any ValuescriptParser::WhilestatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitWhilestatement(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::WhilestatementContext* ValuescriptParser::whilestatement() {
  WhilestatementContext *_localctx = _tracker.createInstance<WhilestatementContext>(_ctx, getState());
  enterRule(_localctx, 20, ValuescriptParser::RuleWhilestatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(ValuescriptParser::WHILE);
    setState(187);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(188);
    expression(0);
    setState(189);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(190);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DostatementContext ------------------------------------------------------------------

ValuescriptParser::DostatementContext::DostatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::DostatementContext::DO() {
  return getToken(ValuescriptParser::DO, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::DostatementContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

tree::TerminalNode* ValuescriptParser::DostatementContext::WHILE() {
  return getToken(ValuescriptParser::WHILE, 0);
}

tree::TerminalNode* ValuescriptParser::DostatementContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::DostatementContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::DostatementContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}


size_t ValuescriptParser::DostatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleDostatement;
}


std::any ValuescriptParser::DostatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitDostatement(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::DostatementContext* ValuescriptParser::dostatement() {
  DostatementContext *_localctx = _tracker.createInstance<DostatementContext>(_ctx, getState());
  enterRule(_localctx, 22, ValuescriptParser::RuleDostatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(ValuescriptParser::DO);
    setState(193);
    codeblock();
    setState(194);
    match(ValuescriptParser::WHILE);
    setState(195);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(196);
    expression(0);
    setState(197);
    match(ValuescriptParser::CLOSED_PARENTHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForstatementContext ------------------------------------------------------------------

ValuescriptParser::ForstatementContext::ForstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::ForstatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleForstatement;
}

void ValuescriptParser::ForstatementContext::copyFrom(ForstatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemforContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ItemforContext::FOR() {
  return getToken(ValuescriptParser::FOR, 0);
}

tree::TerminalNode* ValuescriptParser::ItemforContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::ItemforContext::variabledeclaration() {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(0);
}

tree::TerminalNode* ValuescriptParser::ItemforContext::COLON() {
  return getToken(ValuescriptParser::COLON, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::ItemforContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::ItemforContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::ItemforContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

ValuescriptParser::ItemforContext::ItemforContext(ForstatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ItemforContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitItemfor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RangeforContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::RangeforContext::FOR() {
  return getToken(ValuescriptParser::FOR, 0);
}

tree::TerminalNode* ValuescriptParser::RangeforContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

std::vector<ValuescriptParser::VariabledeclarationContext *> ValuescriptParser::RangeforContext::variabledeclaration() {
  return getRuleContexts<ValuescriptParser::VariabledeclarationContext>();
}

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::RangeforContext::variabledeclaration(size_t i) {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::RangeforContext::SEMICOLON() {
  return getTokens(ValuescriptParser::SEMICOLON);
}

tree::TerminalNode* ValuescriptParser::RangeforContext::SEMICOLON(size_t i) {
  return getToken(ValuescriptParser::SEMICOLON, i);
}

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::RangeforContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::RangeforContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::RangeforContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::RangeforContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::RangeforContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::RangeforContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

ValuescriptParser::RangeforContext::RangeforContext(ForstatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::RangeforContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitRangefor(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::ForstatementContext* ValuescriptParser::forstatement() {
  ForstatementContext *_localctx = _tracker.createInstance<ForstatementContext>(_ctx, getState());
  enterRule(_localctx, 24, ValuescriptParser::RuleForstatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::RangeforContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(199);
      match(ValuescriptParser::FOR);
      setState(200);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(201);
      variabledeclaration();
      setState(206);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(202);
        match(ValuescriptParser::COMMA);
        setState(203);
        variabledeclaration();
        setState(208);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(209);
      match(ValuescriptParser::SEMICOLON);
      setState(210);
      expression(0);
      setState(211);
      match(ValuescriptParser::SEMICOLON);
      setState(212);
      expression(0);
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(213);
        match(ValuescriptParser::COMMA);
        setState(214);
        expression(0);
        setState(219);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(220);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(221);
      codeblock();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::ItemforContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(223);
      match(ValuescriptParser::FOR);
      setState(224);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(225);
      variabledeclaration();
      setState(226);
      match(ValuescriptParser::COLON);
      setState(227);
      expression(0);
      setState(228);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(229);
      codeblock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeblockContext ------------------------------------------------------------------

ValuescriptParser::CodeblockContext::CodeblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::CodeblockContext::OPEN_CURLY_BRACE() {
  return getToken(ValuescriptParser::OPEN_CURLY_BRACE, 0);
}

tree::TerminalNode* ValuescriptParser::CodeblockContext::CLOSED_CURLY_BRACE() {
  return getToken(ValuescriptParser::CLOSED_CURLY_BRACE, 0);
}

std::vector<ValuescriptParser::StatementContext *> ValuescriptParser::CodeblockContext::statement() {
  return getRuleContexts<ValuescriptParser::StatementContext>();
}

ValuescriptParser::StatementContext* ValuescriptParser::CodeblockContext::statement(size_t i) {
  return getRuleContext<ValuescriptParser::StatementContext>(i);
}


size_t ValuescriptParser::CodeblockContext::getRuleIndex() const {
  return ValuescriptParser::RuleCodeblock;
}


std::any ValuescriptParser::CodeblockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCodeblock(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::codeblock() {
  CodeblockContext *_localctx = _tracker.createInstance<CodeblockContext>(_ctx, getState());
  enterRule(_localctx, 26, ValuescriptParser::RuleCodeblock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(233);
      match(ValuescriptParser::OPEN_CURLY_BRACE);
      setState(235); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(234);
        statement();
        setState(237); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((((_la - 1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 1)) & -1152921496004476801) != 0));
      setState(239);
      match(ValuescriptParser::CLOSED_CURLY_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(241);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ValuescriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::ExpressionContext::getRuleIndex() const {
  return ValuescriptParser::RuleExpression;
}

void ValuescriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NotexprContext ------------------------------------------------------------------

ValuescriptParser::NotoperatorContext* ValuescriptParser::NotexprContext::notoperator() {
  return getRuleContext<ValuescriptParser::NotoperatorContext>(0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::NotexprContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

ValuescriptParser::NotexprContext::NotexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::NotexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitNotexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::CompexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::CompexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::ComparisonoperatorContext* ValuescriptParser::CompexprContext::comparisonoperator() {
  return getRuleContext<ValuescriptParser::ComparisonoperatorContext>(0);
}

ValuescriptParser::CompexprContext::CompexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::CompexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCompexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::AddexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::AddexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::AdditiveoperatorContext* ValuescriptParser::AddexprContext::additiveoperator() {
  return getRuleContext<ValuescriptParser::AdditiveoperatorContext>(0);
}

ValuescriptParser::AddexprContext::AddexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AddexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAddexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MembexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::MembexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::MembexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::MembexprContext::PERIOD() {
  return getToken(ValuescriptParser::PERIOD, 0);
}

ValuescriptParser::MembexprContext::MembexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::MembexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitMembexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::AssignexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::AssignexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::AssignmentoperatorContext* ValuescriptParser::AssignexprContext::assignmentoperator() {
  return getRuleContext<ValuescriptParser::AssignmentoperatorContext>(0);
}

ValuescriptParser::AssignexprContext::AssignexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AssignexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::BoolexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::BoolexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::BooleanoperatorContext* ValuescriptParser::BoolexprContext::booleanoperator() {
  return getRuleContext<ValuescriptParser::BooleanoperatorContext>(0);
}

ValuescriptParser::BoolexprContext::BoolexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BoolexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBoolexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AccessexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::AccessexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::AccessexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::AccessexprContext::OPEN_SQUARE() {
  return getToken(ValuescriptParser::OPEN_SQUARE, 0);
}

tree::TerminalNode* ValuescriptParser::AccessexprContext::CLOSED_SQUARE() {
  return getToken(ValuescriptParser::CLOSED_SQUARE, 0);
}

ValuescriptParser::AccessexprContext::AccessexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AccessexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAccessexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::BinexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::BinexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::BinaryoperatorContext* ValuescriptParser::BinexprContext::binaryoperator() {
  return getRuleContext<ValuescriptParser::BinaryoperatorContext>(0);
}

ValuescriptParser::BinexprContext::BinexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BinexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBinexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::MultexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::MultexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

ValuescriptParser::MultiplicativeoperatorContext* ValuescriptParser::MultexprContext::multiplicativeoperator() {
  return getRuleContext<ValuescriptParser::MultiplicativeoperatorContext>(0);
}

ValuescriptParser::MultexprContext::MultexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::MultexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitMultexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncexprContext ------------------------------------------------------------------

ValuescriptParser::ExpressionContext* ValuescriptParser::IncexprContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

ValuescriptParser::IncrementaloperatorContext* ValuescriptParser::IncexprContext::incrementaloperator() {
  return getRuleContext<ValuescriptParser::IncrementaloperatorContext>(0);
}

ValuescriptParser::IncexprContext::IncexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::IncexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitIncexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjexprContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ObjexprContext::OPEN_CURLY_BRACE() {
  return getToken(ValuescriptParser::OPEN_CURLY_BRACE, 0);
}

tree::TerminalNode* ValuescriptParser::ObjexprContext::CLOSED_CURLY_BRACE() {
  return getToken(ValuescriptParser::CLOSED_CURLY_BRACE, 0);
}

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::ObjexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::ObjexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ObjexprContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::ObjexprContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

ValuescriptParser::ObjexprContext::ObjexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ObjexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitObjexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrimexprContext ------------------------------------------------------------------

ValuescriptParser::PrimaryexpressionContext* ValuescriptParser::PrimexprContext::primaryexpression() {
  return getRuleContext<ValuescriptParser::PrimaryexpressionContext>(0);
}

ValuescriptParser::PrimexprContext::PrimexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::PrimexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitPrimexpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenexprContext ------------------------------------------------------------------

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::ParenexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::ParenexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::ParenexprContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::ParenexprContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ParenexprContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::ParenexprContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

ValuescriptParser::ParenexprContext::ParenexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ParenexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitParenexpr(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::expression() {
   return expression(0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ValuescriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ValuescriptParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, ValuescriptParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::TRUE:
      case ValuescriptParser::FALSE:
      case ValuescriptParser::OPEN_PARENTHESES:
      case ValuescriptParser::FLOATING_LITERAL:
      case ValuescriptParser::INTEGER_LITERAL:
      case ValuescriptParser::STRING_LITERAL:
      case ValuescriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<PrimexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(245);
        primaryexpression();
        break;
      }

      case ValuescriptParser::EXCLAMATION_POINT: {
        _localctx = _tracker.createInstance<NotexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(246);
        notoperator();
        setState(247);
        expression(8);
        break;
      }

      case ValuescriptParser::OPEN_CURLY_BRACE: {
        _localctx = _tracker.createInstance<ObjexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(249);
        match(ValuescriptParser::OPEN_CURLY_BRACE);
        setState(258);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 15) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 15)) & 1055531163189891) != 0)) {
          setState(250);
          expression(0);
          setState(255);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ValuescriptParser::COMMA) {
            setState(251);
            match(ValuescriptParser::COMMA);
            setState(252);
            expression(0);
            setState(257);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(260);
        match(ValuescriptParser::CLOSED_CURLY_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(312);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(310);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MembexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(263);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(264);
          match(ValuescriptParser::PERIOD);
          setState(265);
          expression(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(266);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(267);
          multiplicativeoperator();
          setState(268);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(271);
          additiveoperator();
          setState(272);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(274);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(275);
          comparisonoperator();
          setState(276);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BoolexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(278);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(279);
          booleanoperator();
          setState(280);
          expression(5);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(282);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(283);
          binaryoperator();
          setState(284);
          expression(4);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AssignexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(286);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(287);
          assignmentoperator();
          setState(288);
          expression(2);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ParenexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(290);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(291);
          match(ValuescriptParser::OPEN_PARENTHESES);
          setState(300);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 15) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 15)) & 1055531163189891) != 0)) {
            setState(292);
            expression(0);
            setState(297);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == ValuescriptParser::COMMA) {
              setState(293);
              match(ValuescriptParser::COMMA);
              setState(294);
              expression(0);
              setState(299);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(302);
          match(ValuescriptParser::CLOSED_PARENTHESES);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AccessexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(303);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(304);
          match(ValuescriptParser::OPEN_SQUARE);
          setState(305);
          expression(0);
          setState(306);
          match(ValuescriptParser::CLOSED_SQUARE);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<IncexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(308);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(309);
          incrementaloperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentoperatorContext ------------------------------------------------------------------

ValuescriptParser::AssignmentoperatorContext::AssignmentoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::AssignmentoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleAssignmentoperator;
}

void ValuescriptParser::AssignmentoperatorContext::copyFrom(AssignmentoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssaddContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AssaddContext::ASSIGNMENT_ADD() {
  return getToken(ValuescriptParser::ASSIGNMENT_ADD, 0);
}

ValuescriptParser::AssaddContext::AssaddContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AssaddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssadd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssdivContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AssdivContext::ASSIGNMENT_DIV() {
  return getToken(ValuescriptParser::ASSIGNMENT_DIV, 0);
}

ValuescriptParser::AssdivContext::AssdivContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AssdivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssdiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssmodContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AssmodContext::ASSIGNMENT_MOD() {
  return getToken(ValuescriptParser::ASSIGNMENT_MOD, 0);
}

ValuescriptParser::AssmodContext::AssmodContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AssmodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssmod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssmulContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AssmulContext::ASSIGNMENT_MULTI() {
  return getToken(ValuescriptParser::ASSIGNMENT_MULTI, 0);
}

ValuescriptParser::AssmulContext::AssmulContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AssmulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssmul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsseqlContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AsseqlContext::ASSIGNMENT_GENERIC() {
  return getToken(ValuescriptParser::ASSIGNMENT_GENERIC, 0);
}

ValuescriptParser::AsseqlContext::AsseqlContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AsseqlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAsseql(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsssubContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::AsssubContext::ASSIGNMENT_SUB() {
  return getToken(ValuescriptParser::ASSIGNMENT_SUB, 0);
}

ValuescriptParser::AsssubContext::AsssubContext(AssignmentoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::AsssubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAsssub(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::AssignmentoperatorContext* ValuescriptParser::assignmentoperator() {
  AssignmentoperatorContext *_localctx = _tracker.createInstance<AssignmentoperatorContext>(_ctx, getState());
  enterRule(_localctx, 30, ValuescriptParser::RuleAssignmentoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ASSIGNMENT_GENERIC: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsseqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(315);
        match(ValuescriptParser::ASSIGNMENT_GENERIC);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_ADD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssaddContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(316);
        match(ValuescriptParser::ASSIGNMENT_ADD);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_SUB: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsssubContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(317);
        match(ValuescriptParser::ASSIGNMENT_SUB);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MULTI: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmulContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(318);
        match(ValuescriptParser::ASSIGNMENT_MULTI);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_DIV: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssdivContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(319);
        match(ValuescriptParser::ASSIGNMENT_DIV);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MOD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmodContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(320);
        match(ValuescriptParser::ASSIGNMENT_MOD);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryoperatorContext ------------------------------------------------------------------

ValuescriptParser::BinaryoperatorContext::BinaryoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::BinaryoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleBinaryoperator;
}

void ValuescriptParser::BinaryoperatorContext::copyFrom(BinaryoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitandContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::BitandContext::BITWISE_AND() {
  return getToken(ValuescriptParser::BITWISE_AND, 0);
}

ValuescriptParser::BitandContext::BitandContext(BinaryoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BitandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBitand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitorContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::BitorContext::BITWISE_OR() {
  return getToken(ValuescriptParser::BITWISE_OR, 0);
}

ValuescriptParser::BitorContext::BitorContext(BinaryoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BitorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBitor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitxorContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::BitxorContext::BITWISE_XOR() {
  return getToken(ValuescriptParser::BITWISE_XOR, 0);
}

ValuescriptParser::BitxorContext::BitxorContext(BinaryoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BitxorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBitxor(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::BinaryoperatorContext* ValuescriptParser::binaryoperator() {
  BinaryoperatorContext *_localctx = _tracker.createInstance<BinaryoperatorContext>(_ctx, getState());
  enterRule(_localctx, 32, ValuescriptParser::RuleBinaryoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BITWISE_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(323);
        match(ValuescriptParser::BITWISE_AND);
        break;
      }

      case ValuescriptParser::BITWISE_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(324);
        match(ValuescriptParser::BITWISE_OR);
        break;
      }

      case ValuescriptParser::BITWISE_XOR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitxorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(325);
        match(ValuescriptParser::BITWISE_XOR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanoperatorContext ------------------------------------------------------------------

ValuescriptParser::BooleanoperatorContext::BooleanoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::BooleanoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleBooleanoperator;
}

void ValuescriptParser::BooleanoperatorContext::copyFrom(BooleanoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BoolandContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::BoolandContext::BOOLEAN_AND() {
  return getToken(ValuescriptParser::BOOLEAN_AND, 0);
}

ValuescriptParser::BoolandContext::BoolandContext(BooleanoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BoolandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBooland(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolorContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::BoolorContext::BOOLEAN_OR() {
  return getToken(ValuescriptParser::BOOLEAN_OR, 0);
}

ValuescriptParser::BoolorContext::BoolorContext(BooleanoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::BoolorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBoolor(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::BooleanoperatorContext* ValuescriptParser::booleanoperator() {
  BooleanoperatorContext *_localctx = _tracker.createInstance<BooleanoperatorContext>(_ctx, getState());
  enterRule(_localctx, 34, ValuescriptParser::RuleBooleanoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BOOLEAN_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(328);
        match(ValuescriptParser::BOOLEAN_AND);
        break;
      }

      case ValuescriptParser::BOOLEAN_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(329);
        match(ValuescriptParser::BOOLEAN_OR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonoperatorContext ------------------------------------------------------------------

ValuescriptParser::ComparisonoperatorContext::ComparisonoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::ComparisonoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleComparisonoperator;
}

void ValuescriptParser::ComparisonoperatorContext::copyFrom(ComparisonoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ComploeContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ComploeContext::LESS_OR_EQUAL() {
  return getToken(ValuescriptParser::LESS_OR_EQUAL, 0);
}

ValuescriptParser::ComploeContext::ComploeContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ComploeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitComploe(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompeqlContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::CompeqlContext::EQUALITY() {
  return getToken(ValuescriptParser::EQUALITY, 0);
}

ValuescriptParser::CompeqlContext::CompeqlContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::CompeqlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCompeql(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompnonContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::CompnonContext::NON_EQUALITY() {
  return getToken(ValuescriptParser::NON_EQUALITY, 0);
}

ValuescriptParser::CompnonContext::CompnonContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::CompnonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCompnon(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompgoeContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::CompgoeContext::GREATER_OR_EQUAL() {
  return getToken(ValuescriptParser::GREATER_OR_EQUAL, 0);
}

ValuescriptParser::CompgoeContext::CompgoeContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::CompgoeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCompgoe(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComplssContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ComplssContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::ComplssContext::ComplssContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ComplssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitComplss(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompgreContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::CompgreContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::CompgreContext::CompgreContext(ComparisonoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::CompgreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitCompgre(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::ComparisonoperatorContext* ValuescriptParser::comparisonoperator() {
  ComparisonoperatorContext *_localctx = _tracker.createInstance<ComparisonoperatorContext>(_ctx, getState());
  enterRule(_localctx, 36, ValuescriptParser::RuleComparisonoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(338);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompeqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(332);
        match(ValuescriptParser::EQUALITY);
        break;
      }

      case ValuescriptParser::NON_EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompnonContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(333);
        match(ValuescriptParser::NON_EQUALITY);
        break;
      }

      case ValuescriptParser::GREATER_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgoeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(334);
        match(ValuescriptParser::GREATER_OR_EQUAL);
        break;
      }

      case ValuescriptParser::LESS_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComploeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(335);
        match(ValuescriptParser::LESS_OR_EQUAL);
        break;
      }

      case ValuescriptParser::OPEN_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComplssContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(336);
        match(ValuescriptParser::OPEN_ANGLE_BRACKET);
        break;
      }

      case ValuescriptParser::CLOSED_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgreContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(337);
        match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveoperatorContext ------------------------------------------------------------------

ValuescriptParser::AdditiveoperatorContext::AdditiveoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::AdditiveoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleAdditiveoperator;
}

void ValuescriptParser::AdditiveoperatorContext::copyFrom(AdditiveoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MinusContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::MinusContext::SUBTRACTION() {
  return getToken(ValuescriptParser::SUBTRACTION, 0);
}

ValuescriptParser::MinusContext::MinusContext(AdditiveoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::MinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::PlusContext::ADDITION() {
  return getToken(ValuescriptParser::ADDITION, 0);
}

ValuescriptParser::PlusContext::PlusContext(AdditiveoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::AdditiveoperatorContext* ValuescriptParser::additiveoperator() {
  AdditiveoperatorContext *_localctx = _tracker.createInstance<AdditiveoperatorContext>(_ctx, getState());
  enterRule(_localctx, 38, ValuescriptParser::RuleAdditiveoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(342);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ADDITION: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(340);
        match(ValuescriptParser::ADDITION);
        break;
      }

      case ValuescriptParser::SUBTRACTION: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(341);
        match(ValuescriptParser::SUBTRACTION);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeoperatorContext ------------------------------------------------------------------

ValuescriptParser::MultiplicativeoperatorContext::MultiplicativeoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::MultiplicativeoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleMultiplicativeoperator;
}

void ValuescriptParser::MultiplicativeoperatorContext::copyFrom(MultiplicativeoperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TimesContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TimesContext::MULTIPLICATION() {
  return getToken(ValuescriptParser::MULTIPLICATION, 0);
}

ValuescriptParser::TimesContext::TimesContext(MultiplicativeoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TimesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTimes(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivideContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::DivideContext::DIVISION() {
  return getToken(ValuescriptParser::DIVISION, 0);
}

ValuescriptParser::DivideContext::DivideContext(MultiplicativeoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::DivideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitDivide(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModuloContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ModuloContext::MODULUS() {
  return getToken(ValuescriptParser::MODULUS, 0);
}

ValuescriptParser::ModuloContext::ModuloContext(MultiplicativeoperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ModuloContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitModulo(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::MultiplicativeoperatorContext* ValuescriptParser::multiplicativeoperator() {
  MultiplicativeoperatorContext *_localctx = _tracker.createInstance<MultiplicativeoperatorContext>(_ctx, getState());
  enterRule(_localctx, 40, ValuescriptParser::RuleMultiplicativeoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(347);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::MULTIPLICATION: {
        _localctx = _tracker.createInstance<ValuescriptParser::TimesContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(344);
        match(ValuescriptParser::MULTIPLICATION);
        break;
      }

      case ValuescriptParser::DIVISION: {
        _localctx = _tracker.createInstance<ValuescriptParser::DivideContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(345);
        match(ValuescriptParser::DIVISION);
        break;
      }

      case ValuescriptParser::MODULUS: {
        _localctx = _tracker.createInstance<ValuescriptParser::ModuloContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(346);
        match(ValuescriptParser::MODULUS);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotoperatorContext ------------------------------------------------------------------

ValuescriptParser::NotoperatorContext::NotoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::NotoperatorContext::EXCLAMATION_POINT() {
  return getToken(ValuescriptParser::EXCLAMATION_POINT, 0);
}


size_t ValuescriptParser::NotoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleNotoperator;
}


std::any ValuescriptParser::NotoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitNotoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::NotoperatorContext* ValuescriptParser::notoperator() {
  NotoperatorContext *_localctx = _tracker.createInstance<NotoperatorContext>(_ctx, getState());
  enterRule(_localctx, 42, ValuescriptParser::RuleNotoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    match(ValuescriptParser::EXCLAMATION_POINT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncrementaloperatorContext ------------------------------------------------------------------

ValuescriptParser::IncrementaloperatorContext::IncrementaloperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::IncrementaloperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleIncrementaloperator;
}

void ValuescriptParser::IncrementaloperatorContext::copyFrom(IncrementaloperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PlusplusContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::PlusplusContext::INCREMENT() {
  return getToken(ValuescriptParser::INCREMENT, 0);
}

ValuescriptParser::PlusplusContext::PlusplusContext(IncrementaloperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::PlusplusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitPlusplus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusminusContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::MinusminusContext::DECREMENT() {
  return getToken(ValuescriptParser::DECREMENT, 0);
}

ValuescriptParser::MinusminusContext::MinusminusContext(IncrementaloperatorContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::MinusminusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitMinusminus(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::IncrementaloperatorContext* ValuescriptParser::incrementaloperator() {
  IncrementaloperatorContext *_localctx = _tracker.createInstance<IncrementaloperatorContext>(_ctx, getState());
  enterRule(_localctx, 44, ValuescriptParser::RuleIncrementaloperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::INCREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusplusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(351);
        match(ValuescriptParser::INCREMENT);
        break;
      }

      case ValuescriptParser::DECREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusminusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(352);
        match(ValuescriptParser::DECREMENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryexpressionContext ------------------------------------------------------------------

ValuescriptParser::PrimaryexpressionContext::PrimaryexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ValuescriptParser::PrimaryexpressionContext::getRuleIndex() const {
  return ValuescriptParser::RulePrimaryexpression;
}

void ValuescriptParser::PrimaryexpressionContext::copyFrom(PrimaryexpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::NumberContext::INTEGER_LITERAL() {
  return getToken(ValuescriptParser::INTEGER_LITERAL, 0);
}

ValuescriptParser::NumberContext::NumberContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::StringContext::STRING_LITERAL() {
  return getToken(ValuescriptParser::STRING_LITERAL, 0);
}

ValuescriptParser::StringContext::StringContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::IdentContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

ValuescriptParser::IdentContext::IdentContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TrueContext::TRUE() {
  return getToken(ValuescriptParser::TRUE, 0);
}

ValuescriptParser::TrueContext::TrueContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TrueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTrue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::FalseContext::FALSE() {
  return getToken(ValuescriptParser::FALSE, 0);
}

ValuescriptParser::FalseContext::FalseContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::FalseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitFalse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecimalContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::DecimalContext::FLOATING_LITERAL() {
  return getToken(ValuescriptParser::FLOATING_LITERAL, 0);
}

ValuescriptParser::DecimalContext::DecimalContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::DecimalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitDecimal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrderContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::OrderContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::OrderContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::OrderContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

ValuescriptParser::OrderContext::OrderContext(PrimaryexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::OrderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitOrder(this);
  else
    return visitor->visitChildren(this);
}
ValuescriptParser::PrimaryexpressionContext* ValuescriptParser::primaryexpression() {
  PrimaryexpressionContext *_localctx = _tracker.createInstance<PrimaryexpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, ValuescriptParser::RulePrimaryexpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<ValuescriptParser::IdentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(355);
        match(ValuescriptParser::IDENTIFIER);
        break;
      }

      case ValuescriptParser::FLOATING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::DecimalContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(356);
        match(ValuescriptParser::FLOATING_LITERAL);
        break;
      }

      case ValuescriptParser::INTEGER_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::NumberContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(357);
        match(ValuescriptParser::INTEGER_LITERAL);
        break;
      }

      case ValuescriptParser::TRUE: {
        _localctx = _tracker.createInstance<ValuescriptParser::TrueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(358);
        match(ValuescriptParser::TRUE);
        break;
      }

      case ValuescriptParser::FALSE: {
        _localctx = _tracker.createInstance<ValuescriptParser::FalseContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(359);
        match(ValuescriptParser::FALSE);
        break;
      }

      case ValuescriptParser::STRING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::StringContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(360);
        match(ValuescriptParser::STRING_LITERAL);
        break;
      }

      case ValuescriptParser::OPEN_PARENTHESES: {
        _localctx = _tracker.createInstance<ValuescriptParser::OrderContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(361);
        match(ValuescriptParser::OPEN_PARENTHESES);
        setState(362);
        expression(0);
        setState(363);
        match(ValuescriptParser::CLOSED_PARENTHESES);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ValuescriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 14: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ValuescriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 1);
    case 7: return precpred(_ctx, 11);
    case 8: return precpred(_ctx, 10);
    case 9: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void ValuescriptParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  valuescriptparserParserInitialize();
#else
  ::antlr4::internal::call_once(valuescriptparserParserOnceFlag, valuescriptparserParserInitialize);
#endif
}
