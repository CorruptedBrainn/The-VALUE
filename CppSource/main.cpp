#define _HAS_CXX23 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include "Lexer.h"
#include "Parser.h"

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;

class translator {
public:
    int translate (wstring paramA) {
        // Do some cleanup to convert the text from Python's wstring to C++'s string
        // The full compilation is below
        size_t len = wcstombs(nullptr, paramA.c_str(), 0) + 1;
        char* buffer = new char[len];
        wcstombs(buffer, paramA.c_str(), len);
        string fileContents(buffer);
        delete[] buffer;
        cout << fileContents << "\n\n";

        LEXER::token_list tokenstream = LEXER::lex(fileContents);
        while (!tokenstream.empty()) {
            LEXER::lexpair x = tokenstream.front();
            tokenstream.pop();
            int underlying = to_underlying(x.second);
            cout << "[" << x.first << ", " << underlying << "]\n";
        }
        vector<PARSER::AST_Node> AbstractSyntaxTree = PARSER::parse(tokenstream);
        return 1;
    }
};

/// <summary>
/// Export all functions to be used by the Python side with the DLL_FUNCTION macro
/// </summary>
extern "C" {
	DLL_FUNCTION
        translator* createCompiler() {
        return new translator;
    }
	DLL_FUNCTION
		int translate(translator* object, wchar_t* paramA) {
        return object->translate(paramA);
    }
}