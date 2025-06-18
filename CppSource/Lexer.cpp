#include "Lexer.h"

using namespace LEXER;

token_list LEXER::lex(string sourceCode) {
	token_list tokenstream;
	for (int i = 0; i < sourceCode.size(); i++) {
		char character = sourceCode[i];
		if (character == ';') tokenstream.push({ ";", token::endline });
		else if (character == '(') tokenstream.push({ "(", token::oparen });
		else if (character == ')') tokenstream.push({ ")", token::cparen });
		else if (character == '{') tokenstream.push({ "{", token::obrace });
		else if (character == '}') tokenstream.push({ "}", token::cbrace });
		else if (character == '[') tokenstream.push({ "[", token::obracket });
		else if (character == ']') tokenstream.push({ "]", token::cbracket });
		else if (character == '<') tokenstream.push({ "<", token::osharp });
		else if (character == '>') tokenstream.push({ ">", token::csharp });
		else if (character == '.') tokenstream.push({ ".", token::period });
		else if (character == '\"') {
			string lexme = "";
			do {
				lexme += character;
				i++;
				character = sourceCode[i];
			} while (character != '\"' || sourceCode[i - 1] == '\\');
			tokenstream.push({ lexme, token::string });
			i--;
		}
		else if (isalpha(character)) {
			string lexme = "";
			do {
				lexme += character;
				i++;
				character = sourceCode[i];
			} while (isalpha(character));
			tokenstream.push({ lexme, keywords.contains(lexme) ? token::keyword : token::identifier });
			i--;
		}
		else if (isdigit(character)) {
			string lexme = "";
			bool integral = true;
			do {
				lexme += character;
				if (character == '.') integral = false;
				i++;
				character = sourceCode[i];
			} while (isdigit(character) || character == '.');
			tokenstream.push({ lexme, integral ? token::numeric : token::floating });
			i--;
		}
		else if (arithmatics.contains(character)) {
			string lexme = "";
			lexme += character;
			if (sourceCode[i + 1] == '=') {
				lexme += '=';
				i++;
				tokenstream.push({ lexme, token::assignment });
			}
			else tokenstream.push({ lexme, token::arithmatic });
		}
		else if (character == '&' || character == '=' || character == '|' || character == '!') {
			string lexme = "";
			lexme += character;
			lexme += sourceCode[i + 1];
			if (comparitors.contains(lexme)) {
				i++;
				tokenstream.push({ lexme, token::comparison });
			}
			else if (character == '=') tokenstream.push({ "=", token::assignment });
		}
	}
	return tokenstream;
}