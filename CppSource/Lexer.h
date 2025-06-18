#pragma once

#include <string>
#include <queue>
#include <unordered_set>

#ifndef Lexer
#define Lexer

using namespace std;

/// <summary>
/// This namespace will store the functions used for the lexing process of translation
/// </summary>
namespace LEXER {
	
	// The types of each token
	enum class token {
		numeric, // Any integral literal
		floating, // Any decimal / floating point literal
		string, // Any string literal
		identifier, // Identifiers such as a function or variable
		arithmatic, // Arithmatic Operators
		assignment, // Any assignment operator
		keyword, // Any important keyword (ie "if" or "while")
		comparison, // == or != or && or ||
		// DON'T FORGET BOOLEAN OPERATORS FOR LATER WHEN I CAN BE BOTHERED
		oparen, // (
		cparen, // )
		obrace, // {
		cbrace, // }
		osharp, // <
		csharp, // >
		obracket, // [
		cbracket, // ]
		period, // .
		endline // ;
	};

	// The data type used to store a token list
	typedef queue<pair<string, token>> token_list;

	//
	namespace {
		const unordered_set<char> arithmatics = { '+', '-', '*', '/', '%' };
		const unordered_set<string> keywords = { "if", "else", "while", "for" , "true", "false"};
		const unordered_set<string> comparitors = { "&&", "||", "==", "!=" };
	}

	token_list lex(string sourceCode);
}

#endif