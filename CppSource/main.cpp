#include <queue>
#include "valuescript.h"

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;

class compiler {
private:
	inline static queue<VS::CALLABLE> commands;
	inline static VS::COMPILE_ERROR errorObject;
	friend queue<VS::CALLABLE> VS::COMPILE(wstring& contents, VS::COMPILE_ERROR& err);
public:
    int compile(wstring fileContents) {
		commands = VS::COMPILE(fileContents, errorObject);
		if (commands.empty()) {
			return -1;
		}
		return 0;
    }
	wchar_t* showError() {
		cout << errorObject;
		return &errorObject.message[0];
	}
};

/// <summary>
/// Export all functions to be used by the Python side with the DLL_FUNCTION macro
/// </summary>
extern "C" {
	DLL_FUNCTION
		compiler* createCompiler() {
        return new compiler;
    }
	DLL_FUNCTION
		int compile(compiler* object, wchar_t* paramA) {
        return object->compile(paramA);
    }
	DLL_FUNCTION
		wchar_t* showError(compiler* object) {
		return object->showError();
	}
}