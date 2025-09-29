#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#pragma execution_character_set("utf-8")

#include <string>
#include <queue>

#include "translator.h"

#include "antlr4-runtime.h"

using namespace antlr4;
using namespace std;

struct ValuescriptError;

class ValuescriptErrorListener : public BaseErrorListener {
private:
	queue<ValuescriptError>& errorList;
public:
	ValuescriptErrorListener(queue<ValuescriptError>& list) : errorList{ list } {}

	void syntaxError(Recognizer* recogniser, Token* offendingSymbol, size_t line, size_t charPositionInLine,
		const string& msg, exception_ptr e) override;
};