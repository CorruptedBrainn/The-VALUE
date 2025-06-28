#define _HAS_CXX23 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include "Lexer.h"
#include "Parser.h"
#include "Environment.h"

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;

class program {
private:
    inline static vector<PARSER::AST_Node> AbstractSyntaxTree;
public:
    int analyse(wstring paramA) {
        // Do some cleanup to convert the text from Python's wstring to C++'s string
        // The full compilation is below
        size_t len = wcstombs(nullptr, paramA.c_str(), 0) + 1;
        char* buffer = new char[len];
        wcstombs(buffer, paramA.c_str(), len);
        string fileContents(buffer);
        delete[] buffer;
        cout << fileContents << "\n\n";

        try {
            LEXER::token_list tokenstream = LEXER::lex(fileContents);
            /*while (!tokenstream.empty()) {
                LEXER::lexpair x = tokenstream.front();
                tokenstream.pop();
                int underlying = to_underlying(x.second);
                cout << "[" << x.first << ", " << underlying << "]\n";
            }*/
            AbstractSyntaxTree = PARSER::parse(tokenstream);
        }
        catch (exception& e) {
            cout << "Exception Caught: " << e.what() << endl;
            return 1;
        }
        return 0;
    }
};

/// <summary>
/// Export all functions to be used by the Python side with the DLL_FUNCTION macro
/// </summary>
extern "C" {
	DLL_FUNCTION
        program* createProgram() {
        return new program;
    }
	DLL_FUNCTION
		int analyse(program* object, wchar_t* paramA) {
        return object->analyse(paramA);
    }
}