#include <queue>
#include "valuescript.h"

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;

class compiler {
public:
    int compile(wstring fileContents) {
		// INPUT: A string formatted such that a command is ended with a semicolon
		// The idea is that we iterate through the contents of a line -- dictated by space between semicolons
		// For now, assume format function(arguments)
		queue<VS::CALLABLE> commands = VS::COMPILE(fileContents);
		while (!commands.empty()) {
			VS::CALLABLE command = commands.front();
			commands.pop();
			VS::RETURN ret = VS::CALL(command);
			cout << ret << "\n";
		}
		return 0;
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
}