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
		Identifier,
		NumericLiteral,
		StringLiteral,
		MemberExpression,
		CallExpression,
		UnaryExpression,
		BinaryExpression,
		MultiplicativeExpression,
		AdditiveExpression,
		ComparisonExpression,
		BooleanExpression,
		AssignmentExpression,
		IfStatement,
		ClassDeclaration,
		FunctionDeclaration,
		VariableDeclaration,
		TypenameExpression,
		UndefinedLiteral
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