#include "translator.h"

using namespace valuescriptantlrgeneration;
using namespace antlr4;
using namespace std;

queue<ValuescriptError> warningList, errorList;
ProgramStorage* storage = nullptr;

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

int errorCheckStageC(int expected)
{
	if (!errorList.empty() && errorList.size() > expected) {
		delete[] errorList.front().message;
		errorList.pop();
	}
	return errorList.size();
}

int compileProcessStageA()
{
	storage = new ProgramStorage();
	return 0;
}

int compileProcessStageB(const wchar_t* script, const wchar_t* name)
{
	storage->addProgram(convert::wchartostr(script), convert::wchartostr(name));
	return 0;
}

int runtimeStageA()
{
	storage->executePrograms();
	return 0;
}

int runtimeStageB()
{
	storage->killPrograms();
	delete storage;
	return 0;
}

int runOnce(const wchar_t* script, const wchar_t* name)
{
	ValuescriptProgram prog(convert::wchartostr(name), convert::wchartostr(script));
	prog.executeOnce();
	return 0;
}

int ValuescriptProgram::executeOnce()
{
	executionist.visit(tree);
	return 0;
}

int ValuescriptProgram::execute(std::stop_token killswitch)
{
	while (!killswitch.stop_requested()) {
		executionist.visit(tree);
	}
	return 0;
}

int ProgramStorage::addProgram(std::string R, std::string N)
{
	programs.emplace(piecewise_construct,
		forward_as_tuple(N),
		forward_as_tuple(N, R));
	return 0;
}

int ProgramStorage::executePrograms()
{
	killswitch = stop_source();
	for (auto it = programs.begin(); it != programs.end(); it++) {
		threads.emplace_back(jthread(&ValuescriptProgram::execute, &(*it).second, killswitch.get_token()));
	}
	return 0;
}

int ProgramStorage::killPrograms()
{
	killswitch.request_stop();
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	threads.clear();
	return 0;
}
