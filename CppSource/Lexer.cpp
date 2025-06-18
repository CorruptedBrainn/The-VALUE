#include "Lexer.h"

using namespace LEXER;

token_list LEXER::lex(string sourceCode) {
	token_list tokenstream;
	for (int i = 0; i < sourceCode.size(); i++) {
		char character = sourceCode[i];
		if (singlePairings.contains(character)) {
			string lexme = "";
			lexme += character;
			lexpair item = { lexme, singlePairings[character] };
			if (item.second == token::endcmd) {
				tokenstream.push_back(item);
				continue;
			}
			lexme += sourceCode[i + 1];
			if (multiPairings.contains(lexme)) {
				item = { lexme, multiPairings[lexme] };
			}
			tokenstream.push_back(item);
		}
		else if (character == '"') {
			string lexme = "" + character;
			while (sourceCode[i] != '"') {
				i++;
				lexme += sourceCode[i];
			}
			tokenstream.push_back({ lexme, token::string });
		}
		else if (isdigit(character)) {
			string lexme = "";
			lexme += character;
			while (isdigit(sourceCode[i + 1])) {
				i++;
				lexme += sourceCode[i];
			}
			tokenstream.push_back({ lexme, token::number });
		}
		else if (isalpha(character)) {
			string lexme = "";
			lexme += character;
			while (isalpha(sourceCode[i + 1])) {
				i++;
				lexme += sourceCode[i];
			}
			if (multiPairings.contains(lexme)) {
				tokenstream.push_back({ lexme, multiPairings[lexme] });
			}
			else {
				tokenstream.push_back({ lexme, token::identf });
			}
		}
	}
	tokenstream.push_back({ "EOF", token::eofcmd });
	return tokenstream;
}