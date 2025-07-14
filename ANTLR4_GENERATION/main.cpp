#define _CRT_SECURE_NO_WARNINGS 1

#include "Python.h"

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

class ValuescriptProgram {
private:
	ANTLRInputStream* input;
	ValuescriptLexer* lexer;
	CommonTokenStream* tokens;
	ValuescriptParser* parser;
	tree::ParseTree* tree;
	ValuescriptPreVisitor preprocess;
	ValuescriptVisitor executionist;
public:
	ValuescriptProgram(string file) {
		input = new ANTLRInputStream(file);
		lexer = new ValuescriptLexer(input);
		tokens = new CommonTokenStream(lexer);
		parser = new ValuescriptParser(tokens);
		tree = parser->file();
		preprocess.visit(tree);
	}

	~ValuescriptProgram() {
		delete[] input;
		delete[] lexer;
		delete[] tokens;
		delete[] parser;
	}

	void execute(stop_token killswitch) {
		while (!killswitch.stop_requested()) {
			executionist.visit(tree);
		}
		return;
	}
};

class ProgramStorage {
private:
	inline static unordered_map<string, ValuescriptProgram> scripts;
public:
	int addProgram(string name, string file) {
		removeProgram(name);
		scripts.emplace(name, file);
		return 0;
	}

	int removeProgram(string name) {
		if (scripts.contains(name)) scripts.erase(name);
		return 0;
	}

	int executePrograms() {
		vector<jthread> threads;
		stop_source killswitch;
		for (auto it = scripts.begin(); it != scripts.end(); it++) {
			threads.emplace_back(jthread(&ValuescriptProgram::execute, &(*it).second, killswitch.get_token()));
		}
		this_thread::sleep_for(1000000000ms); // Let this thread move on to environment tasks
		killswitch.request_stop();
		for (int i = 0; i < threads.size(); i++) {
			threads[i].join();
		}
		return 0;
	}
};

extern "C" {
	DLL_FUNCTION
		ProgramStorage* createStorage() {
		return new ProgramStorage();
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
}

/*
TEST:

@typenames: data
segment_tree {
	size->int = 0;
	tree->array<data> = {};

	update(pos->int, val->data, i->int = 0, l->int = 0, r->int = size - 1)->data {
		if (l == r) return tree[i] += val;
		m->int = (l + r ) / 2;
		if (pos <= m) return tree[i] = update(pos, val, i + 1, l, m) + tree[i + 2 * (m - l + 1)];
		else return tree[i] = tree[i + 1] + update(pos, val, i + 2 * (m - l + 1), m + 1, r);
	}

	query(posl->int, posr->int, i->int = 0, l->int = 0, r->int = size - 1)->data {
		if (posl <= l && r <= posr) return tree[i];
		if (r < posl || posr < l) return NULL;
		m->int = (l + r) / 2;
		return query(posl, posr, i + 1, l, m) + query(posl, posr, i + 2 * (m - l + 1), m + 1, r);
	}
}

static segtree->segment_tree<int>;
print(segtree.query(2, 4));
*/