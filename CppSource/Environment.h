#pragma once

#include <any>
#include <string>
#include <unordered_map>
#include <unordered_set>

#ifndef Environment
#define Environment

using namespace std;

namespace ENVIRONMENT {
	class environment {
	private:
		unordered_map<string, any> variables;
		unordered_set<string> constants;
		unordered_set<string> statics;
		environment* parent = nullptr;

		environment* lookup(string variable);
	public:
		environment(environment* parent = nullptr);
		~environment();

		any declareVariable(string name, any value, bool constant, bool staticvar);
		any assignVariable(string name, any value);
		any getValue(string name);
	};
};

#endif