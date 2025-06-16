#include "valuescript.h"

#define DLL_FUNCTION __declspec(dllexport)

using namespace std;

class compiler {
private:
	
public:
    int compile(wstring fileContents) {
		vector<wstring> parsed;
		size_t begin = 0;
		size_t end = fileContents.find_first_of(L" \n\t;<>[]{}()", 0);
		while (end != fileContents.npos) {
			if (begin != end) {
				parsed.push_back(fileContents.substr(begin, end - begin));
				begin = end + 1;
				if (iswpunct(fileContents[end])) {
					parsed.push_back(fileContents.substr(end, 1));
				}
			}
			else begin++;
			end = fileContents.find_first_of(L" \n\t;<>[]{}()", begin);
		}
		vector<VS::callable> commands;
		commands.push_back(VS::callable(VS::CREATION[L"start"].first, VS::CREATION[L"start"].second, {}));
		stack<int> needs;
		for (int i = 0; i < parsed.size(); i++) {
			wstring line = parsed[i]; // TODO: FIND A SYSTEM TO PASS / MODIFY ARGS
			if (line == L"=") line = L"equals";
			if (VS::CREATION.contains(line)) {
				auto& helper = VS::CREATION[line];
				VS::callable temp(helper.first, helper.second, {});
				commands.push_back(temp);
			}
			else {
				
			}
		}
		commands.push_back(VS::callable(VS::CREATION[L"end"].first, VS::CREATION[L"end"].second, {}));
		/*commands.push_back(VS::callable(VS::CREATION[L"start"].first, VS::CREATION[L"start"].second, {}));
		commands.push_back(VS::callable(VS::CREATION[L"int"].first, VS::CREATION[L"int"].second, {
			{L"name", (std::wstring)L"x"}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"int"].first, VS::CREATION[L"int"].second, {
			{L"name", (std::wstring)L"y"}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"equals"].first, VS::CREATION[L"equals"].second, {
			{L"name", (std::wstring)L"y"},
			{L"value", 10}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"int"].first, VS::CREATION[L"int"].second, {
			{L"name", (std::wstring)L"z"}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"equals"].first, VS::CREATION[L"equals"].second, {
			{L"name", (std::wstring)L"z"},
			{L"value", 20}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"equals"].first, VS::CREATION[L"equals"].second, {
			{L"name", (std::wstring)L"y"},
			{L"value", 30}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"equals"].first, VS::CREATION[L"equals"].second, {
			{L"name", (std::wstring)L"z"},
			{L"value", 5}
			}));
		commands.push_back(VS::callable(VS::CREATION[L"end"].first, VS::CREATION[L"end"].second, {}));*/
		for (int i = 1; i < commands.size(); i++) { // NOT GOOD
			commands[i - 1].next = &commands[i];
		}
		VS::callable* curr = &commands[0];
		while (curr != nullptr) {
			(*curr).call();
			curr = (*curr).next;
		}
		return 0;
    }

	wchar_t* showError() {
		//cout << errorObject;
		//return &errorObject.message[0];
		wchar_t help = L'e';
		return &help;
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