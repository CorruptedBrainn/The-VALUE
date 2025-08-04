
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
      "'typenames'", "'template'", "'import'", "'console_out'", "'export_var'", 
      "'import_var'", "'this'", "'int'", "'double'", "'bool'", "'str'", 
      "'void'", "'pair'", "'array'", "'list'", "'map'", "'hash_list'", "'hash_map'", 
      "'stack'", "'queue'", "'deque'", "'prior_queue'", "'true'", "'false'", 
      "'if'", "'else'", "'do'", "'while'", "'for'", "'('", "')'", "'{'", 
      "'}'", "'<'", "'>'", "'['", "']'", "'.'", "','", "':'", "';'", "'!'", 
      "'->'", "'&'", "'&&'", "'|'", "'||'", "'^'", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'++'", "'--'", "'='", "'+='", "'-='", "'*='", "'/='", 
      "'%='", "'=='", "'!='", "'>='", "'<='"
    },
    std::vector<std::string>{
      "", "STATIC", "CONSTANT", "VARIABLE", "FUNCTION", "CLASS", "RETURN", 
      "TYPENAMES", "TEMPLATE", "IMPORT", "DBGOUT", "EXPORTVAR", "IMPORTVAR", 
      "CLASSSCOPE", "INTEGER", "DOUBLE", "BOOLEAN", "STRING", "VOID", "PAIR", 
      "ARRAY", "ORD_LIST", "ORD_MAP", "HASH_LIST", "HASH_MAP", "STACK", 
      "QUEUE", "DEQUE", "PRIOR_QUE", "TRUE", "FALSE", "IF", "ELSE", "DO", 
      "WHILE", "FOR", "OPEN_PARENTHESES", "CLOSED_PARENTHESES", "OPEN_CURLY_BRACE", 
      "CLOSED_CURLY_BRACE", "OPEN_ANGLE_BRACKET", "CLOSED_ANGLE_BRACKET", 
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
  	4,1,80,470,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,5,0,52,8,0,10,0,12,0,55,9,0,1,0,
  	4,0,58,8,0,11,0,12,0,59,1,0,1,0,1,1,1,1,1,1,3,1,67,8,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,101,8,2,1,2,3,2,104,8,
  	2,1,3,5,3,107,8,3,10,3,12,3,110,9,3,1,3,1,3,1,3,1,3,5,3,116,8,3,10,3,
  	12,3,119,9,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,127,8,3,1,4,3,4,130,8,4,1,4,
  	3,4,133,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,3,5,143,8,5,1,5,1,5,5,5,147,
  	8,5,10,5,12,5,150,9,5,1,5,1,5,1,6,3,6,155,8,6,1,6,3,6,158,8,6,1,6,1,6,
  	1,6,1,7,1,7,1,7,1,7,1,7,5,7,168,8,7,10,7,12,7,171,9,7,1,7,3,7,174,8,7,
  	1,8,1,8,1,8,1,8,1,8,5,8,181,8,8,10,8,12,8,184,9,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,252,8,9,10,9,12,9,255,9,9,1,9,1,
  	9,3,9,259,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,269,8,10,3,
  	10,271,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,13,1,13,5,13,291,8,13,10,13,12,13,294,9,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,5,13,302,8,13,10,13,12,13,305,9,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,318,8,13,1,14,1,
  	14,4,14,322,8,14,11,14,12,14,323,1,14,1,14,1,14,3,14,329,8,14,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,342,8,15,10,15,12,
  	15,345,9,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,356,8,15,
  	10,15,12,15,359,9,15,3,15,361,8,15,1,15,3,15,364,8,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,5,15,398,8,15,10,15,12,15,401,9,15,3,15,403,8,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,5,15,413,8,15,10,15,12,15,416,9,15,1,16,1,16,
  	1,16,1,16,1,16,1,16,3,16,424,8,16,1,17,1,17,1,17,3,17,429,8,17,1,18,1,
  	18,3,18,433,8,18,1,19,1,19,1,19,1,19,1,19,1,19,3,19,441,8,19,1,20,1,20,
  	3,20,445,8,20,1,21,1,21,1,21,3,21,450,8,21,1,22,1,22,1,23,1,23,3,23,456,
  	8,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,468,8,24,
  	1,24,0,1,30,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,46,48,0,2,2,0,1,1,3,3,1,0,1,3,536,0,53,1,0,0,0,2,63,1,0,0,0,
  	4,103,1,0,0,0,6,126,1,0,0,0,8,129,1,0,0,0,10,140,1,0,0,0,12,154,1,0,0,
  	0,14,162,1,0,0,0,16,175,1,0,0,0,18,258,1,0,0,0,20,260,1,0,0,0,22,272,
  	1,0,0,0,24,278,1,0,0,0,26,317,1,0,0,0,28,328,1,0,0,0,30,363,1,0,0,0,32,
  	423,1,0,0,0,34,428,1,0,0,0,36,432,1,0,0,0,38,440,1,0,0,0,40,444,1,0,0,
  	0,42,449,1,0,0,0,44,451,1,0,0,0,46,455,1,0,0,0,48,467,1,0,0,0,50,52,3,
  	2,1,0,51,50,1,0,0,0,52,55,1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,57,1,
  	0,0,0,55,53,1,0,0,0,56,58,3,4,2,0,57,56,1,0,0,0,58,59,1,0,0,0,59,57,1,
  	0,0,0,59,60,1,0,0,0,60,61,1,0,0,0,61,62,5,0,0,1,62,1,1,0,0,0,63,64,5,
  	9,0,0,64,66,5,78,0,0,65,67,5,47,0,0,66,65,1,0,0,0,66,67,1,0,0,0,67,3,
  	1,0,0,0,68,69,3,6,3,0,69,70,5,47,0,0,70,104,1,0,0,0,71,104,3,8,4,0,72,
  	104,3,12,6,0,73,104,3,20,10,0,74,104,3,22,11,0,75,104,3,24,12,0,76,104,
  	3,26,13,0,77,78,5,10,0,0,78,79,5,36,0,0,79,80,3,30,15,0,80,81,5,37,0,
  	0,81,82,5,47,0,0,82,104,1,0,0,0,83,84,5,11,0,0,84,85,5,36,0,0,85,86,3,
  	30,15,0,86,87,5,37,0,0,87,88,5,47,0,0,88,104,1,0,0,0,89,90,5,12,0,0,90,
  	91,5,36,0,0,91,92,3,30,15,0,92,93,5,37,0,0,93,94,5,47,0,0,94,104,1,0,
  	0,0,95,96,3,30,15,0,96,97,5,47,0,0,97,104,1,0,0,0,98,100,5,6,0,0,99,101,
  	3,30,15,0,100,99,1,0,0,0,100,101,1,0,0,0,101,102,1,0,0,0,102,104,5,47,
  	0,0,103,68,1,0,0,0,103,71,1,0,0,0,103,72,1,0,0,0,103,73,1,0,0,0,103,74,
  	1,0,0,0,103,75,1,0,0,0,103,76,1,0,0,0,103,77,1,0,0,0,103,83,1,0,0,0,103,
  	89,1,0,0,0,103,95,1,0,0,0,103,98,1,0,0,0,104,5,1,0,0,0,105,107,7,0,0,
  	0,106,105,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,
  	111,1,0,0,0,110,108,1,0,0,0,111,112,5,78,0,0,112,113,5,49,0,0,113,127,
  	3,18,9,0,114,116,7,1,0,0,115,114,1,0,0,0,116,119,1,0,0,0,117,115,1,0,
  	0,0,117,118,1,0,0,0,118,120,1,0,0,0,119,117,1,0,0,0,120,121,5,78,0,0,
  	121,122,5,49,0,0,122,123,3,18,9,0,123,124,5,62,0,0,124,125,3,30,15,0,
  	125,127,1,0,0,0,126,108,1,0,0,0,126,117,1,0,0,0,127,7,1,0,0,0,128,130,
  	3,16,8,0,129,128,1,0,0,0,129,130,1,0,0,0,130,132,1,0,0,0,131,133,5,4,
  	0,0,132,131,1,0,0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,135,5,78,0,0,
  	135,136,3,10,5,0,136,137,5,49,0,0,137,138,3,18,9,0,138,139,3,28,14,0,
  	139,9,1,0,0,0,140,142,5,36,0,0,141,143,3,6,3,0,142,141,1,0,0,0,142,143,
  	1,0,0,0,143,148,1,0,0,0,144,145,5,45,0,0,145,147,3,6,3,0,146,144,1,0,
  	0,0,147,150,1,0,0,0,148,146,1,0,0,0,148,149,1,0,0,0,149,151,1,0,0,0,150,
  	148,1,0,0,0,151,152,5,37,0,0,152,11,1,0,0,0,153,155,3,16,8,0,154,153,
  	1,0,0,0,154,155,1,0,0,0,155,157,1,0,0,0,156,158,5,5,0,0,157,156,1,0,0,
  	0,157,158,1,0,0,0,158,159,1,0,0,0,159,160,5,78,0,0,160,161,3,28,14,0,
  	161,13,1,0,0,0,162,163,5,8,0,0,163,164,5,49,0,0,164,169,3,18,9,0,165,
  	166,5,45,0,0,166,168,3,18,9,0,167,165,1,0,0,0,168,171,1,0,0,0,169,167,
  	1,0,0,0,169,170,1,0,0,0,170,173,1,0,0,0,171,169,1,0,0,0,172,174,5,47,
  	0,0,173,172,1,0,0,0,173,174,1,0,0,0,174,15,1,0,0,0,175,176,5,7,0,0,176,
  	177,5,46,0,0,177,182,5,78,0,0,178,179,5,45,0,0,179,181,5,78,0,0,180,178,
  	1,0,0,0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,17,1,0,0,
  	0,184,182,1,0,0,0,185,259,5,14,0,0,186,259,5,15,0,0,187,259,5,17,0,0,
  	188,259,5,16,0,0,189,190,5,19,0,0,190,191,5,40,0,0,191,192,3,18,9,0,192,
  	193,5,45,0,0,193,194,3,18,9,0,194,195,5,41,0,0,195,259,1,0,0,0,196,197,
  	5,20,0,0,197,198,5,40,0,0,198,199,3,18,9,0,199,200,5,41,0,0,200,259,1,
  	0,0,0,201,202,5,21,0,0,202,203,5,40,0,0,203,204,3,18,9,0,204,205,5,41,
  	0,0,205,259,1,0,0,0,206,207,5,22,0,0,207,208,5,40,0,0,208,209,3,18,9,
  	0,209,210,5,45,0,0,210,211,3,18,9,0,211,212,5,41,0,0,212,259,1,0,0,0,
  	213,214,5,23,0,0,214,215,5,40,0,0,215,216,3,18,9,0,216,217,5,41,0,0,217,
  	259,1,0,0,0,218,219,5,24,0,0,219,220,5,40,0,0,220,221,3,18,9,0,221,222,
  	5,45,0,0,222,223,3,18,9,0,223,224,5,41,0,0,224,259,1,0,0,0,225,226,5,
  	25,0,0,226,227,5,40,0,0,227,228,3,18,9,0,228,229,5,41,0,0,229,259,1,0,
  	0,0,230,231,5,26,0,0,231,232,5,40,0,0,232,233,3,18,9,0,233,234,5,41,0,
  	0,234,259,1,0,0,0,235,236,5,27,0,0,236,237,5,40,0,0,237,238,3,18,9,0,
  	238,239,5,41,0,0,239,259,1,0,0,0,240,241,5,28,0,0,241,242,5,40,0,0,242,
  	243,3,18,9,0,243,244,5,41,0,0,244,259,1,0,0,0,245,259,5,78,0,0,246,247,
  	5,78,0,0,247,248,5,40,0,0,248,253,3,18,9,0,249,250,5,45,0,0,250,252,3,
  	18,9,0,251,249,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,
  	0,254,256,1,0,0,0,255,253,1,0,0,0,256,257,5,41,0,0,257,259,1,0,0,0,258,
  	185,1,0,0,0,258,186,1,0,0,0,258,187,1,0,0,0,258,188,1,0,0,0,258,189,1,
  	0,0,0,258,196,1,0,0,0,258,201,1,0,0,0,258,206,1,0,0,0,258,213,1,0,0,0,
  	258,218,1,0,0,0,258,225,1,0,0,0,258,230,1,0,0,0,258,235,1,0,0,0,258,240,
  	1,0,0,0,258,245,1,0,0,0,258,246,1,0,0,0,259,19,1,0,0,0,260,261,5,31,0,
  	0,261,262,5,36,0,0,262,263,3,30,15,0,263,264,5,37,0,0,264,270,3,28,14,
  	0,265,268,5,32,0,0,266,269,3,28,14,0,267,269,3,20,10,0,268,266,1,0,0,
  	0,268,267,1,0,0,0,269,271,1,0,0,0,270,265,1,0,0,0,270,271,1,0,0,0,271,
  	21,1,0,0,0,272,273,5,34,0,0,273,274,5,36,0,0,274,275,3,30,15,0,275,276,
  	5,37,0,0,276,277,3,28,14,0,277,23,1,0,0,0,278,279,5,33,0,0,279,280,3,
  	28,14,0,280,281,5,34,0,0,281,282,5,36,0,0,282,283,3,30,15,0,283,284,5,
  	37,0,0,284,25,1,0,0,0,285,286,5,35,0,0,286,287,5,36,0,0,287,292,3,6,3,
  	0,288,289,5,45,0,0,289,291,3,6,3,0,290,288,1,0,0,0,291,294,1,0,0,0,292,
  	290,1,0,0,0,292,293,1,0,0,0,293,295,1,0,0,0,294,292,1,0,0,0,295,296,5,
  	47,0,0,296,297,3,30,15,0,297,298,5,47,0,0,298,303,3,30,15,0,299,300,5,
  	45,0,0,300,302,3,30,15,0,301,299,1,0,0,0,302,305,1,0,0,0,303,301,1,0,
  	0,0,303,304,1,0,0,0,304,306,1,0,0,0,305,303,1,0,0,0,306,307,5,37,0,0,
  	307,308,3,28,14,0,308,318,1,0,0,0,309,310,5,35,0,0,310,311,5,36,0,0,311,
  	312,3,6,3,0,312,313,5,46,0,0,313,314,3,30,15,0,314,315,5,37,0,0,315,316,
  	3,28,14,0,316,318,1,0,0,0,317,285,1,0,0,0,317,309,1,0,0,0,318,27,1,0,
  	0,0,319,321,5,38,0,0,320,322,3,4,2,0,321,320,1,0,0,0,322,323,1,0,0,0,
  	323,321,1,0,0,0,323,324,1,0,0,0,324,325,1,0,0,0,325,326,5,39,0,0,326,
  	329,1,0,0,0,327,329,3,4,2,0,328,319,1,0,0,0,328,327,1,0,0,0,329,29,1,
  	0,0,0,330,331,6,15,-1,0,331,364,3,48,24,0,332,333,5,13,0,0,333,334,5,
  	44,0,0,334,364,5,78,0,0,335,336,3,14,7,0,336,337,3,30,15,0,337,338,5,
  	36,0,0,338,343,3,30,15,0,339,340,5,45,0,0,340,342,3,30,15,0,341,339,1,
  	0,0,0,342,345,1,0,0,0,343,341,1,0,0,0,343,344,1,0,0,0,344,346,1,0,0,0,
  	345,343,1,0,0,0,346,347,5,37,0,0,347,364,1,0,0,0,348,349,3,44,22,0,349,
  	350,3,30,15,8,350,364,1,0,0,0,351,360,5,38,0,0,352,357,3,30,15,0,353,
  	354,5,45,0,0,354,356,3,30,15,0,355,353,1,0,0,0,356,359,1,0,0,0,357,355,
  	1,0,0,0,357,358,1,0,0,0,358,361,1,0,0,0,359,357,1,0,0,0,360,352,1,0,0,
  	0,360,361,1,0,0,0,361,362,1,0,0,0,362,364,5,39,0,0,363,330,1,0,0,0,363,
  	332,1,0,0,0,363,335,1,0,0,0,363,348,1,0,0,0,363,351,1,0,0,0,364,414,1,
  	0,0,0,365,366,10,7,0,0,366,367,3,42,21,0,367,368,3,30,15,8,368,413,1,
  	0,0,0,369,370,10,6,0,0,370,371,3,40,20,0,371,372,3,30,15,7,372,413,1,
  	0,0,0,373,374,10,5,0,0,374,375,3,38,19,0,375,376,3,30,15,6,376,413,1,
  	0,0,0,377,378,10,4,0,0,378,379,3,36,18,0,379,380,3,30,15,5,380,413,1,
  	0,0,0,381,382,10,3,0,0,382,383,3,34,17,0,383,384,3,30,15,4,384,413,1,
  	0,0,0,385,386,10,1,0,0,386,387,3,32,16,0,387,388,3,30,15,2,388,413,1,
  	0,0,0,389,390,10,13,0,0,390,391,5,44,0,0,391,413,5,78,0,0,392,393,10,
  	12,0,0,393,402,5,36,0,0,394,399,3,30,15,0,395,396,5,45,0,0,396,398,3,
  	30,15,0,397,395,1,0,0,0,398,401,1,0,0,0,399,397,1,0,0,0,399,400,1,0,0,
  	0,400,403,1,0,0,0,401,399,1,0,0,0,402,394,1,0,0,0,402,403,1,0,0,0,403,
  	404,1,0,0,0,404,413,5,37,0,0,405,406,10,10,0,0,406,407,5,42,0,0,407,408,
  	3,30,15,0,408,409,5,43,0,0,409,413,1,0,0,0,410,411,10,9,0,0,411,413,3,
  	46,23,0,412,365,1,0,0,0,412,369,1,0,0,0,412,373,1,0,0,0,412,377,1,0,0,
  	0,412,381,1,0,0,0,412,385,1,0,0,0,412,389,1,0,0,0,412,392,1,0,0,0,412,
  	405,1,0,0,0,412,410,1,0,0,0,413,416,1,0,0,0,414,412,1,0,0,0,414,415,1,
  	0,0,0,415,31,1,0,0,0,416,414,1,0,0,0,417,424,5,62,0,0,418,424,5,63,0,
  	0,419,424,5,64,0,0,420,424,5,65,0,0,421,424,5,66,0,0,422,424,5,67,0,0,
  	423,417,1,0,0,0,423,418,1,0,0,0,423,419,1,0,0,0,423,420,1,0,0,0,423,421,
  	1,0,0,0,423,422,1,0,0,0,424,33,1,0,0,0,425,429,5,50,0,0,426,429,5,52,
  	0,0,427,429,5,54,0,0,428,425,1,0,0,0,428,426,1,0,0,0,428,427,1,0,0,0,
  	429,35,1,0,0,0,430,433,5,51,0,0,431,433,5,53,0,0,432,430,1,0,0,0,432,
  	431,1,0,0,0,433,37,1,0,0,0,434,441,5,68,0,0,435,441,5,69,0,0,436,441,
  	5,70,0,0,437,441,5,71,0,0,438,441,5,40,0,0,439,441,5,41,0,0,440,434,1,
  	0,0,0,440,435,1,0,0,0,440,436,1,0,0,0,440,437,1,0,0,0,440,438,1,0,0,0,
  	440,439,1,0,0,0,441,39,1,0,0,0,442,445,5,55,0,0,443,445,5,56,0,0,444,
  	442,1,0,0,0,444,443,1,0,0,0,445,41,1,0,0,0,446,450,5,57,0,0,447,450,5,
  	58,0,0,448,450,5,59,0,0,449,446,1,0,0,0,449,447,1,0,0,0,449,448,1,0,0,
  	0,450,43,1,0,0,0,451,452,5,48,0,0,452,45,1,0,0,0,453,456,5,60,0,0,454,
  	456,5,61,0,0,455,453,1,0,0,0,455,454,1,0,0,0,456,47,1,0,0,0,457,468,5,
  	78,0,0,458,468,5,75,0,0,459,468,5,76,0,0,460,468,5,29,0,0,461,468,5,30,
  	0,0,462,468,5,77,0,0,463,464,5,36,0,0,464,465,3,30,15,0,465,466,5,37,
  	0,0,466,468,1,0,0,0,467,457,1,0,0,0,467,458,1,0,0,0,467,459,1,0,0,0,467,
  	460,1,0,0,0,467,461,1,0,0,0,467,462,1,0,0,0,467,463,1,0,0,0,468,49,1,
  	0,0,0,42,53,59,66,100,103,108,117,126,129,132,142,148,154,157,169,173,
  	182,253,258,268,270,292,303,317,323,328,343,357,360,363,399,402,412,414,
  	423,428,432,440,444,449,455,467
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
      ((1ULL << _la) & 281882461748734) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & 15) != 0));
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
//----------------- StatementexportContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::StatementexportContext::EXPORTVAR() {
  return getToken(ValuescriptParser::EXPORTVAR, 0);
}

tree::TerminalNode* ValuescriptParser::StatementexportContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementexportContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementexportContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::StatementexportContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::StatementexportContext::StatementexportContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementexportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementexport(this);
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
//----------------- StatementimportContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::StatementimportContext::IMPORTVAR() {
  return getToken(ValuescriptParser::IMPORTVAR, 0);
}

tree::TerminalNode* ValuescriptParser::StatementimportContext::OPEN_PARENTHESES() {
  return getToken(ValuescriptParser::OPEN_PARENTHESES, 0);
}

ValuescriptParser::ExpressionContext* ValuescriptParser::StatementimportContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::StatementimportContext::CLOSED_PARENTHESES() {
  return getToken(ValuescriptParser::CLOSED_PARENTHESES, 0);
}

tree::TerminalNode* ValuescriptParser::StatementimportContext::SEMICOLON() {
  return getToken(ValuescriptParser::SEMICOLON, 0);
}

ValuescriptParser::StatementimportContext::StatementimportContext(StatementContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::StatementimportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementimport(this);
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
    setState(103);
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
      _localctx = _tracker.createInstance<ValuescriptParser::StatementexportContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(83);
      match(ValuescriptParser::EXPORTVAR);
      setState(84);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(85);
      expression(0);
      setState(86);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(87);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementimportContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(89);
      match(ValuescriptParser::IMPORTVAR);
      setState(90);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(91);
      expression(0);
      setState(92);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(93);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementexprContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(95);
      expression(0);
      setState(96);
      match(ValuescriptParser::SEMICOLON);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<ValuescriptParser::StatementretContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(98);
      match(ValuescriptParser::RETURN);
      setState(100);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 281820184715520) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & 15) != 0)) {
        setState(99);
        expression(0);
      }
      setState(102);
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
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::STATIC

      || _la == ValuescriptParser::VARIABLE) {
        setState(105);
        _la = _input->LA(1);
        if (!(_la == ValuescriptParser::STATIC

        || _la == ValuescriptParser::VARIABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(111);
      match(ValuescriptParser::IDENTIFIER);
      setState(112);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(113);
      typenameexpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 14) != 0)) {
        setState(114);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 14) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(119);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(120);
      match(ValuescriptParser::IDENTIFIER);
      setState(121);
      match(ValuescriptParser::ARROW_OPERATOR);
      setState(122);
      typenameexpression();
      setState(123);
      match(ValuescriptParser::ASSIGNMENT_GENERIC);
      setState(124);
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
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(128);
      templatedeclaration();
    }
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::FUNCTION) {
      setState(131);
      match(ValuescriptParser::FUNCTION);
    }
    setState(134);
    match(ValuescriptParser::IDENTIFIER);
    setState(135);
    functionparameters();
    setState(136);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(137);
    typenameexpression();
    setState(138);
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
    setState(140);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14) != 0) || _la == ValuescriptParser::IDENTIFIER) {
      setState(141);
      variabledeclaration();
    }
    setState(148);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(144);
      match(ValuescriptParser::COMMA);
      setState(145);
      variabledeclaration();
      setState(150);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(151);
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
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::TYPENAMES) {
      setState(153);
      templatedeclaration();
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::CLASS) {
      setState(156);
      match(ValuescriptParser::CLASS);
    }
    setState(159);
    match(ValuescriptParser::IDENTIFIER);
    setState(160);
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
    setState(162);
    match(ValuescriptParser::TEMPLATE);
    setState(163);
    match(ValuescriptParser::ARROW_OPERATOR);
    setState(164);
    typenameexpression();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(165);
      match(ValuescriptParser::COMMA);
      setState(166);
      typenameexpression();
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ValuescriptParser::SEMICOLON) {
      setState(172);
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
    setState(175);
    match(ValuescriptParser::TYPENAMES);
    setState(176);
    match(ValuescriptParser::COLON);
    setState(177);
    match(ValuescriptParser::IDENTIFIER);
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ValuescriptParser::COMMA) {
      setState(178);
      match(ValuescriptParser::COMMA);
      setState(179);
      match(ValuescriptParser::IDENTIFIER);
      setState(184);
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
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyintegerContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(185);
      match(ValuescriptParser::INTEGER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::TydoubleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(186);
      match(ValuescriptParser::DOUBLE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValuescriptParser::TystringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(187);
      match(ValuescriptParser::STRING);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValuescriptParser::TybooleanContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(188);
      match(ValuescriptParser::BOOLEAN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValuescriptParser::TypairContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(189);
      match(ValuescriptParser::PAIR);
      setState(190);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(191);
      typenameexpression();
      setState(192);
      match(ValuescriptParser::COMMA);
      setState(193);
      typenameexpression();
      setState(194);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyarrayContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(196);
      match(ValuescriptParser::ARRAY);
      setState(197);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(198);
      typenameexpression();
      setState(199);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValuescriptParser::TysetContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(201);
      match(ValuescriptParser::ORD_LIST);
      setState(202);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(203);
      typenameexpression();
      setState(204);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ValuescriptParser::TymapContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(206);
      match(ValuescriptParser::ORD_MAP);
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

    case 9: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyusetContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(213);
      match(ValuescriptParser::HASH_LIST);
      setState(214);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(215);
      typenameexpression();
      setState(216);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyumapContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(218);
      match(ValuescriptParser::HASH_MAP);
      setState(219);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(220);
      typenameexpression();
      setState(221);
      match(ValuescriptParser::COMMA);
      setState(222);
      typenameexpression();
      setState(223);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<ValuescriptParser::TystackContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(225);
      match(ValuescriptParser::STACK);
      setState(226);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(227);
      typenameexpression();
      setState(228);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyqueueContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(230);
      match(ValuescriptParser::QUEUE);
      setState(231);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(232);
      typenameexpression();
      setState(233);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<ValuescriptParser::TydequeContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(235);
      match(ValuescriptParser::DEQUE);
      setState(236);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(237);
      typenameexpression();
      setState(238);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<ValuescriptParser::TypriorContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(240);
      match(ValuescriptParser::PRIOR_QUE);
      setState(241);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(242);
      typenameexpression();
      setState(243);
      match(ValuescriptParser::CLOSED_ANGLE_BRACKET);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<ValuescriptParser::TyidentContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(245);
      match(ValuescriptParser::IDENTIFIER);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<ValuescriptParser::TynestedContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(246);
      match(ValuescriptParser::IDENTIFIER);
      setState(247);
      match(ValuescriptParser::OPEN_ANGLE_BRACKET);
      setState(248);
      typenameexpression();
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(249);
        match(ValuescriptParser::COMMA);
        setState(250);
        typenameexpression();
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(256);
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
    setState(260);
    match(ValuescriptParser::IF);
    setState(261);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(262);
    expression(0);
    setState(263);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(264);
    codeblock();
    setState(270);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(265);
      match(ValuescriptParser::ELSE);
      setState(268);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(266);
        codeblock();
        break;
      }

      case 2: {
        setState(267);
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
    setState(272);
    match(ValuescriptParser::WHILE);
    setState(273);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(274);
    expression(0);
    setState(275);
    match(ValuescriptParser::CLOSED_PARENTHESES);
    setState(276);
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
    setState(278);
    match(ValuescriptParser::DO);
    setState(279);
    codeblock();
    setState(280);
    match(ValuescriptParser::WHILE);
    setState(281);
    match(ValuescriptParser::OPEN_PARENTHESES);
    setState(282);
    expression(0);
    setState(283);
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
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ValuescriptParser::RangeforContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(285);
      match(ValuescriptParser::FOR);
      setState(286);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(287);
      variabledeclaration();
      setState(292);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(288);
        match(ValuescriptParser::COMMA);
        setState(289);
        variabledeclaration();
        setState(294);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(295);
      match(ValuescriptParser::SEMICOLON);
      setState(296);
      expression(0);
      setState(297);
      match(ValuescriptParser::SEMICOLON);
      setState(298);
      expression(0);
      setState(303);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ValuescriptParser::COMMA) {
        setState(299);
        match(ValuescriptParser::COMMA);
        setState(300);
        expression(0);
        setState(305);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(306);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(307);
      codeblock();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ValuescriptParser::ItemforContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(309);
      match(ValuescriptParser::FOR);
      setState(310);
      match(ValuescriptParser::OPEN_PARENTHESES);
      setState(311);
      variabledeclaration();
      setState(312);
      match(ValuescriptParser::COLON);
      setState(313);
      expression(0);
      setState(314);
      match(ValuescriptParser::CLOSED_PARENTHESES);
      setState(315);
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
    setState(328);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(319);
      match(ValuescriptParser::OPEN_CURLY_BRACE);
      setState(321); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(320);
        statement();
        setState(323); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 281882461748734) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 75)) & 15) != 0));
      setState(325);
      match(ValuescriptParser::CLOSED_CURLY_BRACE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(327);
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

ValuescriptParser::ExpressionContext* ValuescriptParser::MembexprContext::expression() {
  return getRuleContext<ValuescriptParser::ExpressionContext>(0);
}

tree::TerminalNode* ValuescriptParser::MembexprContext::PERIOD() {
  return getToken(ValuescriptParser::PERIOD, 0);
}

tree::TerminalNode* ValuescriptParser::MembexprContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
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
//----------------- ThisexprContext ------------------------------------------------------------------

tree::TerminalNode* ValuescriptParser::ThisexprContext::CLASSSCOPE() {
  return getToken(ValuescriptParser::CLASSSCOPE, 0);
}

tree::TerminalNode* ValuescriptParser::ThisexprContext::PERIOD() {
  return getToken(ValuescriptParser::PERIOD, 0);
}

tree::TerminalNode* ValuescriptParser::ThisexprContext::IDENTIFIER() {
  return getToken(ValuescriptParser::IDENTIFIER, 0);
}

ValuescriptParser::ThisexprContext::ThisexprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any ValuescriptParser::ThisexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ValuescriptParserVisitor*>(visitor))
    return parserVisitor->visitThisexpr(this);
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
    setState(363);
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

        setState(331);
        primaryexpression();
        break;
      }

      case ValuescriptParser::CLASSSCOPE: {
        _localctx = _tracker.createInstance<ThisexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(332);
        match(ValuescriptParser::CLASSSCOPE);
        setState(333);
        match(ValuescriptParser::PERIOD);
        setState(334);
        match(ValuescriptParser::IDENTIFIER);
        break;
      }

      case ValuescriptParser::TEMPLATE: {
        _localctx = _tracker.createInstance<TyparexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(335);
        templateexpression();
        setState(336);
        expression(0);
        setState(337);
        match(ValuescriptParser::OPEN_PARENTHESES);
        setState(338);
        expression(0);
        setState(343);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ValuescriptParser::COMMA) {
          setState(339);
          match(ValuescriptParser::COMMA);
          setState(340);
          expression(0);
          setState(345);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(346);
        match(ValuescriptParser::CLOSED_PARENTHESES);
        break;
      }

      case ValuescriptParser::EXCLAMATION_POINT: {
        _localctx = _tracker.createInstance<NotexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(348);
        notoperator();
        setState(349);
        expression(8);
        break;
      }

      case ValuescriptParser::OPEN_CURLY_BRACE: {
        _localctx = _tracker.createInstance<ObjexprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(351);
        match(ValuescriptParser::OPEN_CURLY_BRACE);
        setState(360);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 281820184715520) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 75)) & 15) != 0)) {
          setState(352);
          expression(0);
          setState(357);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ValuescriptParser::COMMA) {
            setState(353);
            match(ValuescriptParser::COMMA);
            setState(354);
            expression(0);
            setState(359);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(362);
        match(ValuescriptParser::CLOSED_CURLY_BRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(414);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(412);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(365);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(366);
          multiplicativeoperator();
          setState(367);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(369);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(370);
          additiveoperator();
          setState(371);
          expression(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CompexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(373);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(374);
          comparisonoperator();
          setState(375);
          expression(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BoolexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(377);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(378);
          booleanoperator();
          setState(379);
          expression(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(381);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(382);
          binaryoperator();
          setState(383);
          expression(4);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AssignexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(385);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(386);
          assignmentoperator();
          setState(387);
          expression(2);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<MembexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(389);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(390);
          match(ValuescriptParser::PERIOD);
          setState(391);
          match(ValuescriptParser::IDENTIFIER);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ParenexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(392);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(393);
          match(ValuescriptParser::OPEN_PARENTHESES);
          setState(402);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 281820184715520) != 0) || ((((_la - 75) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 75)) & 15) != 0)) {
            setState(394);
            expression(0);
            setState(399);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == ValuescriptParser::COMMA) {
              setState(395);
              match(ValuescriptParser::COMMA);
              setState(396);
              expression(0);
              setState(401);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(404);
          match(ValuescriptParser::CLOSED_PARENTHESES);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AccessexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(405);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(406);
          match(ValuescriptParser::OPEN_SQUARE);
          setState(407);
          expression(0);
          setState(408);
          match(ValuescriptParser::CLOSED_SQUARE);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<IncexprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(410);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(411);
          incrementaloperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(416);
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
    setState(423);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ASSIGNMENT_GENERIC: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsseqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(417);
        match(ValuescriptParser::ASSIGNMENT_GENERIC);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_ADD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssaddContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(418);
        match(ValuescriptParser::ASSIGNMENT_ADD);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_SUB: {
        _localctx = _tracker.createInstance<ValuescriptParser::AsssubContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(419);
        match(ValuescriptParser::ASSIGNMENT_SUB);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MULTI: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmulContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(420);
        match(ValuescriptParser::ASSIGNMENT_MULTI);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_DIV: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssdivContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(421);
        match(ValuescriptParser::ASSIGNMENT_DIV);
        break;
      }

      case ValuescriptParser::ASSIGNMENT_MOD: {
        _localctx = _tracker.createInstance<ValuescriptParser::AssmodContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(422);
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
    setState(428);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BITWISE_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(425);
        match(ValuescriptParser::BITWISE_AND);
        break;
      }

      case ValuescriptParser::BITWISE_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(426);
        match(ValuescriptParser::BITWISE_OR);
        break;
      }

      case ValuescriptParser::BITWISE_XOR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BitxorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(427);
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
    setState(432);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::BOOLEAN_AND: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(430);
        match(ValuescriptParser::BOOLEAN_AND);
        break;
      }

      case ValuescriptParser::BOOLEAN_OR: {
        _localctx = _tracker.createInstance<ValuescriptParser::BoolorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(431);
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
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompeqlContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(434);
        match(ValuescriptParser::EQUALITY);
        break;
      }

      case ValuescriptParser::NON_EQUALITY: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompnonContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(435);
        match(ValuescriptParser::NON_EQUALITY);
        break;
      }

      case ValuescriptParser::GREATER_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgoeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(436);
        match(ValuescriptParser::GREATER_OR_EQUAL);
        break;
      }

      case ValuescriptParser::LESS_OR_EQUAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComploeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(437);
        match(ValuescriptParser::LESS_OR_EQUAL);
        break;
      }

      case ValuescriptParser::OPEN_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::ComplssContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(438);
        match(ValuescriptParser::OPEN_ANGLE_BRACKET);
        break;
      }

      case ValuescriptParser::CLOSED_ANGLE_BRACKET: {
        _localctx = _tracker.createInstance<ValuescriptParser::CompgreContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(439);
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
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::ADDITION: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(442);
        match(ValuescriptParser::ADDITION);
        break;
      }

      case ValuescriptParser::SUBTRACTION: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(443);
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
    setState(449);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::MULTIPLICATION: {
        _localctx = _tracker.createInstance<ValuescriptParser::TimesContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(446);
        match(ValuescriptParser::MULTIPLICATION);
        break;
      }

      case ValuescriptParser::DIVISION: {
        _localctx = _tracker.createInstance<ValuescriptParser::DivideContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(447);
        match(ValuescriptParser::DIVISION);
        break;
      }

      case ValuescriptParser::MODULUS: {
        _localctx = _tracker.createInstance<ValuescriptParser::ModuloContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(448);
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
    setState(451);
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
    setState(455);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::INCREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::PlusplusContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(453);
        match(ValuescriptParser::INCREMENT);
        break;
      }

      case ValuescriptParser::DECREMENT: {
        _localctx = _tracker.createInstance<ValuescriptParser::MinusminusContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(454);
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
    setState(467);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ValuescriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<ValuescriptParser::IdentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(457);
        match(ValuescriptParser::IDENTIFIER);
        break;
      }

      case ValuescriptParser::FLOATING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::DecimalContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(458);
        match(ValuescriptParser::FLOATING_LITERAL);
        break;
      }

      case ValuescriptParser::INTEGER_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::NumberContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(459);
        match(ValuescriptParser::INTEGER_LITERAL);
        break;
      }

      case ValuescriptParser::TRUE: {
        _localctx = _tracker.createInstance<ValuescriptParser::TrueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(460);
        match(ValuescriptParser::TRUE);
        break;
      }

      case ValuescriptParser::FALSE: {
        _localctx = _tracker.createInstance<ValuescriptParser::FalseContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(461);
        match(ValuescriptParser::FALSE);
        break;
      }

      case ValuescriptParser::STRING_LITERAL: {
        _localctx = _tracker.createInstance<ValuescriptParser::StringContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(462);
        match(ValuescriptParser::STRING_LITERAL);
        break;
      }

      case ValuescriptParser::OPEN_PARENTHESES: {
        _localctx = _tracker.createInstance<ValuescriptParser::OrderContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(463);
        match(ValuescriptParser::OPEN_PARENTHESES);
        setState(464);
        expression(0);
        setState(465);
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
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 1);
    case 6: return precpred(_ctx, 13);
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
