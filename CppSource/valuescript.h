#pragma once

#ifndef VALUESCRIPT_H
#define VALUESCRIPT_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <any>
#include <variant>
#include <stack>
#include <cctype>

/// <summary>
/// The namespace used for all Valuescript Language References
/// </summary>
namespace VS {
	/// <summary>
	/// A typesafe name to reference a list of parameters
	/// </summary>
	using param = std::unordered_map<std::string, std::any>;

	/// <summary>
	/// Any Enums I may use
	/// </summary>
	enum ENUMS {
		// NULL / void type
		VS_NULL,
		// For when variables are created
		VS_VARIABLE
	};

	/// <summary>
	/// Enums used to tell me the current compilation mode
	/// </summary>
	enum COMPILE_MODE {
		// When a command is just started, and the function has not been determined yet
		COMPILE_START_OF_COMMAND,
		// When we're getting general text / names
		COMPILE_GENERIC_TEXT,
		// When we're getting a string
		COMPILE_STRING
	};

	class COMPILE_ERROR {
	private:
		friend std::ostream& operator<<(std::ostream& os, const VS::COMPILE_ERROR& obj);
	public:
		int line = -1;
		std::wstring message = L"";
	};

	/// <summary>
	/// Prints some data about the return value
	/// </summary>
	/// <param name="os">The output stream object</param>
	/// <param name="obj">The error object to print data about</param>
	/// <returns>The output stream used -- is dealt with internally</returns>
	std::ostream& operator<<(std::ostream& os, const VS::COMPILE_ERROR& obj);

	/// <summary>
	/// The namespace to store internal Valuescript Types
	/// </summary>
	namespace INTERNAL {
		class VS_INTEGER {
		public:
			int data;
		};
	}

	/// <summary>
	/// The broard class to store return values from all VS functions
	/// </summary>
	class RETURN {
	private:
		friend std::ostream& operator<<(std::ostream& os, const VS::RETURN& obj);
	public:
		// Function name
		std::string name = "";
		// Sucessful or not
		int result = -1;
		// The actual return value
		std::variant<VS::ENUMS, int> value = VS_NULL;
	};

	/// <summary>
	/// Prints some data about the return value
	/// </summary>
	/// <param name="os">The output stream object</param>
	/// <param name="obj">The return object to print data about</param>
	/// <returns>The output stream used -- is dealt with internally</returns>
	std::ostream& operator<<(std::ostream& os, const VS::RETURN& obj);

	/// <summary>
	/// The CALLABLE structure to store data cleanly about a VS function
	/// </summary>
	struct CALLABLE {
		// Name of the function -- for lookup
		std::wstring function;
		// The arguments
		VS::param args;
	};

	/// <summary>
	/// Call this with a CALLABLE object to run a VS function
	/// </summary>
	/// <param name="obj">The CALLABLE object to run the function</param>
	/// <returns>A RETURN object with details on function execution</returns>
	VS::RETURN CALL(VS::CALLABLE& obj);

	/// <summary>
	/// The namespace to store Valuescript Initialising Functions
	/// </summary>
	namespace INITIALISERS {
		static inline std::unordered_set<std::wstring> members = {
			L"int", L"double", L"bool", L"str",
			L"coord", L"unit", L"foe",
			L"pair", L"array", L"queue", L"stack", L"map",
			L"func", L"class"
		};

		VS::RETURN INTEGER(VS::param& args);
		VS::RETURN DOUBLE(VS::param& args);
		VS::RETURN BOOLEAN(VS::param& args);
		VS::RETURN STRING(VS::param& args);

		VS::RETURN COORDINATE(VS::param& args);
		VS::RETURN UNIT(VS::param& args);
		VS::RETURN FOE(VS::param& args);
		
		VS::RETURN PAIR(VS::param& args);
		VS::RETURN ARRAY(VS::param& args);
		VS::RETURN QUEUE(VS::param& args);
		VS::RETURN STACK(VS::param& args);
		VS::RETURN MAP(VS::param& args);

		VS::RETURN FUNCTION(VS::param& args);
		VS::RETURN CLASS(VS::param& args);
	}

	/// <summary>
	/// The namespace to store Valuescript Operators
	/// </summary>
	namespace OPERATORS {
		static inline std::unordered_set<std::wstring> members = {
			L"add", L"subtract", L"multiply", L"divide", L"modulo",
			L"bit_and", L"bit_or", L"bit_not", L"bit_xor", L"assign",
			L"equals", L"not_equals", L"and", L"or", L"not"
		};

		VS::RETURN ADD(VS::param& args);
		VS::RETURN SUBTRACT(VS::param& args);
		VS::RETURN MULTIPLY(VS::param& args);
		VS::RETURN DIVIDE(VS::param& args);
		VS::RETURN MODULUS(VS::param& args);
		VS::RETURN BIT_AND(VS::param& args);
		VS::RETURN BIT_OR(VS::param& args);
		VS::RETURN BIT_NOT(VS::param& args);
		VS::RETURN BIT_XOR(VS::param& args);
		VS::RETURN ASSIGNMENT(VS::param& args);

		VS::RETURN EQUALITY(VS::param& args);
		VS::RETURN UNEQUALITY(VS::param& args);
		VS::RETURN BOOL_AND(VS::param& args);
		VS::RETURN BOOL_OR(VS::param& args);
		VS::RETURN BOOL_NOT(VS::param& args);
	}

	/// <summary>
	/// The namespace to store Valuescript Condition Checkers
	/// </summary>
	namespace CONDITIONALS {
		static inline std::unordered_set<std::wstring> members = {
			L"if", L"else", L"while", L"for"
		};

		VS::RETURN VS_IF(VS::param& args);
		VS::RETURN VS_ELSE(VS::param& args);
		VS::RETURN VS_WHILE(VS::param& args);
		VS::RETURN VS_FOR(VS::param& args);
	}

	/// <summary>
	/// The namespace to store Valuescript Callable Functions
	/// </summary>
	namespace FUNCTIONS {
		static inline std::unordered_set<std::wstring> members = {
			L"max", L"min", L"abs",
			L"print"
		};
		
		VS::RETURN MAXIMUM(VS::param& args);
		VS::RETURN MINIMUM(VS::param& args);
		VS::RETURN ABSOLUTE_VALUE(VS::param& args);

		VS::RETURN PRINT(VS::param& args);
	}

	/// <summary>
	/// The namespace to store Valuescript Decoration Functions
	/// </summary>
	namespace DECORATORS {
		static inline std::unordered_set<std::wstring> members = {
			L"static", L"const"
		};

		VS::RETURN VS_STATIC(VS::param& args);
		VS::RETURN VS_CONST(VS::param& args);
	}

	/// <summary>
	/// The unordered map (hashmap) to store all functions and their respective callables
	/// </summary>
	inline static std::unordered_map<std::wstring, std::function<VS::RETURN(VS::param&)>> DEFINITIONS = {
		// Base Variable Types
		{L"int", VS::INITIALISERS::INTEGER},
		{L"double", VS::INITIALISERS::DOUBLE},
		{L"bool", VS::INITIALISERS::BOOLEAN},
		{L"str", VS::INITIALISERS::STRING},
		// Game Specific Types
		{L"coord", VS::INITIALISERS::COORDINATE},
		{L"unit", VS::INITIALISERS::UNIT},
		{L"foe", VS::INITIALISERS::FOE},
		// Complex Data Structures
		{L"pair", VS::INITIALISERS::PAIR},
		{L"array", VS::INITIALISERS::ARRAY},
		{L"queue", VS::INITIALISERS::QUEUE},
		{L"stack", VS::INITIALISERS::STACK},
		{L"map", VS::INITIALISERS::MAP},
		// Other Data Structures
		{L"func", VS::INITIALISERS::FUNCTION},
		{L"class", VS::INITIALISERS::CLASS},
		// Basic Operators
		{L"add", VS::OPERATORS::ADD},
		{L"subtract", VS::OPERATORS::SUBTRACT},
		{L"multiply", VS::OPERATORS::MULTIPLY},
		{L"divide", VS::OPERATORS::DIVIDE},
		{L"modulo", VS::OPERATORS::MODULUS},
		{L"bit_and", VS::OPERATORS::BIT_AND},
		{L"bit_or", VS::OPERATORS::BIT_OR},
		{L"bit_not", VS::OPERATORS::BIT_NOT},
		{L"bit_xor", VS::OPERATORS::BIT_XOR},
		{L"assign", VS::OPERATORS::ASSIGNMENT},
		// Decorations
		{L"static", VS::DECORATORS::VS_STATIC},
		{L"const", VS::DECORATORS::VS_CONST},
		// Condition Checkers
		{L"if", VS::CONDITIONALS::VS_IF},
		{L"else", VS::CONDITIONALS::VS_ELSE},
		{L"while", VS::CONDITIONALS::VS_WHILE},
		{L"for", VS::CONDITIONALS::VS_FOR},
		// Logical Operators
		{L"equals", VS::OPERATORS::EQUALITY},
		{L"not_equals", VS::OPERATORS::UNEQUALITY},
		{L"and", VS::OPERATORS::BOOL_AND},
		{L"or", VS::OPERATORS::BOOL_OR},
		{L"not", VS::OPERATORS::BOOL_NOT},
		// Predefined Math Functions
		{L"max", VS::FUNCTIONS::MAXIMUM},
		{L"min", VS::FUNCTIONS::MINIMUM},
		{L"abs", VS::FUNCTIONS::ABSOLUTE_VALUE},
		// Debugger Functions
		{L"print", VS::FUNCTIONS::PRINT}
	};

	/// <summary>
	/// Parses the contents of a TVSF string (Valuescript-Formatted Text) into callable commands
	/// </summary>
	/// <param name="contents">The text to be parsed and compiled</param>
	/// <returns>A queue of callables for the code to use at runtime</returns>
	std::queue<VS::CALLABLE> COMPILE(std::wstring& contents, VS::COMPILE_ERROR& err);
}

#endif