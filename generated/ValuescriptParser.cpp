
// Generated from ../ValuescriptParser.g4 by ANTLR 4.13.2


#include "ValuescriptParserListener.h"
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
      "expression", "assignmentoperator", "booleanoperator", "comparisonoperator", 
      "additiveoperator", "multiplicativeoperator", "notoperator", "incrementaloperator", 
      "primaryexpression"
    },
    std::vector<std::string>{
      "", "'static'", "'const'", "'var'", "'func'", "'class'", "'return'", 
      "'typenames'", "'import'", "'as'", "'int'", "'double'", "'bool'", 
      "'str'", "'void'", "'true'", "'false'", "'if'", "'else'", "'do'", 
      "'while'", "'for'", "'('", "')'", "'{'", "'}'", "'<'", "'>'", "'['", 
      "']'", "'.'", "','", "'@'", "':'", "';'", "'!'", "'->'", "'&'", "'&&'", 
      "'|'", "'||'", "'^'", "'+'", "'-'", "'*'", "'/'", "'%'", "'++'", "'--'", 
      "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'=='", "'!='", "'>='", 
      "'<='"
    },
    std::vector<std::string>{
      "", "STATIC", "CONSTANT", "VARIABLE", "FUNCTION", "CLASS", "RETURN", 
      "TYPENAMES", "IMPORT", "AS", "INTEGER", "DOUBLE", "BOOLEAN", "STRING", 
      "VOID", "TRUE", "FALSE", "IF", "ELSE", "DO", "WHILE", "FOR", "OPEN_PARENTHESES", 
      "CLOSED_PARENTHESES", "OPEN_CURLY_BRACE", "CLOSED_CURLY_BRACE", "OPEN_ANGLE_BRACKET", 
      "CLOSED_ANGLE_BRACKET", "OPEN_SQUARE", "CLOSED_SQUARE", "PERIOD", 
      "COMMA", "AT_SYMBOL", "COLON", "SEMICOLON", "EXCLAMATION_POINT", "ARROW_OPERATOR", 
      "BITWISE_AND", "BOOLEAN_AND", "BITWISE_OR", "BOOLEAN_OR", "BITWISE_XOR", 
      "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULUS", 
      "INCREMENT", "DECREMENT", "ASSIGNMENT_GENERIC", "ASSIGNMENT_ADD", 
      "ASSIGNMENT_SUB", "ASSIGNMENT_MULTI", "ASSIGNMENT_DIV", "ASSIGNMENT_MOD", 
      "EQUALITY", "NON_EQUALITY", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "SINGLE_LINE_COMMENT", 
      "MULTI_LINE_COMMENT", "WHITESPACE", "INTEGER_LITERAL", "STRING_LITERAL", 
      "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,64,338,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,5,0,48,8,0,10,0,12,0,51,9,0,1,0,4,0,54,8,0,11,0,12,0,
  	55,1,0,1,0,1,1,1,1,1,1,1,1,3,1,64,8,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,84,8,2,1,3,5,3,87,8,3,10,
  	3,12,3,90,9,3,1,3,1,3,1,3,1,3,5,3,96,8,3,10,3,12,3,99,9,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,3,3,107,8,3,1,4,3,4,110,8,4,1,4,3,4,113,8,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,5,1,5,3,5,123,8,5,1,5,1,5,5,5,127,8,5,10,5,12,5,130,9,5,1,
  	5,1,5,1,6,3,6,135,8,6,1,6,3,6,138,8,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,7,5,7,149,8,7,10,7,12,7,152,9,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,5,8,164,8,8,10,8,12,8,167,9,8,1,8,1,8,3,8,171,8,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,3,9,181,8,9,3,9,183,8,9,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,5,12,203,
  	8,12,10,12,12,12,206,9,12,1,12,1,12,1,12,1,12,1,12,1,12,5,12,214,8,12,
  	10,12,12,12,217,9,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,3,12,230,8,12,1,13,1,13,4,13,234,8,13,11,13,12,13,235,1,13,1,13,
  	1,13,3,13,241,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,
  	252,8,14,10,14,12,14,255,9,14,3,14,257,8,14,1,14,3,14,260,8,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,290,
  	8,14,10,14,12,14,293,9,14,3,14,295,8,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,5,14,305,8,14,10,14,12,14,308,9,14,1,15,1,15,1,16,1,16,1,17,
  	1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,336,8,22,1,22,0,1,28,23,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,8,2,0,1,1,
  	3,3,1,0,1,3,1,0,49,54,2,0,38,38,40,40,2,0,26,27,55,58,1,0,42,43,1,0,44,
  	46,1,0,47,48,369,0,49,1,0,0,0,2,59,1,0,0,0,4,83,1,0,0,0,6,106,1,0,0,0,
  	8,109,1,0,0,0,10,120,1,0,0,0,12,134,1,0,0,0,14,142,1,0,0,0,16,170,1,0,
  	0,0,18,172,1,0,0,0,20,184,1,0,0,0,22,190,1,0,0,0,24,229,1,0,0,0,26,240,
  	1,0,0,0,28,259,1,0,0,0,30,309,1,0,0,0,32,311,1,0,0,0,34,313,1,0,0,0,36,
  	315,1,0,0,0,38,317,1,0,0,0,40,319,1,0,0,0,42,321,1,0,0,0,44,335,1,0,0,
  	0,46,48,3,2,1,0,47,46,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,
  	0,50,53,1,0,0,0,51,49,1,0,0,0,52,54,3,4,2,0,53,52,1,0,0,0,54,55,1,0,0,
  	0,55,53,1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,57,58,5,0,0,1,58,1,1,0,0,
  	0,59,60,5,8,0,0,60,63,5,64,0,0,61,62,5,9,0,0,62,64,5,64,0,0,63,61,1,0,
  	0,0,63,64,1,0,0,0,64,65,1,0,0,0,65,66,5,34,0,0,66,3,1,0,0,0,67,68,3,6,
  	3,0,68,69,5,34,0,0,69,84,1,0,0,0,70,84,3,8,4,0,71,84,3,12,6,0,72,84,3,
  	18,9,0,73,84,3,20,10,0,74,84,3,22,11,0,75,84,3,24,12,0,76,77,5,6,0,0,
  	77,78,3,28,14,0,78,79,5,34,0,0,79,84,1,0,0,0,80,81,3,28,14,0,81,82,5,
  	34,0,0,82,84,1,0,0,0,83,67,1,0,0,0,83,70,1,0,0,0,83,71,1,0,0,0,83,72,
  	1,0,0,0,83,73,1,0,0,0,83,74,1,0,0,0,83,75,1,0,0,0,83,76,1,0,0,0,83,80,
  	1,0,0,0,84,5,1,0,0,0,85,87,7,0,0,0,86,85,1,0,0,0,87,90,1,0,0,0,88,86,
  	1,0,0,0,88,89,1,0,0,0,89,91,1,0,0,0,90,88,1,0,0,0,91,92,5,64,0,0,92,93,
  	5,36,0,0,93,107,3,16,8,0,94,96,7,1,0,0,95,94,1,0,0,0,96,99,1,0,0,0,97,
  	95,1,0,0,0,97,98,1,0,0,0,98,100,1,0,0,0,99,97,1,0,0,0,100,101,5,64,0,
  	0,101,102,5,36,0,0,102,103,3,16,8,0,103,104,5,49,0,0,104,105,3,28,14,
  	0,105,107,1,0,0,0,106,88,1,0,0,0,106,97,1,0,0,0,107,7,1,0,0,0,108,110,
  	3,14,7,0,109,108,1,0,0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,113,5,4,
  	0,0,112,111,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,115,5,64,0,0,
  	115,116,3,10,5,0,116,117,5,36,0,0,117,118,3,16,8,0,118,119,3,26,13,0,
  	119,9,1,0,0,0,120,122,5,22,0,0,121,123,3,6,3,0,122,121,1,0,0,0,122,123,
  	1,0,0,0,123,128,1,0,0,0,124,125,5,31,0,0,125,127,3,6,3,0,126,124,1,0,
  	0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,131,1,0,0,0,130,
  	128,1,0,0,0,131,132,5,23,0,0,132,11,1,0,0,0,133,135,3,14,7,0,134,133,
  	1,0,0,0,134,135,1,0,0,0,135,137,1,0,0,0,136,138,5,5,0,0,137,136,1,0,0,
  	0,137,138,1,0,0,0,138,139,1,0,0,0,139,140,5,64,0,0,140,141,3,26,13,0,
  	141,13,1,0,0,0,142,143,5,32,0,0,143,144,5,7,0,0,144,145,5,33,0,0,145,
  	150,5,64,0,0,146,147,5,31,0,0,147,149,5,64,0,0,148,146,1,0,0,0,149,152,
  	1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,15,1,0,0,0,152,150,1,0,0,
  	0,153,171,5,10,0,0,154,171,5,11,0,0,155,171,5,13,0,0,156,171,5,12,0,0,
  	157,171,5,64,0,0,158,159,5,64,0,0,159,160,5,26,0,0,160,165,3,16,8,0,161,
  	162,5,31,0,0,162,164,3,16,8,0,163,161,1,0,0,0,164,167,1,0,0,0,165,163,
  	1,0,0,0,165,166,1,0,0,0,166,168,1,0,0,0,167,165,1,0,0,0,168,169,5,27,
  	0,0,169,171,1,0,0,0,170,153,1,0,0,0,170,154,1,0,0,0,170,155,1,0,0,0,170,
  	156,1,0,0,0,170,157,1,0,0,0,170,158,1,0,0,0,171,17,1,0,0,0,172,173,5,
  	17,0,0,173,174,5,22,0,0,174,175,3,28,14,0,175,176,5,23,0,0,176,182,3,
  	26,13,0,177,180,5,18,0,0,178,181,3,26,13,0,179,181,3,18,9,0,180,178,1,
  	0,0,0,180,179,1,0,0,0,181,183,1,0,0,0,182,177,1,0,0,0,182,183,1,0,0,0,
  	183,19,1,0,0,0,184,185,5,20,0,0,185,186,5,22,0,0,186,187,3,28,14,0,187,
  	188,5,23,0,0,188,189,3,26,13,0,189,21,1,0,0,0,190,191,5,19,0,0,191,192,
  	3,26,13,0,192,193,5,20,0,0,193,194,5,22,0,0,194,195,3,28,14,0,195,196,
  	5,23,0,0,196,23,1,0,0,0,197,198,5,21,0,0,198,199,5,22,0,0,199,204,3,6,
  	3,0,200,201,5,31,0,0,201,203,3,6,3,0,202,200,1,0,0,0,203,206,1,0,0,0,
  	204,202,1,0,0,0,204,205,1,0,0,0,205,207,1,0,0,0,206,204,1,0,0,0,207,208,
  	5,34,0,0,208,209,3,28,14,0,209,210,5,34,0,0,210,215,3,28,14,0,211,212,
  	5,31,0,0,212,214,3,28,14,0,213,211,1,0,0,0,214,217,1,0,0,0,215,213,1,
  	0,0,0,215,216,1,0,0,0,216,218,1,0,0,0,217,215,1,0,0,0,218,219,5,23,0,
  	0,219,220,3,26,13,0,220,230,1,0,0,0,221,222,5,21,0,0,222,223,5,22,0,0,
  	223,224,3,6,3,0,224,225,5,33,0,0,225,226,3,28,14,0,226,227,5,23,0,0,227,
  	228,3,26,13,0,228,230,1,0,0,0,229,197,1,0,0,0,229,221,1,0,0,0,230,25,
  	1,0,0,0,231,233,5,24,0,0,232,234,3,4,2,0,233,232,1,0,0,0,234,235,1,0,
  	0,0,235,233,1,0,0,0,235,236,1,0,0,0,236,237,1,0,0,0,237,238,5,25,0,0,
  	238,241,1,0,0,0,239,241,3,4,2,0,240,231,1,0,0,0,240,239,1,0,0,0,241,27,
  	1,0,0,0,242,243,6,14,-1,0,243,260,3,44,22,0,244,245,3,40,20,0,245,246,
  	3,28,14,7,246,260,1,0,0,0,247,256,5,24,0,0,248,253,3,28,14,0,249,250,
  	5,31,0,0,250,252,3,28,14,0,251,249,1,0,0,0,252,255,1,0,0,0,253,251,1,
  	0,0,0,253,254,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,0,256,248,1,0,0,0,
  	256,257,1,0,0,0,257,258,1,0,0,0,258,260,5,25,0,0,259,242,1,0,0,0,259,
  	244,1,0,0,0,259,247,1,0,0,0,260,306,1,0,0,0,261,262,10,11,0,0,262,263,
  	5,30,0,0,263,305,3,28,14,12,264,265,10,6,0,0,265,266,3,38,19,0,266,267,
  	3,28,14,7,267,305,1,0,0,0,268,269,10,5,0,0,269,270,3,36,18,0,270,271,
  	3,28,14,6,271,305,1,0,0,0,272,273,10,4,0,0,273,274,3,34,17,0,274,275,
  	3,28,14,5,275,305,1,0,0,0,276,277,10,3,0,0,277,278,3,32,16,0,278,279,
  	3,28,14,4,279,305,1,0,0,0,280,281,10,1,0,0,281,282,3,30,15,0,282,283,
  	3,28,14,2,283,305,1,0,0,0,284,285,10,10,0,0,285,294,5,22,0,0,286,291,
  	3,28,14,0,287,288,5,31,0,0,288,290,3,28,14,0,289,287,1,0,0,0,290,293,
  	1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,
  	0,294,286,1,0,0,0,294,295,1,0,0,0,295,296,1,0,0,0,296,305,5,23,0,0,297,
  	298,10,9,0,0,298,299,5,28,0,0,299,300,3,28,14,0,300,301,5,29,0,0,301,
  	305,1,0,0,0,302,303,10,8,0,0,303,305,3,42,21,0,304,261,1,0,0,0,304,264,
  	1,0,0,0,304,268,1,0,0,0,304,272,1,0,0,0,304,276,1,0,0,0,304,280,1,0,0,
  	0,304,284,1,0,0,0,304,297,1,0,0,0,304,302,1,0,0,0,305,308,1,0,0,0,306,
  	304,1,0,0,0,306,307,1,0,0,0,307,29,1,0,0,0,308,306,1,0,0,0,309,310,7,
  	2,0,0,310,31,1,0,0,0,311,312,7,3,0,0,312,33,1,0,0,0,313,314,7,4,0,0,314,
  	35,1,0,0,0,315,316,7,5,0,0,316,37,1,0,0,0,317,318,7,6,0,0,318,39,1,0,
  	0,0,319,320,5,35,0,0,320,41,1,0,0,0,321,322,7,7,0,0,322,43,1,0,0,0,323,
  	336,5,64,0,0,324,325,5,62,0,0,325,326,5,30,0,0,326,336,5,62,0,0,327,336,
  	5,62,0,0,328,336,5,15,0,0,329,336,5,16,0,0,330,336,5,63,0,0,331,332,5,
  	22,0,0,332,333,3,28,14,0,333,334,5,23,0,0,334,336,1,0,0,0,335,323,1,0,
  	0,0,335,324,1,0,0,0,335,327,1,0,0,0,335,328,1,0,0,0,335,329,1,0,0,0,335,
  	330,1,0,0,0,335,331,1,0,0,0,336,45,1,0,0,0,31,49,55,63,83,88,97,106,109,
  	112,122,128,134,137,150,165,170,180,182,204,215,229,235,240,253,256,259,
  	291,294,304,306,335
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

void ValuescriptParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void ValuescriptParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::IMPORT) {
      setState(46);
      extra();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(52);
      statement();
      setState(55); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -2305842989873905601) != 0));
    setState(57);
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

void ValuescriptParser::ExtraContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtra(this);
}

void ValuescriptParser::ExtraContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtra(this);
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
    setState(59);
    match(ValuescriptParser::IMPORT);
    setState(60);
    match(ValuescriptParser::IDENTIFIER);
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::AS) {
      setState(61);
      match(ValuescriptParser::AS);
      setState(62);
      match(ValuescriptParser::IDENTIFIER);
    }
    setState(65);
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

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::StatementContext::variabledeclaration() {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::FunctiondeclarationContext* ValuescriptParser::StatementContext::functiondeclaration() {
  return getRuleContext<ValuescriptParser::FunctiondeclarationContext>(0);
}

ValuescriptParser::ClassdeclarationContext* ValuescriptParser::StatementContext::classdeclaration() {
  return getRuleContext<ValuescriptParser::ClassdeclarationContext>(0);
}

ValuescriptParser::IfstatementContext* ValuescriptParser::StatementContext::ifstatement() {
  return getRuleContext<ValuescriptParser::IfstatementContext>(0);
}

ValuescriptParser::WhilestatementContext* ValuescriptParser::StatementContext::whilestatement() {
  return getRuleContext<ValuescriptParser::WhilestatementContext>(0);
}

ValuescriptParser::DostatementContext* ValuescriptParser::StatementContext::dostatement() {
  return getRuleContext<ValuescriptParser::DostatementContext>(0);
}

ValuescriptParser::ForstatementContext* ValuescriptParser::StatementContext::forstatement() {
  return getRuleContext<ValuescriptParser::ForstatementContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementContext::RETURN() {
  return getToken(ValuescriptParser::RETURN, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}


size_t ValuescriptParser::StatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleStatement;
}

void ValuescriptParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ValuescriptParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any ValuescriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::StatementContext* ValuescriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ValuescriptParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      variabledeclaration();
      setState(68);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(70);
      functiondeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(71);
      classdeclaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(72);
      ifstatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(73);
      whilestatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(74);
      dostatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(75);
      forstatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(76);
      match(ValuescriptParser::RETURN);
      setState(77);
      expression(0);
      setState(78);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(80);
      expression(0);
      setState(81);
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

void ValuescriptParser::VariabledeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariabledeclaration(this);
}

void ValuescriptParser::VariabledeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariabledeclaration(this);
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
    setState(106);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::STATIC

      || _la == ValuescriptParser::VARIABLE) {
        setState(85);
        _la = _input->LA(1);
        if (!(_la == ValuescriptParser::STATIC

        || _la == ValuescriptParser::VARIABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(91);
      match(ValuescriptParser::IDENTIFIER);
      setState(92);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(93);
      typenameexpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 14) != 0)) {
        setState(94);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 14) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(99);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(100);
      match(ValuescriptParser::IDENTIFIER);
      setState(101);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(102);
      typenameexpression();
      setState(103);
      match(ValuescriptParser::ASSIGNMENT_GENERIC);
      setState(104);
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

void ValuescriptParser::FunctiondeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctiondeclaration(this);
}

void ValuescriptParser::FunctiondeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctiondeclaration(this);
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
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::AT_SYMBOL) {
      setState(108);
      templatedeclaration();
    }
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::FUNCTION) {
      setState(111);
      match(ValuescriptParser::FUNCTION);
    }
    setState(114);
    match(ValuescriptParser::IDENTIFIER);
    setState(115);
    functionparameters();
    setState(116);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(117);
    typenameexpression();
    setState(118);
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

void ValuescriptParser::FunctionparametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionparameters(this);
}

void ValuescriptParser::FunctionparametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionparameters(this);
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
    setState(120);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9223372036854775801) != 0)) {
      setState(121);
      variabledeclaration();
    }
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(124);
      match(ValuescriptParser::COMMA);
      setState(125);
      variabledeclaration();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
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

void ValuescriptParser::ClassdeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassdeclaration(this);
}

void ValuescriptParser::ClassdeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassdeclaration(this);
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
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::AT_SYMBOL) {
      setState(133);
      templatedeclaration();
    }
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::CLASS) {
      setState(136);
      match(ValuescriptParser::CLASS);
    }
    setState(139);
    match(ValuescriptParser::IDENTIFIER);
    setState(140);
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

tree::TerminalNode* ValuescriptParser::TemplatedeclarationContext::AT_SYMBOL() {
  return getToken(ValuescriptParser::AT_SYMBOL, 0);
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

void ValuescriptParser::TemplatedeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplatedeclaration(this);
}

void ValuescriptParser::TemplatedeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplatedeclaration(this);
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
    setState(142);
    match(ValuescriptParser::AT_SYMBOL);
    setState(143);
    match(ValuescriptParser::TYPENAMES);
    setState(144);
    match(ValuescriptParser::COLON);
    setState(145);
    match(ValuescriptParser::IDENTIFIER);
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(146);
      match(ValuescriptParser::COMMA);
      setState(147);
      match(ValuescriptParser::IDENTIFIER);
      setState(152);
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

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::INTEGER() {
  return getToken(ValuescriptParser::INTEGER, 0);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::DOUBLE() {
  return getToken(ValuescriptParser::DOUBLE, 0);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::STRING() {
  return getToken(ValuescriptParser::STRING, 0);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::BOOLEAN() {
  return getToken(ValuescriptParser::BOOLEAN, 0);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TypenameexpressionContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TypenameexpressionContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TypenameexpressionContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::TypenameexpressionContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}


size_t ValuescriptParser::TypenameexpressionContext::getRuleIndex() const {
  return ValuescriptParser::RuleTypenameexpression;
}

void ValuescriptParser::TypenameexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypenameexpression(this);
}

void ValuescriptParser::TypenameexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypenameexpression(this);
}


std::any ValuescriptParser::TypenameexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTypenameexpression(this);
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
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(153);
      match(ValuescriptParser::INTEGER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(154);
      match(ValuescriptParser::DOUBLE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(155);
      match(ValuescriptParser::STRING);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(156);
      match(ValuescriptParser::BOOLEAN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(157);
      match(ValuescriptParser::IDENTIFIER);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(158);
      match(ValuescriptParser::IDENTIFIER);
      setState(159);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(160);
      typenameexpression();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(161);
        match(ValuescriptParser::COMMA);
        setState(162);
        typenameexpression();
        setState(167);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(168);
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

void ValuescriptParser::IfstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfstatement(this);
}

void ValuescriptParser::IfstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfstatement(this);
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
    setState(172);
    match(ValuescriptParser::IF);
    setState(173);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(174);
    expression(0);
    setState(175);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(176);
    codeblock();
    setState(182);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(177);
      match(ValuescriptParser::ELSE);
      setState(180);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(178);
        codeblock();
        break;
      }

      case 2: {
        setState(179);
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

void ValuescriptParser::WhilestatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhilestatement(this);
}

void ValuescriptParser::WhilestatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhilestatement(this);
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
    setState(184);
    match(ValuescriptParser::WHILE);
    setState(185);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(186);
    expression(0);
    setState(187);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(188);
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

void ValuescriptParser::DostatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDostatement(this);
}

void ValuescriptParser::DostatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDostatement(this);
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
    setState(190);
    match(ValuescriptParser::DO);
    setState(191);
    codeblock();
    setState(192);
    match(ValuescriptParser::WHILE);
    setState(193);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(194);
    expression(0);
    setState(195);
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

tree::TerminalNode* ValuescriptParser::ForstatementContext::FOR() {
  return getToken(ValuescriptParser::FOR, 0);
}

tree::TerminalNode* ValuescriptParser::ForstatementContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

std::vector<ValuescriptParser::VariabledeclarationContext *> ValuescriptParser::ForstatementContext::variabledeclaration() {
  return getRuleContexts<ValuescriptParser::VariabledeclarationContext>();
}

ValuescriptParser::VariabledeclarationContext* ValuescriptParser::ForstatementContext::variabledeclaration(size_t i) {
  return getRuleContext<ValuescriptParser::VariabledeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ForstatementContext::SEMICOLON() {
  return getTokens(ValuescriptParser::SEMICOLON);
}

tree::TerminalNode* ValuescriptParser::ForstatementContext::SEMICOLON(size_t i) {
  return getToken(ValuescriptParser::SEMICOLON, i);
}

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::ForstatementContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::ForstatementContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::ForstatementContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

ValuescriptParser::CodeblockContext* ValuescriptParser::ForstatementContext::codeblock() {
  return getRuleContext<ValuescriptParser::CodeblockContext>(0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ForstatementContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::ForstatementContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

tree::TerminalNode* ValuescriptParser::ForstatementContext::COLON() {
  return getToken(ValuescriptParser::COLON, 0);
}


size_t ValuescriptParser::ForstatementContext::getRuleIndex() const {
  return ValuescriptParser::RuleForstatement;
}

void ValuescriptParser::ForstatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForstatement(this);
}

void ValuescriptParser::ForstatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForstatement(this);
}


std::any ValuescriptParser::ForstatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitForstatement(this);
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
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(197);
      match(ValuescriptParser::FOR);
      setState(198);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(199);
      variabledeclaration();
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(200);
        match(ValuescriptParser::COMMA);
        setState(201);
        variabledeclaration();
        setState(206);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(207);
      match(ValuescriptParser::SEMICOLON);
      setState(208);
      expression(0);
      setState(209);
      match(ValuescriptParser::SEMICOLON);
      setState(210);
      expression(0);
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(211);
        match(ValuescriptParser::COMMA);
        setState(212);
        expression(0);
        setState(217);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(218);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(219);
      codeblock();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(221);
      match(ValuescriptParser::FOR);
      setState(222);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(223);
      variabledeclaration();
      setState(224);
      match(ValuescriptParser::COLON);
      setState(225);
      expression(0);
      setState(226);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(227);
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

void ValuescriptParser::CodeblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeblock(this);
}

void ValuescriptParser::CodeblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeblock(this);
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
    setState(240);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(231);
      match(ValuescriptParser::OPEN_CURLY_BRACE);
      setState(233); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(232);
        statement();
        setState(235); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((((_la - 1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 1)) & -2305842989873905601) != 0));
      setState(237);
      match(ValuescriptParser::CLOSED_CURLY_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(239);
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

ValuescriptParser::PrimaryexpressionContext* ValuescriptParser::ExpressionContext::primaryexpression() {
  return getRuleContext<ValuescriptParser::PrimaryexpressionContext>(0);
}

ValuescriptParser::NotoperatorContext* ValuescriptParser::ExpressionContext::notoperator() {
  return getRuleContext<ValuescriptParser::NotoperatorContext>(0);
}

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::ExpressionContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::OPEN_CURLY_BRACE() {
  return getToken(ValuescriptParser::OPEN_CURLY_BRACE, 0);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::CLOSED_CURLY_BRACE() {
  return getToken(ValuescriptParser::CLOSED_CURLY_BRACE, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::ExpressionContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::PERIOD() {
  return getToken(ValuescriptParser::PERIOD, 0);
}

ValuescriptParser::MultiplicativeoperatorContext* ValuescriptParser::ExpressionContext::multiplicativeoperator() {
  return getRuleContext<ValuescriptParser::MultiplicativeoperatorContext>(0);
}

ValuescriptParser::AdditiveoperatorContext* ValuescriptParser::ExpressionContext::additiveoperator() {
  return getRuleContext<ValuescriptParser::AdditiveoperatorContext>(0);
}

ValuescriptParser::ComparisonoperatorContext* ValuescriptParser::ExpressionContext::comparisonoperator() {
  return getRuleContext<ValuescriptParser::ComparisonoperatorContext>(0);
}

ValuescriptParser::BooleanoperatorContext* ValuescriptParser::ExpressionContext::booleanoperator() {
  return getRuleContext<ValuescriptParser::BooleanoperatorContext>(0);
}

ValuescriptParser::AssignmentoperatorContext* ValuescriptParser::ExpressionContext::assignmentoperator() {
  return getRuleContext<ValuescriptParser::AssignmentoperatorContext>(0);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::OPEN_SQUARE() {
  return getToken(ValuescriptParser::OPEN_SQUARE, 0);
}

tree::TerminalNode* ValuescriptParser::ExpressionContext::CLOSED_SQUARE() {
  return getToken(ValuescriptParser::CLOSED_SQUARE, 0);
}

ValuescriptParser::IncrementaloperatorContext* ValuescriptParser::ExpressionContext::incrementaloperator() {
  return getRuleContext<ValuescriptParser::IncrementaloperatorContext>(0);
}


size_t ValuescriptParser::ExpressionContext::getRuleIndex() const {
  return ValuescriptParser::RuleExpression;
}

void ValuescriptParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ValuescriptParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any ValuescriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
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
    setState(259);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::TRUE:
      case ValuescriptParser::FALSE:
      case ValuescriptParser::OPEN_PARENTHESES:
      case ValuescriptParser::INTEGER_LITERAL:
      case ValuescriptParser::STRING_LITERAL:
      case ValuescriptParser::IDENTIFIER: {
        setState(243);
        primaryexpression();
        break;
      }

      case ValuescriptParser::EXCLAMATION_POINT: {
        setState(244);
        notoperator();
        setState(245);
        expression(7);
        break;
      }

      case ValuescriptParser::OPEN_CURLY_BRACE: {
        setState(247);
        match(ValuescriptParser::OPEN_CURLY_BRACE);
        setState(256);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 15) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 15)) & 985162419536515) != 0)) {
          setState(248);
          expression(0);
          setState(253);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ValuescriptParser::COMMA) {
            setState(249);
            match(ValuescriptParser::COMMA);
            setState(250);
            expression(0);
            setState(255);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(258);
        match(ValuescriptParser::CLOSED_CURLY_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(306);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(304);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(262);
          match(ValuescriptParser::PERIOD);
          setState(263);
          expression(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(264);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(265);
          multiplicativeoperator();
          setState(266);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(268);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(269);
          additiveoperator();
          setState(270);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(272);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(273);
          comparisonoperator();
          setState(274);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(276);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(277);
          booleanoperator();
          setState(278);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(280);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(281);
          assignmentoperator();
          setState(282);
          expression(2);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(284);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(285);
          match(ValuescriptParser::OPEN_PARENTHESES);
          setState(294);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 15) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 15)) & 985162419536515) != 0)) {
            setState(286);
            expression(0);
            setState(291);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == ValuescriptParser::COMMA) {
              setState(287);
              match(ValuescriptParser::COMMA);
              setState(288);
              expression(0);
              setState(293);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(296);
          match(ValuescriptParser::CLOSED_PARENTHESES);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(297);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(298);
          match(ValuescriptParser::OPEN_SQUARE);
          setState(299);
          expression(0);
          setState(300);
          match(ValuescriptParser::CLOSED_SQUARE);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(302);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(303);
          incrementaloperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_GENERIC() {
  return getToken(ValuescriptParser::ASSIGNMENT_GENERIC, 0);
}

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_ADD() {
  return getToken(ValuescriptParser::ASSIGNMENT_ADD, 0);
}

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_SUB() {
  return getToken(ValuescriptParser::ASSIGNMENT_SUB, 0);
}

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_MULTI() {
  return getToken(ValuescriptParser::ASSIGNMENT_MULTI, 0);
}

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_DIV() {
  return getToken(ValuescriptParser::ASSIGNMENT_DIV, 0);
}

tree::TerminalNode* ValuescriptParser::AssignmentoperatorContext::ASSIGNMENT_MOD() {
  return getToken(ValuescriptParser::ASSIGNMENT_MOD, 0);
}


size_t ValuescriptParser::AssignmentoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleAssignmentoperator;
}

void ValuescriptParser::AssignmentoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentoperator(this);
}

void ValuescriptParser::AssignmentoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentoperator(this);
}


std::any ValuescriptParser::AssignmentoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::AssignmentoperatorContext* ValuescriptParser::assignmentoperator() {
  AssignmentoperatorContext *_localctx = _tracker.createInstance<AssignmentoperatorContext>(_ctx, getState());
  enterRule(_localctx, 30, ValuescriptParser::RuleAssignmentoperator);
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
    setState(309);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35465847065542656) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

tree::TerminalNode* ValuescriptParser::BooleanoperatorContext::BOOLEAN_AND() {
  return getToken(ValuescriptParser::BOOLEAN_AND, 0);
}

tree::TerminalNode* ValuescriptParser::BooleanoperatorContext::BOOLEAN_OR() {
  return getToken(ValuescriptParser::BOOLEAN_OR, 0);
}


size_t ValuescriptParser::BooleanoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleBooleanoperator;
}

void ValuescriptParser::BooleanoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanoperator(this);
}

void ValuescriptParser::BooleanoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanoperator(this);
}


std::any ValuescriptParser::BooleanoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitBooleanoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::BooleanoperatorContext* ValuescriptParser::booleanoperator() {
  BooleanoperatorContext *_localctx = _tracker.createInstance<BooleanoperatorContext>(_ctx, getState());
  enterRule(_localctx, 32, ValuescriptParser::RuleBooleanoperator);
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
    setState(311);
    _la = _input->LA(1);
    if (!(_la == ValuescriptParser::BOOLEAN_AND

    || _la == ValuescriptParser::BOOLEAN_OR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::EQUALITY() {
  return getToken(ValuescriptParser::EQUALITY, 0);
}

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::NON_EQUALITY() {
  return getToken(ValuescriptParser::NON_EQUALITY, 0);
}

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::GREATER_OR_EQUAL() {
  return getToken(ValuescriptParser::GREATER_OR_EQUAL, 0);
}

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::LESS_OR_EQUAL() {
  return getToken(ValuescriptParser::LESS_OR_EQUAL, 0);
}

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

tree::TerminalNode* ValuescriptParser::ComparisonoperatorContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}


size_t ValuescriptParser::ComparisonoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleComparisonoperator;
}

void ValuescriptParser::ComparisonoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonoperator(this);
}

void ValuescriptParser::ComparisonoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonoperator(this);
}


std::any ValuescriptParser::ComparisonoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitComparisonoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::ComparisonoperatorContext* ValuescriptParser::comparisonoperator() {
  ComparisonoperatorContext *_localctx = _tracker.createInstance<ComparisonoperatorContext>(_ctx, getState());
  enterRule(_localctx, 34, ValuescriptParser::RuleComparisonoperator);
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
    setState(313);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540431955485786112) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

tree::TerminalNode* ValuescriptParser::AdditiveoperatorContext::ADDITION() {
  return getToken(ValuescriptParser::ADDITION, 0);
}

tree::TerminalNode* ValuescriptParser::AdditiveoperatorContext::SUBTRACTION() {
  return getToken(ValuescriptParser::SUBTRACTION, 0);
}


size_t ValuescriptParser::AdditiveoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleAdditiveoperator;
}

void ValuescriptParser::AdditiveoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveoperator(this);
}

void ValuescriptParser::AdditiveoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveoperator(this);
}


std::any ValuescriptParser::AdditiveoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::AdditiveoperatorContext* ValuescriptParser::additiveoperator() {
  AdditiveoperatorContext *_localctx = _tracker.createInstance<AdditiveoperatorContext>(_ctx, getState());
  enterRule(_localctx, 36, ValuescriptParser::RuleAdditiveoperator);
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
    setState(315);
    _la = _input->LA(1);
    if (!(_la == ValuescriptParser::ADDITION

    || _la == ValuescriptParser::SUBTRACTION)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

tree::TerminalNode* ValuescriptParser::MultiplicativeoperatorContext::MULTIPLICATION() {
  return getToken(ValuescriptParser::MULTIPLICATION, 0);
}

tree::TerminalNode* ValuescriptParser::MultiplicativeoperatorContext::DIVISION() {
  return getToken(ValuescriptParser::DIVISION, 0);
}

tree::TerminalNode* ValuescriptParser::MultiplicativeoperatorContext::MODULUS() {
  return getToken(ValuescriptParser::MODULUS, 0);
}


size_t ValuescriptParser::MultiplicativeoperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleMultiplicativeoperator;
}

void ValuescriptParser::MultiplicativeoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeoperator(this);
}

void ValuescriptParser::MultiplicativeoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeoperator(this);
}


std::any ValuescriptParser::MultiplicativeoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::MultiplicativeoperatorContext* ValuescriptParser::multiplicativeoperator() {
  MultiplicativeoperatorContext *_localctx = _tracker.createInstance<MultiplicativeoperatorContext>(_ctx, getState());
  enterRule(_localctx, 38, ValuescriptParser::RuleMultiplicativeoperator);
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
    setState(317);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 123145302310912) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

void ValuescriptParser::NotoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotoperator(this);
}

void ValuescriptParser::NotoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotoperator(this);
}


std::any ValuescriptParser::NotoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitNotoperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::NotoperatorContext* ValuescriptParser::notoperator() {
  NotoperatorContext *_localctx = _tracker.createInstance<NotoperatorContext>(_ctx, getState());
  enterRule(_localctx, 40, ValuescriptParser::RuleNotoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
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

tree::TerminalNode* ValuescriptParser::IncrementaloperatorContext::INCREMENT() {
  return getToken(ValuescriptParser::INCREMENT, 0);
}

tree::TerminalNode* ValuescriptParser::IncrementaloperatorContext::DECREMENT() {
  return getToken(ValuescriptParser::DECREMENT, 0);
}


size_t ValuescriptParser::IncrementaloperatorContext::getRuleIndex() const {
  return ValuescriptParser::RuleIncrementaloperator;
}

void ValuescriptParser::IncrementaloperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncrementaloperator(this);
}

void ValuescriptParser::IncrementaloperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncrementaloperator(this);
}


std::any ValuescriptParser::IncrementaloperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitIncrementaloperator(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::IncrementaloperatorContext* ValuescriptParser::incrementaloperator() {
  IncrementaloperatorContext *_localctx = _tracker.createInstance<IncrementaloperatorContext>(_ctx, getState());
  enterRule(_localctx, 42, ValuescriptParser::RuleIncrementaloperator);
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
    setState(321);
    _la = _input->LA(1);
    if (!(_la == ValuescriptParser::INCREMENT

    || _la == ValuescriptParser::DECREMENT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::PrimaryexpressionContext::INTEGER_LITERAL() {
  return getTokens(ValuescriptParser::INTEGER_LITERAL);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::INTEGER_LITERAL(size_t i) {
  return getToken(ValuescriptParser::INTEGER_LITERAL, i);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::PERIOD() {
  return getToken(ValuescriptParser::PERIOD, 0);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::TRUE() {
  return getToken(ValuescriptParser::TRUE, 0);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::FALSE() {
  return getToken(ValuescriptParser::FALSE, 0);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::STRING_LITERAL() {
  return getToken(ValuescriptParser::STRING_LITERAL, 0);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::PrimaryexpressionContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::PrimaryexpressionContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}


size_t ValuescriptParser::PrimaryexpressionContext::getRuleIndex() const {
  return ValuescriptParser::RulePrimaryexpression;
}

void ValuescriptParser::PrimaryexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryexpression(this);
}

void ValuescriptParser::PrimaryexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ValuescriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryexpression(this);
}


std::any ValuescriptParser::PrimaryexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitPrimaryexpression(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::PrimaryexpressionContext* ValuescriptParser::primaryexpression() {
  PrimaryexpressionContext *_localctx = _tracker.createInstance<PrimaryexpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, ValuescriptParser::RulePrimaryexpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      match(ValuescriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(324);
      match(ValuescriptParser::INTEGER_LITERAL);
      setState(325);
      match(ValuescriptParser::PERIOD);
      setState(326);
      match(ValuescriptParser::INTEGER_LITERAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(327);
      match(ValuescriptParser::INTEGER_LITERAL);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(328);
      match(ValuescriptParser::TRUE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(329);
      match(ValuescriptParser::FALSE);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(330);
      match(ValuescriptParser::STRING_LITERAL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(331);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(332);
      expression(0);
      setState(333);
      match(ValuescriptParser::CLOSED_PARENTHESES);
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
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 1);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);

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
