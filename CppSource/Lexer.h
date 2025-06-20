#pragma once

#include <string>
#include <queue>
#include <unordered_map>

#ifndef Lexer
#define Lexer

using namespace std;

/// <summary>
/// This namespace will store the functions used for the lexing process of translation
/// </summary>
namespace LEXER {
	
	// The types of each token
	enum class token {
		oparen, // (
		cparen, // )
		ocurly, // {
		ccurly, // }
		obrack, // [
		cbrack, // ]
		oangle, // <
		cangle, // >
		addito, // Any additive operator (eg '+')
		multio, // Any multiplicative operator (eg '%')
		binary, // Any binary operator (eg '&')
		compar, // Any comparison operator (eg '<=')
		unaryo, // Any operator that has one component (eg '!')
		boolea, // Any boolean operator (like 'and' / '&&')
		assign, // Any assignment operator (eg '=')
		endcmd, // ;
		eofcmd, // The end of file token (Written as "EOF")
		colong, // :
		commag, // ,
		period, // .
		string, // Any string literal (surrounded in ")
		number, // Any numeric literal
		identf, // Any custom non-keyword string (such as int)
		variab, // The "var" keyword
		funcin, // The "func" keyword
		classi, // The "class" keyword
		ifthis, // The "if" keyword
		elseth, // The "else" keyword
		statdc, // The "static" keyword
		constd, // The "const" keyword
		truthy, // The "true" keyword
		falsey, // The "false" keyword
	};

	// The data type used to store a token list
	typedef pair<string, token> lexpair;
	typedef queue<lexpair> token_list;

	// A private namespace to keep this list strictly bound to Lexer.cpp
	namespace {
		inline static unordered_map<char, token> singlePairings = {
			{'(', token::oparen},
			{')', token::cparen},
			{'{', token::ocurly},
			{'}', token::ccurly},
			{'[', token::obrack},
			{']', token::cbrack},
			{'+', token::addito},
			{'-', token::addito},
			{'*', token::multio},
			{'/', token::multio},
			{'%', token::multio},
			{'&', token::binary},
			{'|', token::binary},
			{'^', token::binary},
			{'!', token::unaryo},
			{'<', token::oangle},
			{'>', token::cangle},
			{'=', token::assign},
			{';', token::endcmd},
			{':', token::colong},
			{',', token::commag},
			{'.', token::period}
		};
		inline static unordered_map<string, token> multiPairings = {
			{"==", token::compar},
			{"<=", token::compar},
			{">=", token::compar},
			{"!=", token::compar},
			{"&&", token::boolea},
			{"||", token::boolea},
			{"+=", token::assign},
			{"-=", token::assign},
			{"*=", token::assign},
			{"/=", token::assign},
			{"%=", token::assign},
			{"var", token::variab},
			{"func", token::funcin},
			{"class", token::classi},
			{"if", token::ifthis},
			{"else", token::elseth},
			{"static", token::statdc},
			{"true", token::truthy},
			{"faslse", token::falsey}
		};
	}

	token_list lex(string sourceCode);
}

#endif