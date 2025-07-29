
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
      "functionparameters", "classdeclaration", "templateexpression", "templatedeclaration", 
      "typenameexpression", "ifstatement", "whilestatement", "dostatement", 
      "forstatement", "codeblock", "expression", "assignmentoperator", "binaryoperator", 
      "booleanoperator", "comparisonoperator", "additiveoperator", "multiplicativeoperator", 
      "notoperator", "incrementaloperator", "primaryexpression"
    },
    std::vector<std::string>{
      "", "'static'", "'const'", "'var'", "'func'", "'class'", "'return'", 
      "'typenames'", "'template'", "'import'", "'console_out'", "'int'", 
      "'double'", "'bool'", "'str'", "'void'", "'pair'", "'array'", "'list'", 
      "'map'", "'hash_list'", "'hash_map'", "'stack'", "'queue'", "'deque'", 
      "'prior_queue'", "'true'", "'false'", "'if'", "'else'", "'do'", "'while'", 
      "'for'", "'('", "')'", "'{'", "'}'", "'<'", "'>'", "'['", "']'", "'.'", 
      "','", "':'", "';'", "'!'", "'->'", "'&'", "'&&'", "'|'", "'||'", 
      "'^'", "'+'", "'-'", "'*'", "'/'", "'%'", "'++'", "'--'", "'='", "'+='", 
      "'-='", "'*='", "'/='", "'%='", "'=='", "'!='", "'>='", "'<='"
    },
    std::vector<std::string>{
      "", "STATIC", "CONSTANT", "VARIABLE", "FUNCTION", "CLASS", "RETURN", 
      "TYPENAMES", "TEMPLATE", "IMPORT", "DBGOUT", "INTEGER", "DOUBLE", 
      "BOOLEAN", "STRING", "VOID", "PAIR", "ARRAY", "ORD_LIST", "ORD_MAP", 
      "HASH_LIST", "HASH_MAP", "STACK", "QUEUE", "DEQUE", "PRIOR_QUE", "TRUE", 
      "FALSE", "IF", "ELSE", "DO", "WHILE", "FOR", "OPEN_PARENTHESES", "CLOSED_PARENTHESES", 
      "OPEN_CURLY_BRACE", "CLOSED_CURLY_BRACE", "OPEN_ANGLE_BRACKET", "CLOSED_ANGLE_BRACKET", 
      "OPEN_SQUARE", "CLOSED_SQUARE", "PERIOD", "COMMA", "COLON", "SEMICOLON", 
      "EXCLAMATION_POINT", "ARROW_OPERATOR", "BITWISE_AND", "BOOLEAN_AND", 
      "BITWISE_OR", "BOOLEAN_OR", "BITWISE_XOR", "ADDITION", "SUBTRACTION", 
      "MULTIPLICATION", "DIVISION", "MODULUS", "INCREMENT", "DECREMENT", 
      "ASSIGNMENT_GENERIC", "ASSIGNMENT_ADD", "ASSIGNMENT_SUB", "ASSIGNMENT_MULTI", 
      "ASSIGNMENT_DIV", "ASSIGNMENT_MOD", "EQUALITY", "NON_EQUALITY", "GREATER_OR_EQUAL", 
      "LESS_OR_EQUAL", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT", "WHITESPACE", 
      "FLOATING_LITERAL", "INTEGER_LITERAL", "STRING_LITERAL", "IDENTIFIER", 
      "LETTER", "ESCAPE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,77,455,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,5,0,52,8,0,10,0,12,0,55,9,0,1,0,
  	4,0,58,8,0,11,0,12,0,59,1,0,1,0,1,1,1,1,1,1,3,1,67,8,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,
  	89,8,2,1,2,3,2,92,8,2,1,3,5,3,95,8,3,10,3,12,3,98,9,3,1,3,1,3,1,3,1,3,
  	5,3,104,8,3,10,3,12,3,107,9,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,115,8,3,1,4,
  	3,4,118,8,4,1,4,3,4,121,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,3,5,131,8,
  	5,1,5,1,5,5,5,135,8,5,10,5,12,5,138,9,5,1,5,1,5,1,6,3,6,143,8,6,1,6,3,
  	6,146,8,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,5,7,156,8,7,10,7,12,7,159,9,
  	7,1,7,3,7,162,8,7,1,8,1,8,1,8,1,8,1,8,5,8,169,8,8,10,8,12,8,172,9,8,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,240,8,9,10,9,
  	12,9,243,9,9,1,9,1,9,3,9,247,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,3,10,257,8,10,3,10,259,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,5,13,279,8,13,10,13,
  	12,13,282,9,13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,290,8,13,10,13,12,13,
  	293,9,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,
  	306,8,13,1,14,1,14,4,14,310,8,14,11,14,12,14,311,1,14,1,14,1,14,3,14,
  	317,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,327,8,15,10,15,
  	12,15,330,9,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,341,
  	8,15,10,15,12,15,344,9,15,3,15,346,8,15,1,15,3,15,349,8,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,5,15,383,8,15,10,15,12,15,386,9,15,3,15,388,8,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,5,15,398,8,15,10,15,12,15,401,9,15,1,16,
  	1,16,1,16,1,16,1,16,1,16,3,16,409,8,16,1,17,1,17,1,17,3,17,414,8,17,1,
  	18,1,18,3,18,418,8,18,1,19,1,19,1,19,1,19,1,19,1,19,3,19,426,8,19,1,20,
  	1,20,3,20,430,8,20,1,21,1,21,1,21,3,21,435,8,21,1,22,1,22,1,23,1,23,3,
  	23,441,8,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,453,
  	8,24,1,24,0,1,30,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,0,2,2,0,1,1,3,3,1,0,1,3,518,0,53,1,0,0,0,2,63,1,
  	0,0,0,4,91,1,0,0,0,6,114,1,0,0,0,8,117,1,0,0,0,10,128,1,0,0,0,12,142,
  	1,0,0,0,14,150,1,0,0,0,16,163,1,0,0,0,18,246,1,0,0,0,20,248,1,0,0,0,22,
  	260,1,0,0,0,24,266,1,0,0,0,26,305,1,0,0,0,28,316,1,0,0,0,30,348,1,0,0,
  	0,32,408,1,0,0,0,34,413,1,0,0,0,36,417,1,0,0,0,38,425,1,0,0,0,40,429,
  	1,0,0,0,42,434,1,0,0,0,44,436,1,0,0,0,46,440,1,0,0,0,48,452,1,0,0,0,50,
  	52,3,2,1,0,51,50,1,0,0,0,52,55,1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,
  	57,1,0,0,0,55,53,1,0,0,0,56,58,3,4,2,0,57,56,1,0,0,0,58,59,1,0,0,0,59,
  	57,1,0,0,0,59,60,1,0,0,0,60,61,1,0,0,0,61,62,5,0,0,1,62,1,1,0,0,0,63,
  	64,5,9,0,0,64,66,5,75,0,0,65,67,5,44,0,0,66,65,1,0,0,0,66,67,1,0,0,0,
  	67,3,1,0,0,0,68,69,3,6,3,0,69,70,5,44,0,0,70,92,1,0,0,0,71,92,3,8,4,0,
  	72,92,3,12,6,0,73,92,3,20,10,0,74,92,3,22,11,0,75,92,3,24,12,0,76,92,
  	3,26,13,0,77,78,5,10,0,0,78,79,5,33,0,0,79,80,3,30,15,0,80,81,5,34,0,
  	0,81,82,5,44,0,0,82,92,1,0,0,0,83,84,3,30,15,0,84,85,5,44,0,0,85,92,1,
  	0,0,0,86,88,5,6,0,0,87,89,3,30,15,0,88,87,1,0,0,0,88,89,1,0,0,0,89,90,
  	1,0,0,0,90,92,5,44,0,0,91,68,1,0,0,0,91,71,1,0,0,0,91,72,1,0,0,0,91,73,
  	1,0,0,0,91,74,1,0,0,0,91,75,1,0,0,0,91,76,1,0,0,0,91,77,1,0,0,0,91,83,
  	1,0,0,0,91,86,1,0,0,0,92,5,1,0,0,0,93,95,7,0,0,0,94,93,1,0,0,0,95,98,
  	1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,99,1,0,0,0,98,96,1,0,0,0,99,100,
  	5,75,0,0,100,101,5,46,0,0,101,115,3,18,9,0,102,104,7,1,0,0,103,102,1,
  	0,0,0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,
  	107,105,1,0,0,0,108,109,5,75,0,0,109,110,5,46,0,0,110,111,3,18,9,0,111,
  	112,5,59,0,0,112,113,3,30,15,0,113,115,1,0,0,0,114,96,1,0,0,0,114,105,
  	1,0,0,0,115,7,1,0,0,0,116,118,3,16,8,0,117,116,1,0,0,0,117,118,1,0,0,
  	0,118,120,1,0,0,0,119,121,5,4,0,0,120,119,1,0,0,0,120,121,1,0,0,0,121,
  	122,1,0,0,0,122,123,5,75,0,0,123,124,3,10,5,0,124,125,5,46,0,0,125,126,
  	3,18,9,0,126,127,3,28,14,0,127,9,1,0,0,0,128,130,5,33,0,0,129,131,3,6,
  	3,0,130,129,1,0,0,0,130,131,1,0,0,0,131,136,1,0,0,0,132,133,5,42,0,0,
  	133,135,3,6,3,0,134,132,1,0,0,0,135,138,1,0,0,0,136,134,1,0,0,0,136,137,
  	1,0,0,0,137,139,1,0,0,0,138,136,1,0,0,0,139,140,5,34,0,0,140,11,1,0,0,
  	0,141,143,3,16,8,0,142,141,1,0,0,0,142,143,1,0,0,0,143,145,1,0,0,0,144,
  	146,5,5,0,0,145,144,1,0,0,0,145,146,1,0,0,0,146,147,1,0,0,0,147,148,5,
  	75,0,0,148,149,3,28,14,0,149,13,1,0,0,0,150,151,5,8,0,0,151,152,5,46,
  	0,0,152,157,3,18,9,0,153,154,5,42,0,0,154,156,3,18,9,0,155,153,1,0,0,
  	0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,158,161,1,0,0,0,159,
  	157,1,0,0,0,160,162,5,44,0,0,161,160,1,0,0,0,161,162,1,0,0,0,162,15,1,
  	0,0,0,163,164,5,7,0,0,164,165,5,43,0,0,165,170,5,75,0,0,166,167,5,42,
  	0,0,167,169,5,75,0,0,168,166,1,0,0,0,169,172,1,0,0,0,170,168,1,0,0,0,
  	170,171,1,0,0,0,171,17,1,0,0,0,172,170,1,0,0,0,173,247,5,11,0,0,174,247,
  	5,12,0,0,175,247,5,14,0,0,176,247,5,13,0,0,177,178,5,16,0,0,178,179,5,
  	37,0,0,179,180,3,18,9,0,180,181,5,42,0,0,181,182,3,18,9,0,182,183,5,38,
  	0,0,183,247,1,0,0,0,184,185,5,17,0,0,185,186,5,37,0,0,186,187,3,18,9,
  	0,187,188,5,38,0,0,188,247,1,0,0,0,189,190,5,18,0,0,190,191,5,37,0,0,
  	191,192,3,18,9,0,192,193,5,38,0,0,193,247,1,0,0,0,194,195,5,19,0,0,195,
  	196,5,37,0,0,196,197,3,18,9,0,197,198,5,42,0,0,198,199,3,18,9,0,199,200,
  	5,38,0,0,200,247,1,0,0,0,201,202,5,20,0,0,202,203,5,37,0,0,203,204,3,
  	18,9,0,204,205,5,38,0,0,205,247,1,0,0,0,206,207,5,21,0,0,207,208,5,37,
  	0,0,208,209,3,18,9,0,209,210,5,42,0,0,210,211,3,18,9,0,211,212,5,38,0,
  	0,212,247,1,0,0,0,213,214,5,22,0,0,214,215,5,37,0,0,215,216,3,18,9,0,
  	216,217,5,38,0,0,217,247,1,0,0,0,218,219,5,23,0,0,219,220,5,37,0,0,220,
  	221,3,18,9,0,221,222,5,38,0,0,222,247,1,0,0,0,223,224,5,24,0,0,224,225,
  	5,37,0,0,225,226,3,18,9,0,226,227,5,38,0,0,227,247,1,0,0,0,228,229,5,
  	25,0,0,229,230,5,37,0,0,230,231,3,18,9,0,231,232,5,38,0,0,232,247,1,0,
  	0,0,233,247,5,75,0,0,234,235,5,75,0,0,235,236,5,37,0,0,236,241,3,18,9,
  	0,237,238,5,42,0,0,238,240,3,18,9,0,239,237,1,0,0,0,240,243,1,0,0,0,241,
  	239,1,0,0,0,241,242,1,0,0,0,242,244,1,0,0,0,243,241,1,0,0,0,244,245,5,
  	38,0,0,245,247,1,0,0,0,246,173,1,0,0,0,246,174,1,0,0,0,246,175,1,0,0,
  	0,246,176,1,0,0,0,246,177,1,0,0,0,246,184,1,0,0,0,246,189,1,0,0,0,246,
  	194,1,0,0,0,246,201,1,0,0,0,246,206,1,0,0,0,246,213,1,0,0,0,246,218,1,
  	0,0,0,246,223,1,0,0,0,246,228,1,0,0,0,246,233,1,0,0,0,246,234,1,0,0,0,
  	247,19,1,0,0,0,248,249,5,28,0,0,249,250,5,33,0,0,250,251,3,30,15,0,251,
  	252,5,34,0,0,252,258,3,28,14,0,253,256,5,29,0,0,254,257,3,28,14,0,255,
  	257,3,20,10,0,256,254,1,0,0,0,256,255,1,0,0,0,257,259,1,0,0,0,258,253,
  	1,0,0,0,258,259,1,0,0,0,259,21,1,0,0,0,260,261,5,31,0,0,261,262,5,33,
  	0,0,262,263,3,30,15,0,263,264,5,34,0,0,264,265,3,28,14,0,265,23,1,0,0,
  	0,266,267,5,30,0,0,267,268,3,28,14,0,268,269,5,31,0,0,269,270,5,33,0,
  	0,270,271,3,30,15,0,271,272,5,34,0,0,272,25,1,0,0,0,273,274,5,32,0,0,
  	274,275,5,33,0,0,275,280,3,6,3,0,276,277,5,42,0,0,277,279,3,6,3,0,278,
  	276,1,0,0,0,279,282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,283,1,
  	0,0,0,282,280,1,0,0,0,283,284,5,44,0,0,284,285,3,30,15,0,285,286,5,44,
  	0,0,286,291,3,30,15,0,287,288,5,42,0,0,288,290,3,30,15,0,289,287,1,0,
  	0,0,290,293,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,294,1,0,0,0,293,
  	291,1,0,0,0,294,295,5,34,0,0,295,296,3,28,14,0,296,306,1,0,0,0,297,298,
  	5,32,0,0,298,299,5,33,0,0,299,300,3,6,3,0,300,301,5,43,0,0,301,302,3,
  	30,15,0,302,303,5,34,0,0,303,304,3,28,14,0,304,306,1,0,0,0,305,273,1,
  	0,0,0,305,297,1,0,0,0,306,27,1,0,0,0,307,309,5,35,0,0,308,310,3,4,2,0,
  	309,308,1,0,0,0,310,311,1,0,0,0,311,309,1,0,0,0,311,312,1,0,0,0,312,313,
  	1,0,0,0,313,314,5,36,0,0,314,317,1,0,0,0,315,317,3,4,2,0,316,307,1,0,
  	0,0,316,315,1,0,0,0,317,29,1,0,0,0,318,319,6,15,-1,0,319,349,3,48,24,
  	0,320,321,3,14,7,0,321,322,3,30,15,0,322,323,5,33,0,0,323,328,3,30,15,
  	0,324,325,5,42,0,0,325,327,3,30,15,0,326,324,1,0,0,0,327,330,1,0,0,0,
  	328,326,1,0,0,0,328,329,1,0,0,0,329,331,1,0,0,0,330,328,1,0,0,0,331,332,
  	5,34,0,0,332,349,1,0,0,0,333,334,3,44,22,0,334,335,3,30,15,8,335,349,
  	1,0,0,0,336,345,5,35,0,0,337,342,3,30,15,0,338,339,5,42,0,0,339,341,3,
  	30,15,0,340,338,1,0,0,0,341,344,1,0,0,0,342,340,1,0,0,0,342,343,1,0,0,
  	0,343,346,1,0,0,0,344,342,1,0,0,0,345,337,1,0,0,0,345,346,1,0,0,0,346,
  	347,1,0,0,0,347,349,5,36,0,0,348,318,1,0,0,0,348,320,1,0,0,0,348,333,
  	1,0,0,0,348,336,1,0,0,0,349,399,1,0,0,0,350,351,10,13,0,0,351,352,5,41,
  	0,0,352,398,3,30,15,14,353,354,10,7,0,0,354,355,3,42,21,0,355,356,3,30,
  	15,8,356,398,1,0,0,0,357,358,10,6,0,0,358,359,3,40,20,0,359,360,3,30,
  	15,7,360,398,1,0,0,0,361,362,10,5,0,0,362,363,3,38,19,0,363,364,3,30,
  	15,6,364,398,1,0,0,0,365,366,10,4,0,0,366,367,3,36,18,0,367,368,3,30,
  	15,5,368,398,1,0,0,0,369,370,10,3,0,0,370,371,3,34,17,0,371,372,3,30,
  	15,4,372,398,1,0,0,0,373,374,10,1,0,0,374,375,3,32,16,0,375,376,3,30,
  	15,2,376,398,1,0,0,0,377,378,10,12,0,0,378,387,5,33,0,0,379,384,3,30,
  	15,0,380,381,5,42,0,0,381,383,3,30,15,0,382,380,1,0,0,0,383,386,1,0,0,
  	0,384,382,1,0,0,0,384,385,1,0,0,0,385,388,1,0,0,0,386,384,1,0,0,0,387,
  	379,1,0,0,0,387,388,1,0,0,0,388,389,1,0,0,0,389,398,5,34,0,0,390,391,
  	10,10,0,0,391,392,5,39,0,0,392,393,3,30,15,0,393,394,5,40,0,0,394,398,
  	1,0,0,0,395,396,10,9,0,0,396,398,3,46,23,0,397,350,1,0,0,0,397,353,1,
  	0,0,0,397,357,1,0,0,0,397,361,1,0,0,0,397,365,1,0,0,0,397,369,1,0,0,0,
  	397,373,1,0,0,0,397,377,1,0,0,0,397,390,1,0,0,0,397,395,1,0,0,0,398,401,
  	1,0,0,0,399,397,1,0,0,0,399,400,1,0,0,0,400,31,1,0,0,0,401,399,1,0,0,
  	0,402,409,5,59,0,0,403,409,5,60,0,0,404,409,5,61,0,0,405,409,5,62,0,0,
  	406,409,5,63,0,0,407,409,5,64,0,0,408,402,1,0,0,0,408,403,1,0,0,0,408,
  	404,1,0,0,0,408,405,1,0,0,0,408,406,1,0,0,0,408,407,1,0,0,0,409,33,1,
  	0,0,0,410,414,5,47,0,0,411,414,5,49,0,0,412,414,5,51,0,0,413,410,1,0,
  	0,0,413,411,1,0,0,0,413,412,1,0,0,0,414,35,1,0,0,0,415,418,5,48,0,0,416,
  	418,5,50,0,0,417,415,1,0,0,0,417,416,1,0,0,0,418,37,1,0,0,0,419,426,5,
  	65,0,0,420,426,5,66,0,0,421,426,5,67,0,0,422,426,5,68,0,0,423,426,5,37,
  	0,0,424,426,5,38,0,0,425,419,1,0,0,0,425,420,1,0,0,0,425,421,1,0,0,0,
  	425,422,1,0,0,0,425,423,1,0,0,0,425,424,1,0,0,0,426,39,1,0,0,0,427,430,
  	5,52,0,0,428,430,5,53,0,0,429,427,1,0,0,0,429,428,1,0,0,0,430,41,1,0,
  	0,0,431,435,5,54,0,0,432,435,5,55,0,0,433,435,5,56,0,0,434,431,1,0,0,
  	0,434,432,1,0,0,0,434,433,1,0,0,0,435,43,1,0,0,0,436,437,5,45,0,0,437,
  	45,1,0,0,0,438,441,5,57,0,0,439,441,5,58,0,0,440,438,1,0,0,0,440,439,
  	1,0,0,0,441,47,1,0,0,0,442,453,5,75,0,0,443,453,5,72,0,0,444,453,5,73,
  	0,0,445,453,5,26,0,0,446,453,5,27,0,0,447,453,5,74,0,0,448,449,5,33,0,
  	0,449,450,3,30,15,0,450,451,5,34,0,0,451,453,1,0,0,0,452,442,1,0,0,0,
  	452,443,1,0,0,0,452,444,1,0,0,0,452,445,1,0,0,0,452,446,1,0,0,0,452,447,
  	1,0,0,0,452,448,1,0,0,0,453,49,1,0,0,0,42,53,59,66,88,91,96,105,114,117,
  	120,130,136,142,145,157,161,170,241,246,256,258,280,291,305,311,316,328,
  	342,345,348,384,387,397,399,408,413,417,425,429,434,440,452
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
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::IMPORT) {
      setState(50);
      extra();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(56);
      statement();
      setState(59); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35235307718142) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & 15) != 0));
    setState(61);
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

tree::TerminalNode* ValuescriptParser::ExtraContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ValuescriptParser::ExtraContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
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
    setState(63);
    match(ValuescriptParser::IMPORT);
    setState(64);
    match(ValuescriptParser::IDENTIFIER);
    setState(66);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::SEMICOLON) {
      setState(65);
      match(ValuescriptParser::SEMICOLON);
    }
   
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
//----------------- StatementprintContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::StatementprintContext::DBGOUT() {
  return getToken(ValuescriptParser::DBGOUT, 0);
}

tree::TerminalNode* ValuescriptParser::StatementprintContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementprintContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementprintContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::StatementprintContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::StatementprintContext::StatementprintContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementprintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementprint(this);
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
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementvardeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(68);
      variabledeclaration();
      setState(69);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementfuncdeclContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(71);
      functiondeclaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementclassdeclContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(72);
      classdeclaration();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementifContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(73);
      ifstatement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementwhileContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(74);
      whilestatement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementdoContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(75);
      dostatement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementforContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(76);
      forstatement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementprintContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(77);
      match(ValuescriptParser::DBGOUT);
      setState(78);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(79);
      expression(0);
      setState(80);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(81);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementexprContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(83);
      expression(0);
      setState(84);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementretContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(86);
      match(ValuescriptParser::RETURN);
      setState(88);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 35227523088640) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & 15) != 0)) {
        setState(87);
        expression(0);
      }
      setState(90);
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
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::STATIC

      || _la == ValuescriptParser::VARIABLE) {
        setState(93);
        _la = _input->LA(1);
        if (!(_la == ValuescriptParser::STATIC

        || _la == ValuescriptParser::VARIABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(99);
      match(ValuescriptParser::IDENTIFIER);
      setState(100);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(101);
      typenameexpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 14) != 0)) {
        setState(102);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 14) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(107);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(108);
      match(ValuescriptParser::IDENTIFIER);
      setState(109);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(110);
      typenameexpression();
      setState(111);
      match(ValuescriptParser::ASSIGNMENT_GENERIC);
      setState(112);
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
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(116);
      templatedeclaration();
    }
    setState(120);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::FUNCTION) {
      setState(119);
      match(ValuescriptParser::FUNCTION);
    }
    setState(122);
    match(ValuescriptParser::IDENTIFIER);
    setState(123);
    functionparameters();
    setState(124);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(125);
    typenameexpression();
    setState(126);
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
    setState(128);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(130);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14) != 0) || _la == ValuescriptParser::IDENTIFIER) {
      setState(129);
      variabledeclaration();
    }
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(132);
      match(ValuescriptParser::COMMA);
      setState(133);
      variabledeclaration();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
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
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(141);
      templatedeclaration();
    }
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::CLASS) {
      setState(144);
      match(ValuescriptParser::CLASS);
    }
    setState(147);
    match(ValuescriptParser::IDENTIFIER);
    setState(148);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateexpressionContext ------------------------------------------------------------------

ValuescriptParser::TemplateexpressionContext::TemplateexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ValuescriptParser::TemplateexpressionContext::TEMPLATE() {
  return getToken(ValuescriptParser::TEMPLATE, 0);
}

tree::TerminalNode* ValuescriptParser::TemplateexpressionContext::ARROW_OPERATOR() {
  return getToken(ValuescriptParser::ARROW_OPERATOR, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TemplateexpressionContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TemplateexpressionContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TemplateexpressionContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::TemplateexpressionContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

tree::TerminalNode* ValuescriptParser::TemplateexpressionContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}


size_t ValuescriptParser::TemplateexpressionContext::getRuleIndex() const {
  return ValuescriptParser::RuleTemplateexpression;
}


std::any ValuescriptParser::TemplateexpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTemplateexpression(this);
  else
    return visitor->visitChildren(this);
}

ValuescriptParser::TemplateexpressionContext* ValuescriptParser::templateexpression() {
  TemplateexpressionContext *_localctx = _tracker.createInstance<TemplateexpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, ValuescriptParser::RuleTemplateexpression);
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
    setState(150);
    match(ValuescriptParser::TEMPLATE);
    setState(151);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(152);
    typenameexpression();
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(153);
      match(ValuescriptParser::COMMA);
      setState(154);
      typenameexpression();
      setState(159);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::SEMICOLON) {
      setState(160);
      match(ValuescriptParser::SEMICOLON);
    }
   
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
  enterRule(_localctx, 16, ValuescriptParser::RuleTemplatedeclaration);
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
    setState(163);
    match(ValuescriptParser::TYPENAMES);
    setState(164);
    match(ValuescriptParser::COLON);
    setState(165);
    match(ValuescriptParser::IDENTIFIER);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(166);
      match(ValuescriptParser::COMMA);
      setState(167);
      match(ValuescriptParser::IDENTIFIER);
      setState(172);
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

//----------------- TyusetContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyusetContext::HASH_LIST() {
  return getToken(ValuescriptParser::HASH_LIST, 0);
}

tree::TerminalNode* ValuescriptParser::TyusetContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TyusetContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TyusetContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TyusetContext::TyusetContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyusetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyuset(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TydequeContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TydequeContext::DEQUE() {
  return getToken(ValuescriptParser::DEQUE, 0);
}

tree::TerminalNode* ValuescriptParser::TydequeContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TydequeContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TydequeContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TydequeContext::TydequeContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TydequeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTydeque(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TysetContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TysetContext::ORD_LIST() {
  return getToken(ValuescriptParser::ORD_LIST, 0);
}

tree::TerminalNode* ValuescriptParser::TysetContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TysetContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TysetContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TysetContext::TysetContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TysetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyset(this);
  else
    return visitor->visitChildren(this);
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
//----------------- TypriorContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TypriorContext::PRIOR_QUE() {
  return getToken(ValuescriptParser::PRIOR_QUE, 0);
}

tree::TerminalNode* ValuescriptParser::TypriorContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TypriorContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TypriorContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypriorContext::TypriorContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TypriorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyprior(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TymapContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TymapContext::ORD_MAP() {
  return getToken(ValuescriptParser::ORD_MAP, 0);
}

tree::TerminalNode* ValuescriptParser::TymapContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TymapContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TymapContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TymapContext::COMMA() {
  return getToken(ValuescriptParser::COMMA, 0);
}

tree::TerminalNode* ValuescriptParser::TymapContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TymapContext::TymapContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TymapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTymap(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TyarrayContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyarrayContext::ARRAY() {
  return getToken(ValuescriptParser::ARRAY, 0);
}

tree::TerminalNode* ValuescriptParser::TyarrayContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TyarrayContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TyarrayContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TyarrayContext::TyarrayContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyarrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyarray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypairContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TypairContext::PAIR() {
  return getToken(ValuescriptParser::PAIR, 0);
}

tree::TerminalNode* ValuescriptParser::TypairContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TypairContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TypairContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TypairContext::COMMA() {
  return getToken(ValuescriptParser::COMMA, 0);
}

tree::TerminalNode* ValuescriptParser::TypairContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypairContext::TypairContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TypairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTypair(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TyqueueContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyqueueContext::QUEUE() {
  return getToken(ValuescriptParser::QUEUE, 0);
}

tree::TerminalNode* ValuescriptParser::TyqueueContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TyqueueContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TyqueueContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TyqueueContext::TyqueueContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyqueueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyqueue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TystackContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TystackContext::STACK() {
  return getToken(ValuescriptParser::STACK, 0);
}

tree::TerminalNode* ValuescriptParser::TystackContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TystackContext::typenameexpression() {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::TystackContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TystackContext::TystackContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TystackContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTystack(this);
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
//----------------- TyumapContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::TyumapContext::HASH_MAP() {
  return getToken(ValuescriptParser::HASH_MAP, 0);
}

tree::TerminalNode* ValuescriptParser::TyumapContext::OPEN_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::OPEN_ANGLE_BRACKET, 0);
}

std::vector<ValuescriptParser::TypenameexpressionContext *> ValuescriptParser::TyumapContext::typenameexpression() {
  return getRuleContexts<ValuescriptParser::TypenameexpressionContext>();
}

ValuescriptParser::TypenameexpressionContext* ValuescriptParser::TyumapContext::typenameexpression(size_t i) {
  return getRuleContext<ValuescriptParser::TypenameexpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TyumapContext::COMMA() {
  return getToken(ValuescriptParser::COMMA, 0);
}

tree::TerminalNode* ValuescriptParser::TyumapContext::CLOSED_ANGLE_BRACKET() {
  return getToken(ValuescriptParser::CLOSED_ANGLE_BRACKET, 0);
}

ValuescriptParser::TyumapContext::TyumapContext(TypenameexpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyumapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyumap(this);
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
  enterRule(_localctx, 18, ValuescriptParser::RuleTypenameexpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyintegerContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(173);
      match(ValuescriptParser::INTEGER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::TydoubleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(174);
      match(ValuescriptParser::DOUBLE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValuescriptParser::TystringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(175);
      match(ValuescriptParser::STRING);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValuescriptParser::TybooleanContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(176);
      match(ValuescriptParser::BOOLEAN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValuescriptParser::TypairContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(177);
      match(ValuescriptParser::PAIR);
      setState(178);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(179);
      typenameexpression();
      setState(180);
      match(ValuescriptParser::COMMA);
      setState(181);
      typenameexpression();
      setState(182);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyarrayContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(184);
      match(ValuescriptParser::ARRAY);
      setState(185);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(186);
      typenameexpression();
      setState(187);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValuescriptParser::TysetContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(189);
      match(ValuescriptParser::ORD_LIST);
      setState(190);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(191);
      typenameexpression();
      setState(192);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ValuescriptParser::TymapContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(194);
      match(ValuescriptParser::ORD_MAP);
      setState(195);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(196);
      typenameexpression();
      setState(197);
      match(ValuescriptParser::COMMA);
      setState(198);
      typenameexpression();
      setState(199);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyusetContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(201);
      match(ValuescriptParser::HASH_LIST);
      setState(202);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(203);
      typenameexpression();
      setState(204);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyumapContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(206);
      match(ValuescriptParser::HASH_MAP);
      setState(207);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(208);
      typenameexpression();
      setState(209);
      match(ValuescriptParser::COMMA);
      setState(210);
      typenameexpression();
      setState(211);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<ValuescriptParser::TystackContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(213);
      match(ValuescriptParser::STACK);
      setState(214);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(215);
      typenameexpression();
      setState(216);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyqueueContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(218);
      match(ValuescriptParser::QUEUE);
      setState(219);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(220);
      typenameexpression();
      setState(221);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<ValuescriptParser::TydequeContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(223);
      match(ValuescriptParser::DEQUE);
      setState(224);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(225);
      typenameexpression();
      setState(226);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<ValuescriptParser::TypriorContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(228);
      match(ValuescriptParser::PRIOR_QUE);
      setState(229);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(230);
      typenameexpression();
      setState(231);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyidentContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(233);
      match(ValuescriptParser::IDENTIFIER);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<ValuescriptParser::TynestedContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(234);
      match(ValuescriptParser::IDENTIFIER);
      setState(235);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(236);
      typenameexpression();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(237);
        match(ValuescriptParser::COMMA);
        setState(238);
        typenameexpression();
        setState(243);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(244);
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
  enterRule(_localctx, 20, ValuescriptParser::RuleIfstatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(ValuescriptParser::IF);
    setState(249);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(250);
    expression(0);
    setState(251);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(252);
    codeblock();
    setState(258);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(253);
      match(ValuescriptParser::ELSE);
      setState(256);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(254);
        codeblock();
        break;
      }

      case 2: {
        setState(255);
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
  enterRule(_localctx, 22, ValuescriptParser::RuleWhilestatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(ValuescriptParser::WHILE);
    setState(261);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(262);
    expression(0);
    setState(263);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(264);
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
  enterRule(_localctx, 24, ValuescriptParser::RuleDostatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(ValuescriptParser::DO);
    setState(267);
    codeblock();
    setState(268);
    match(ValuescriptParser::WHILE);
    setState(269);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(270);
    expression(0);
    setState(271);
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
  enterRule(_localctx, 26, ValuescriptParser::RuleForstatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::RangeforContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(273);
      match(ValuescriptParser::FOR);
      setState(274);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(275);
      variabledeclaration();
      setState(280);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(276);
        match(ValuescriptParser::COMMA);
        setState(277);
        variabledeclaration();
        setState(282);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(283);
      match(ValuescriptParser::SEMICOLON);
      setState(284);
      expression(0);
      setState(285);
      match(ValuescriptParser::SEMICOLON);
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
      setState(294);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(295);
      codeblock();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::ItemforContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(297);
      match(ValuescriptParser::FOR);
      setState(298);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(299);
      variabledeclaration();
      setState(300);
      match(ValuescriptParser::COLON);
      setState(301);
      expression(0);
      setState(302);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(303);
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
  enterRule(_localctx, 28, ValuescriptParser::RuleCodeblock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(316);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(307);
      match(ValuescriptParser::OPEN_CURLY_BRACE);
      setState(309); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(308);
        statement();
        setState(311); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 35235307718142) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & 15) != 0));
      setState(313);
      match(ValuescriptParser::CLOSED_CURLY_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(315);
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
//----------------- TyparexprContext ------------------------------------------------------------------

ValuescriptParser::TemplateexpressionContext* ValuescriptParser::TyparexprContext::templateexpression() {
  return getRuleContext<ValuescriptParser::TemplateexpressionContext>(0);
}

std::vector<ValuescriptParser::ExpressionContext *> ValuescriptParser::TyparexprContext::expression() {
  return getRuleContexts<ValuescriptParser::ExpressionContext>();
}

ValuescriptParser::ExpressionContext* ValuescriptParser::TyparexprContext::expression(size_t i) {
  return getRuleContext<ValuescriptParser::ExpressionContext>(i);
}

tree::TerminalNode* ValuescriptParser::TyparexprContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::TyparexprContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

std::vector<tree::TerminalNode *> ValuescriptParser::TyparexprContext::COMMA() {
  return getTokens(ValuescriptParser::COMMA);
}

tree::TerminalNode* ValuescriptParser::TyparexprContext::COMMA(size_t i) {
  return getToken(ValuescriptParser::COMMA, i);
}

ValuescriptParser::TyparexprContext::TyparexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::TyparexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitTyparexpr(this);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, ValuescriptParser::RuleExpression, precedence);

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
    setState(348);
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

        setState(319);
        primaryexpression();
        break;
      }

      case ValuescriptParser::TEMPLATE: {
        _localctx = _tracker.createInstance<TyparexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(320);
        templateexpression();
        setState(321);
        expression(0);
        setState(322);
        match(ValuescriptParser::OPEN_PARENTHESES);
        setState(323);
        expression(0);
        setState(328);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ValuescriptParser::COMMA) {
          setState(324);
          match(ValuescriptParser::COMMA);
          setState(325);
          expression(0);
          setState(330);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(331);
        match(ValuescriptParser::CLOSED_PARENTHESES);
        break;
      }

      case ValuescriptParser::EXCLAMATION_POINT: {
        _localctx = _tracker.createInstance<NotexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(333);
        notoperator();
        setState(334);
        expression(8);
        break;
      }

      case ValuescriptParser::OPEN_CURLY_BRACE: {
        _localctx = _tracker.createInstance<ObjexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(336);
        match(ValuescriptParser::OPEN_CURLY_BRACE);
        setState(345);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 35227523088640) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & 15) != 0)) {
          setState(337);
          expression(0);
          setState(342);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ValuescriptParser::COMMA) {
            setState(338);
            match(ValuescriptParser::COMMA);
            setState(339);
            expression(0);
            setState(344);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(347);
        match(ValuescriptParser::CLOSED_CURLY_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(399);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(397);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MembexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(350);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(351);
          match(ValuescriptParser::PERIOD);
          setState(352);
          expression(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(353);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(354);
          multiplicativeoperator();
          setState(355);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(357);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(358);
          additiveoperator();
          setState(359);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(361);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(362);
          comparisonoperator();
          setState(363);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BoolexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(365);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(366);
          booleanoperator();
          setState(367);
          expression(5);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(369);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(370);
          binaryoperator();
          setState(371);
          expression(4);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AssignexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(373);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(374);
          assignmentoperator();
          setState(375);
          expression(2);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ParenexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(377);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(378);
          match(ValuescriptParser::OPEN_PARENTHESES);
          setState(387);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 35227523088640) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & 15) != 0)) {
            setState(379);
            expression(0);
            setState(384);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == ValuescriptParser::COMMA) {
              setState(380);
              match(ValuescriptParser::COMMA);
              setState(381);
              expression(0);
              setState(386);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(389);
          match(ValuescriptParser::CLOSED_PARENTHESES);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AccessexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(390);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(391);
          match(ValuescriptParser::OPEN_SQUARE);
          setState(392);
          expression(0);
          setState(393);
          match(ValuescriptParser::CLOSED_SQUARE);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<IncexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(395);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(396);
          incrementaloperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(401);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
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
  enterRule(_localctx, 32, ValuescriptParser::RuleAssignmentoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(408);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ASSIGNMENT_GENERIC: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsseqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(402);
        match(ValuescriptParser::ASSIGNMENT_GENERIC);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_ADD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssaddContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(403);
        match(ValuescriptParser::ASSIGNMENT_ADD);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_SUB: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsssubContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(404);
        match(ValuescriptParser::ASSIGNMENT_SUB);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MULTI: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmulContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(405);
        match(ValuescriptParser::ASSIGNMENT_MULTI);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_DIV: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssdivContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(406);
        match(ValuescriptParser::ASSIGNMENT_DIV);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MOD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmodContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(407);
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
  enterRule(_localctx, 34, ValuescriptParser::RuleBinaryoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(413);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BITWISE_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(410);
        match(ValuescriptParser::BITWISE_AND);
        break;
      }

      case ValuescriptParser::BITWISE_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(411);
        match(ValuescriptParser::BITWISE_OR);
        break;
      }

      case ValuescriptParser::BITWISE_XOR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitxorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(412);
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
  enterRule(_localctx, 36, ValuescriptParser::RuleBooleanoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(417);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BOOLEAN_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(415);
        match(ValuescriptParser::BOOLEAN_AND);
        break;
      }

      case ValuescriptParser::BOOLEAN_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(416);
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
  enterRule(_localctx, 38, ValuescriptParser::RuleComparisonoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(425);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompeqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(419);
        match(ValuescriptParser::EQUALITY);
        break;
      }

      case ValuescriptParser::NON_EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompnonContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(420);
        match(ValuescriptParser::NON_EQUALITY);
        break;
      }

      case ValuescriptParser::GREATER_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgoeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(421);
        match(ValuescriptParser::GREATER_OR_EQUAL);
        break;
      }

      case ValuescriptParser::LESS_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComploeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(422);
        match(ValuescriptParser::LESS_OR_EQUAL);
        break;
      }

      case ValuescriptParser::OPEN_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComplssContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(423);
        match(ValuescriptParser::OPEN_ANGLE_BRACKET);
        break;
      }

      case ValuescriptParser::CLOSED_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgreContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(424);
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
  enterRule(_localctx, 40, ValuescriptParser::RuleAdditiveoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(429);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ADDITION: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(427);
        match(ValuescriptParser::ADDITION);
        break;
      }

      case ValuescriptParser::SUBTRACTION: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(428);
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
  enterRule(_localctx, 42, ValuescriptParser::RuleMultiplicativeoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(434);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::MULTIPLICATION: {
        _localctx = _tracker.createInstance<ValuescriptParser::TimesContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(431);
        match(ValuescriptParser::MULTIPLICATION);
        break;
      }

      case ValuescriptParser::DIVISION: {
        _localctx = _tracker.createInstance<ValuescriptParser::DivideContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(432);
        match(ValuescriptParser::DIVISION);
        break;
      }

      case ValuescriptParser::MODULUS: {
        _localctx = _tracker.createInstance<ValuescriptParser::ModuloContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(433);
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
  enterRule(_localctx, 44, ValuescriptParser::RuleNotoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
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
  enterRule(_localctx, 46, ValuescriptParser::RuleIncrementaloperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::INCREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusplusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(438);
        match(ValuescriptParser::INCREMENT);
        break;
      }

      case ValuescriptParser::DECREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusminusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(439);
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
  enterRule(_localctx, 48, ValuescriptParser::RulePrimaryexpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<ValuescriptParser::IdentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(442);
        match(ValuescriptParser::IDENTIFIER);
        break;
      }

      case ValuescriptParser::FLOATING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::DecimalContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(443);
        match(ValuescriptParser::FLOATING_LITERAL);
        break;
      }

      case ValuescriptParser::INTEGER_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::NumberContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(444);
        match(ValuescriptParser::INTEGER_LITERAL);
        break;
      }

      case ValuescriptParser::TRUE: {
        _localctx = _tracker.createInstance<ValuescriptParser::TrueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(445);
        match(ValuescriptParser::TRUE);
        break;
      }

      case ValuescriptParser::FALSE: {
        _localctx = _tracker.createInstance<ValuescriptParser::FalseContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(446);
        match(ValuescriptParser::FALSE);
        break;
      }

      case ValuescriptParser::STRING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::StringContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(447);
        match(ValuescriptParser::STRING_LITERAL);
        break;
      }

      case ValuescriptParser::OPEN_PARENTHESES: {
        _localctx = _tracker.createInstance<ValuescriptParser::OrderContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(448);
        match(ValuescriptParser::OPEN_PARENTHESES);
        setState(449);
        expression(0);
        setState(450);
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
    case 15: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ValuescriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 1);
    case 7: return precpred(_ctx, 12);
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
