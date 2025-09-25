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

class ValuescriptWarningListener : public BaseErrorListener {
private:
	queue<ValuescriptError>& warningList;
public:
	ValuescriptWarningListener(queue<ValuescriptError>& list) : warningList{ list } {}

	void syntaxError(Recognizer* recogniser, Token* offendingSymbol, size_t line, size_t charPositionInLine,
		const string& msg, exception_ptr e) override;
};