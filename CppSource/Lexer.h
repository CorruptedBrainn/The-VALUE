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
		oparen,
		cparen,
		ocurly,
		ccurly,
		obrack,
		cbrack,
		oangle,
		cangle,
		binary,
		compar,
		unaryo,
		logico,
		assign,
		endcmd,
		eofcmd,
		colong,
		commag,
		period,
		string,
		number,
		identf,
		variab,
		funcin,
		classi,
		ifthis,
		elseth,
		statdc,
		constd,
		truthy,
		falsey,
	};

	// The data type used to store a token list
	typedef pair<string, token> lexpair;
	typedef vector<lexpair> token_list;

	// A private namespace
	namespace {
		inline static unordered_map<char, token> singlePairings = {
			{'(', token::oparen},
			{')', token::cparen},
			{'{', token::ocurly},
			{'}', token::ccurly},
			{'[', token::obrack},
			{']', token::cbrack},
			{'+', token::binary},
			{'-', token::binary},
			{'*', token::binary},
			{'/', token::binary},
			{'%', token::binary},
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
			{"&&", token::logico},
			{"||", token::logico},
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

	// The function to start the lexing process
	token_list lex(string sourceCode);
}

#endif