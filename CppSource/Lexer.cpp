#include "Lexer.h"

using namespace LEXER;

/// <summary>
/// The function to start the lexing process
/// The process will take the source code and assign each value a token or type
/// </summary>
/// <param name="sourceCode">A string containing the untokenised source code</param>
/// <returns>Returns the source code split into items and tokens</returns>
token_list LEXER::lex(string sourceCode) {
	// The return list
	token_list tokenstream;
	// For every character in the code:
	for (int i = 0; i < sourceCode.size(); i++) {
		char character = sourceCode[i];
		// If the character is a known single character token
		if (singlePairings.contains(character)) {
			string lexme = "";
			lexme += character;
			lexpair item = { lexme, singlePairings[character] };
			// Double check it is not the end command character so we don't get an exception
			if (item.second == token::endcmd) {
				tokenstream.push(item);
				continue;
			}
			// Check that we're not skipping a multi-character token
			lexme += sourceCode[i + 1];
			if (multiPairings.contains(lexme)) {
				item = { lexme, multiPairings[lexme] };
			}
			tokenstream.push(item);
		}
		// For any string literal
		else if (character == '"') {
			string lexme = "";
			// Grab anything between the two " characters
			while (sourceCode[i + 1] != '"') {
				i++;
				lexme += sourceCode[i];
			}
			tokenstream.push({ lexme, token::string });
		}
		// For any numeric literal
		else if (isdigit(character)) {
			string lexme = "";
			lexme += character;
			// Keep grabbing integers until we hit something else
			while (isdigit(sourceCode[i + 1]) || sourceCode[i + 1] == '.') {
				i++;
				lexme += sourceCode[i];
			}
			tokenstream.push({ lexme, token::number });
		}
		// For any alphabetic literal
		else if (isalpha(character)) {
			string lexme = "";
			lexme += character;
			// Grab the whole word
			while (isalpha(sourceCode[i + 1])) {
				i++;
				lexme += sourceCode[i];
			}
			// Is it a known keyword?
			if (multiPairings.contains(lexme)) {
				tokenstream.push({ lexme, multiPairings[lexme] });
			}
			else {
				tokenstream.push({ lexme, token::identf });
			}
		}
	}
	// Push back the end of file token
	tokenstream.push({ "EOF", token::eofcmd });
	return tokenstream;
}