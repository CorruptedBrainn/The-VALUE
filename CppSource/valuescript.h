#pragma once

#ifndef VALUESCRIPT_H
#define VALUESCRIPT_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <functional>
#include <any>
#include <variant>

/// <summary>
/// The namespace used for all Valuescript Language References
/// </summary>
namespace VS {
	/// <summary>
	/// A typesafe name to reference a list of parameters
	/// </summary>
	using param = std::vector<std::any>;

	/// <summary>
	/// Any Enums I may use
	/// </summary>
	enum ENUMS {
		// NULL (void type)
		VS_NULL,
		// Variable (for when variables are created)
		VS_VARIABLE
	};

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
	/// The namespace to store Valuescript Types
	/// </summary>
	namespace TYPES {
		// TODO: REWRITE TYPE STRUCTURE FOR PROPER PARAMETERS (param& args rewrite)
		VS::RETURN INT(VS::param& args);
		VS::RETURN DOUBLE(VS::param& args);
		VS::RETURN BOOLEAN(VS::param& args);
		VS::RETURN STRING(VS::param& args);
	}

	/// <summary>
	/// The namespace to store Valuescript Callables
	/// </summary>
	namespace FUNCTIONS {
		/// <summary>
		/// Print some stuff -- TODO: REWRITE FOR DEBUGGER MODE
		/// </summary>
		/// <param name="args">args[0] should store a wstring to print</param>
		/// <returns>0 to indicate success, and VS_NULL as a placeholder</returns>
		VS::RETURN PRINT(VS::param& args);
	}
	/// <summary>
	/// The unordered map (hashmap) to store all function keywords and their respective callables
	/// </summary>
	inline static std::unordered_map<std::wstring, std::function<VS::RETURN(VS::param&)>> DEFINITIONS = {
		{L"print", VS::FUNCTIONS::PRINT},
		{L"int", VS::TYPES::INT},
		{L"double", VS::TYPES::DOUBLE},
		{L"bool", VS::TYPES::BOOLEAN},
		{L"str", VS::TYPES::STRING}
	};

	/// <summary>
	/// Parses the contents of a TVSF string (Valuescript-Formatted Text) into callable commands
	/// </summary>
	/// <param name="contents">The text to be parsed and compiled</param>
	/// <returns>A queue of callables for the code to use at runtime</returns>
	std::queue<VS::CALLABLE> COMPILE(std::wstring& contents);
}

#endif