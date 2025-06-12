#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <functional>
#include <variant>

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;
using namespace std::placeholders;

class valuescriptTranslation {
private:
	static void VSPrint(wstring string) { wcout << string; return; }
	static int genFive() { return 5; }
public:
	inline static unordered_map<wstring, variant<function<void(wstring)>, function<int()>>> functions;
	valuescriptTranslation() {
		functions[L"print"] = bind(VSPrint, _1);
		functions[L"gen"] = genFive;
	}
};

class compiler {
private:
	valuescriptTranslation VS_T;

public:
    bool compile(wstring fileContents) {
		
        return 1;
    }
};

extern "C" {
	DLL_FUNCTION
	compiler* createCompiler() {
        return new compiler;
    }
	DLL_FUNCTION
	bool compile(compiler* object, wchar_t* paramA) {
        return object->compile(paramA);
    }
}