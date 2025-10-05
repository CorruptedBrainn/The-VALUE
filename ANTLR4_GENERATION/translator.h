#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define DLL_EXPORT __declspec(dllexport)

#pragma execution_character_set("utf-8")

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <thread>

#include "runtime.h"
#include "warnings.h"
#include "custom_errors.h"
#include "rules.h"

#include "antlr4-runtime.h"
#include "..\generated\ValuescriptLexer.h"
#include "..\generated\ValuescriptParser.h"

namespace convert {
	std::string chartostr(const char* input);
	std::string wchartostr(const wchar_t* input);
	std::string wstrtostr(std::wstring input);
	std::wstring chartowstr(const char* input);
	std::wstring wchartowstr(const wchar_t* input);
	std::wstring strtowstr(std::string input);
	char* wchartochar(const wchar_t* input);
	char* strtochar(std::string input);
	char* wstrtochar(std::wstring input);
	wchar_t* chartowchar(const char* input);
	wchar_t* strtowchar(std::string input);
	wchar_t* wstrtowchar(std::wstring input);
}

extern "C" {
	struct DLL_EXPORT ValuescriptError {
		const wchar_t* message;
		int lineAt;
		int characterAt;
	};

	DLL_EXPORT int scriptCheckStageA(const wchar_t* script);
	DLL_EXPORT ValuescriptError scriptCheckStageB();
	DLL_EXPORT int scriptCheckStageC(int expected);

	DLL_EXPORT int errorCheckStageA(const wchar_t* script);
	DLL_EXPORT ValuescriptError errorCheckStageB();
	DLL_EXPORT int errorCheckStageC(int expected);

	DLL_EXPORT int compileProcessStageA();
	DLL_EXPORT int compileProcessStageB(const wchar_t* script, const wchar_t* name);
	DLL_EXPORT int compileProcessStageC();

	DLL_EXPORT int runtimeStageA();
	DLL_EXPORT int runtimeStageB();
}

/// The stages:
/// 1) While writing, analyse and give warnings
/// 2) Before executing, deal with parse rules and save to files if so (for every script)
/// 3) Create player-defined classes with another parse
/// 4) Execute each script continuously
/// At the end of every scope, delete appropriate non-static variables to avoid a static scoping ruleset
/// Use factories for everything
/// Store scripts by name

/// Stage: Script Check (for current script)
/// A: Repeatedly generate a list of warnings in a queue
/// B: Return the front warning in the queue
/// C: Remove the front warning in the queue

/// Stage: Error Check (for all scripts)
/// A: Check a single script and generate list of errors
/// B: Return front error in queue
/// C: Remove front error in queue

/// Stage: Compile and Process (for all scripts)
/// A: Create the storage
/// B: For each script, compile it and put it in the storage container
/// C: register the classes and functions for all scripts

/// Stage: Runtime (for all scripts)
/// A: Create the threads and execute, will have some way to communicate to python
/// B: Stop threads, destroy storage

/// Other: needs way to communicate during runtime