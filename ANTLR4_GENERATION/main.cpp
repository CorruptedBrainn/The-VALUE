/// Author: Nicolas Martens
/// Name: main.cpp
/// Description: The start point for anything Valuescript related, and the storage location for the function signatures

#define _CRT_SECURE_NO_WARNINGS 1

#include <chrono>
#include <thread>
#include <stop_token>
#include <unordered_map>

#include "antlr4-runtime.h"
#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"
#include "ValuescriptRuntime.cpp"

#define DLL_FUNCTION __declspec(dllexport)

#pragma execution_character_set("utf-8")

using namespace valuescriptantlrgeneration;
using namespace antlr4;

/// <summary>
/// Converts the contents of a wstring to a regular C++ string
/// </summary>
/// <param name="file">The wstring to convert to string</param>
/// <returns>The wstring as a C++ string</returns>
string string_conversion(wstring file) {
	// Do some cleanup to convert the text from wstring to string
	// Python stores strings as C style wstring, but we want strings instead
	size_t len = wcstombs(nullptr, file.c_str(), 0) + 1;
	char* buffer = new char[len];
	wcstombs(buffer, file.c_str(), len);
	string fileContents(buffer);
	delete[] buffer;
	return fileContents;
}

/// <summary>
/// The class containing the Abstract Syntax Tree of a Valuescript Program
/// </summary>
class ValuescriptProgram {
private:
	// The ANTLR4 classes storing the program
	ANTLRInputStream* input;
	ValuescriptLexer* lexer;
	CommonTokenStream* tokens;
	ValuescriptParser* parser;
	tree::ParseTree* tree;
	ValuescriptPreVisitor preprocess;
	ValuescriptVisitor* executionist;
public:
	/// <summary>
	/// Create the program and takes the program text, turning it into an Abstract Syntax Tree, then visiting it to deal with static data
	/// </summary>
	/// <param name="file">The contents of the Valuescript Program as a string</param>
	/// <param name="pipeline">A pointer to the thread safe queue to use</param>
	ValuescriptProgram(string file, string name,
		thread_safe_queue<call>* exportPipeline,
		thread_safe_queue<call>* importPipeline,
		thread_safe_queue<request>* requestPipeline,
		deque<request>* pushed) {
		input = new ANTLRInputStream(file);
		lexer = new ValuescriptLexer(input);
		tokens = new CommonTokenStream(lexer);
		parser = new ValuescriptParser(tokens);
		executionist = new ValuescriptVisitor(&preprocess, name, exportPipeline, importPipeline, requestPipeline, pushed);
		tree = parser->file();
		preprocess.visit(tree);
	}

	/// <summary>
	/// Delete the pointers we have to avoid memory leaks
	/// </summary>
	~ValuescriptProgram() {
		delete input;
		delete lexer;
		delete tokens;
		delete parser;
		delete executionist;
	}

	/// <summary>
	/// Execute a program, with a token killswitch so we can have parallelism
	/// </summary>
	/// <param name="killswitch">The stop token that will call the thread to kill itself</param>
	void execute(stop_token killswitch) {
		while (!killswitch.stop_requested()) {
			executionist->visit(tree);
		}
		return;
	}
};

/// <summary>
/// The storage container holding all of the Valuescript Programs
/// </summary>
class ProgramStorage {
private:
	inline static unordered_map<string, ValuescriptProgram> scripts;
	inline static vector<jthread> threads;
	inline static stop_source killswitch;
	inline static thread_safe_queue<call> exportPipeline;
	inline static thread_safe_queue<call> importPipeline;
	inline static thread_safe_queue<request> requestPipeline;
	inline static deque<call> pulled;
	inline static deque<request> pushed;
public:
	/// <summary>
	/// Add a new program to the storage
	/// </summary>
	/// <param name="name">The name of the program, to be indexed with</param>
	/// <param name="file">The contents / text of the program, to be parsed into something executable</param>
	/// <returns>Returns 0</returns>
	int addProgram(string name, string file) {
		removeProgram(name);
		scripts.emplace(piecewise_construct,
			forward_as_tuple(name),
			forward_as_tuple(file, name, &exportPipeline, &importPipeline, &requestPipeline, &pushed));
		return 0;
	}

	/// <summary>
	/// Removes a program from storage
	/// </summary>
	/// <param name="name">The name of the program to remove</param>
	/// <returns>Returns 0</returns>
	int removeProgram(string name) {
		if (scripts.contains(name)) scripts.erase(name);
		return 0;
	}

	/// <summary>
	/// Execute all the programs in storage in parallel
	/// </summary>
	/// <returns>Returns 0 when threads have halted</returns>
	int executePrograms() {
		// For all programs, create a new thread
		killswitch = stop_source();
		for (auto it = scripts.begin(); it != scripts.end(); it++) {
			threads.emplace_back(jthread(&ValuescriptProgram::execute, &(*it).second, killswitch.get_token()));
		}
		return 0;
	}

	/// <summary>
	/// Get the next variable change from the pipeline
	/// </summary>
	/// <returns>Information for the python scripts</returns>
	void* readExportPipeline() {
		pulled.emplace_back(exportPipeline.pop());
		return &(pulled.back());
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int killExportPipeline() {
		delete[] pulled.begin()->name;
		pulled.pop_front();
		return 0;
	}

	int updateImportPipeline(call change) {
		importPipeline.push(change);
		return 0;
	}

	void* readRequestPipeline() {
		pushed.emplace_back(requestPipeline.pop());
		return &(pushed.back());
	}

	int addRequestPipeline(request add) {
		requestPipeline.push(add);
		return 0;
	}

	/// <summary>
	/// Calls for all Valuescript Programs to be halted
	/// </summary>
	/// <returns>Returns 0 when threads have been told to stop</returns>
	int killPrograms() {
		// Call for the threads to stop
		killswitch.request_stop();
		// Wait for threads to join
		for (int i = 0; i < threads.size(); i++) {
			threads[i].join();
		}
		// Clear the thread array
		threads.clear();
		return 0;
	}
};

/// <summary>
/// Export all of my objects as functions to the DLL
/// </summary>
extern "C" {
	DLL_FUNCTION
		ProgramStorage* createStorage() {
		return new ProgramStorage();
	}
	DLL_FUNCTION
		int deleteStorage(ProgramStorage* obj) {
		delete obj;
		return 0;
	}
	DLL_FUNCTION
		int addProgram(ProgramStorage* obj, wchar_t* name, wchar_t* file) {
		return obj->addProgram(string_conversion(name), string_conversion(file));
	}
	DLL_FUNCTION
		int removeProgram(ProgramStorage* obj, wchar_t* name) {
		return obj->removeProgram(string_conversion(name));
	}
	DLL_FUNCTION
		int executePrograms(ProgramStorage* obj) {
		return obj->executePrograms();
	}
	DLL_FUNCTION
		void* readExportPipeline(ProgramStorage* obj) {
		return obj->readExportPipeline();
	}
	DLL_FUNCTION
		int killExportPipeline(ProgramStorage* obj) {
		return obj->killExportPipeline();
	}
	DLL_FUNCTION
		int updateImportPipeline(ProgramStorage* obj, wchar_t* name, int value) {
		size_t size = wcstombs(nullptr, name, 0) + 1;
		wchar_t* varName = new wchar_t[size];
		for (int i = 0; i < size; i++) varName[i] = name[i];
		return obj->updateImportPipeline(call(varName, value));
	}
	DLL_FUNCTION
		void* readRequestPipeline(ProgramStorage* obj) {
		return obj->readRequestPipeline();
	}
	DLL_FUNCTION
		int addRequestPipeline(ProgramStorage* obj, wchar_t* name, wchar_t* var) {
		size_t nameSize = wcstombs(nullptr, name, 0) + 1;
		wchar_t* fullName = new wchar_t[nameSize];
		for (int i = 0; i < nameSize; i++) fullName[i] = name[i];
		size_t varSize = wcstombs(nullptr, var, 0) + 1;
		wchar_t* varName = new wchar_t[varSize];
		for (int i = 0; i < varSize; i++) varName[i] = name[i];
		return obj->addRequestPipeline(request(fullName, varName));
	}
	DLL_FUNCTION
		int killPrograms(ProgramStorage* obj) {
		return obj->killPrograms();
	}
}