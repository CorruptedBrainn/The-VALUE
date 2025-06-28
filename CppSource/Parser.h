#pragma once

#include "Lexer.h"
#include <any>

#ifndef Parser
#define Parser

using namespace std;

/// <summary>
/// This namespace will store the functions used for the parsing process of translation
/// </summary>
namespace PARSER {

	// The types of each command
	enum class command {
		Identifier, // Any user defined (or language defined) identifiers
		NumericLiteral, // Any numeric value
		StringLiteral, // Any string value
		MemberExpression, // Any member value (eg list.size())
		CallExpression, // Calling a function
		UnaryExpression, // Any expression with a single operand (such as !true)
		BinaryExpression, // Should be called BitwiseExpression
		MultiplicativeExpression, // For any multiplication expressions
		AdditiveExpression, // Any addition expressions
		ComparisonExpression, // Comparisons such as equality
		BooleanExpression, // Boolean logical operators
		AssignmentExpression, // variable = value
		IfStatement, // if this then that
		ClassDeclaration, // Declaring a class
		FunctionDeclaration, // Declaring a function
		VariableDeclaration, // Declaring a variable
		TypenameExpression, // Declaring a type
		UndefinedLiteral // UNDEFINED / NULL / some non-existant value
	};

	// The class to store a node within the Abstract Syntax Tree
	class AST_Node {
	public:
		command type;
		unordered_map<string, any> data;
		AST_Node(command arg, unordered_map<string, any> children) {
			type = arg;
			data = children;
		}
	};

	vector<AST_Node> parse(LEXER::token_list tokenstream);
}

#endif