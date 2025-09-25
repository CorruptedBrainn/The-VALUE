#include "translator.h"

using namespace valuescriptantlrgeneration;
using namespace antlr4;
using namespace std;

queue<ValuescriptError> warningList, errorList;

string convert::chartostr(const char* input) {
	string buffer(input);
	return buffer;
}

string convert::wchartostr(const wchar_t* input) {
	size_t len = wcstombs(nullptr, input, 0) + 1;
	string buffer(len, '-');
	wcstombs(buffer.data(), input, len);
	return buffer;
}

string convert::wstrtostr(wstring input)
{
	return convert::wchartostr(input.c_str());
}

wstring convert::chartowstr(const char* input)
{
	size_t len = mbstowcs(nullptr, input, 0) + 1;
	wstring buffer(len, L'-');
	mbstowcs(buffer.data(), input, len);
	return buffer;
}

wstring convert::wchartowstr(const wchar_t* input)
{
	wstring buffer(input);
	return buffer;
}

wstring convert::strtowstr(string input)
{
	return convert::chartowstr(input.c_str());
}

char* convert::wchartochar(const wchar_t* input)
{
	size_t len = wcstombs(nullptr, input, 0) + 1;
	char* buffer = new char[len];
	wcstombs(buffer, input, len);
	return buffer;
}

char* convert::strtochar(string input)
{
	size_t len = mbstowcs(nullptr, input.c_str(), 0) + 1;
	char* buffer = new char[len];
	strcpy(buffer, input.c_str());
	return buffer;
}

char* convert::wstrtochar(wstring input)
{
	return wchartochar(input.c_str());
}

wchar_t* convert::chartowchar(const char* input)
{
	size_t len = mbstowcs(nullptr, input, 0) + 1;
	wchar_t* buffer = new wchar_t[len];
	mbstowcs(buffer, input, len);
	return buffer;
}

wchar_t* convert::strtowchar(string input)
{
	return chartowchar(input.c_str());
}

wchar_t* convert::wstrtowchar(wstring input)
{
	size_t len = wcstombs(nullptr, input.c_str(), 0) + 1;
	wchar_t* buffer = new wchar_t[len];
	wcscpy(buffer, input.c_str());
	return buffer;
}

int scriptCheckStageA(const wchar_t* script)
{
	if (warningList.empty()) {
		string program = convert::wchartostr(script);
		ValuescriptWarningListener listener(warningList);
		ANTLRInputStream input(program);
		ValuescriptLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		ValuescriptParser parser(&tokens);
		parser.removeErrorListeners();
		parser.addErrorListener(&listener);
		tree::ParseTree* tree = parser.file();
	}
	return warningList.size();
}

ValuescriptError scriptCheckStageB()
{
	return warningList.front();
}

int scriptCheckStageC(int expected)
{
	if (!warningList.empty() && warningList.size() > expected) {
		delete[] warningList.front().message;
		warningList.pop();
	}
	return warningList.size();
}

int errorCheckStageA(const wchar_t* script)
{
	return 0;
}

ValuescriptError errorCheckStageB()
{
	return errorList.front();
}

int errorCheckStageC()
{
	delete[] errorList.front().message;
	errorList.pop();
	return errorList.size();
}

int compileProcessStageA()
{
	return 0;
}

int compileProcessStageB(const wchar_t* script, const wchar_t* name)
{
	return 0;
}

int compileProcessStageC()
{
	return 0;
}

int runtimeStageA()
{
	return 0;
}

int runtimeStageB()
{
	return 0;
}
