#include "Parser.h"
#include <vector>

using namespace PARSER;

// Declare the existance of a few functions before defining them
// Done for the compiler so it knows a function exists when converting to assembly

static AST_Node parseVariableDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseFunctionDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseClassDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseIfStatement(LEXER::token_list& tokenstream);
static AST_Node parseExpression(LEXER::token_list& tokenstream);
static AST_Node parseAssignment(LEXER::token_list& tokenstream);
static AST_Node parseObjectExpression(LEXER::token_list& tokenstream);
static AST_Node parseBoolean(LEXER::token_list& tokenstream);
static AST_Node parseComparison(LEXER::token_list& tokenstream);
static AST_Node parseAdditive(LEXER::token_list & tokenstream);
static AST_Node parseMultiplicative(LEXER::token_list& tokenstream);
static AST_Node parseBinary(LEXER::token_list& tokenstream);
static AST_Node parseUnary(LEXER::token_list& tokenstream);
static AST_Node parseFunctionCalls(LEXER::token_list& tokenstream);
static AST_Node parseObjectMember(LEXER::token_list& tokenstream);
static AST_Node parsePrimary(LEXER::token_list& tokenstream);
static AST_Node parseStatement(LEXER::token_list& tokenstream);

static LEXER::lexpair grabFront(LEXER::token_list& tokenstream) {
	return tokenstream.front();
}

static LEXER::lexpair moveFront(LEXER::token_list& tokenstream) {
	LEXER::lexpair ret = tokenstream.front();
	tokenstream.pop();
	return ret;
}

static AST_Node parseVariableDeclaration(LEXER::token_list& tokenstream) {
	
}

static AST_Node parseFunctionDeclaration(LEXER::token_list& tokenstream) {

}

static AST_Node parseClassDeclaration(LEXER::token_list& tokenstream) {

}

static AST_Node parseIfStatement(LEXER::token_list& tokenstream) {

}

static AST_Node parseExpression(LEXER::token_list& tokenstream) {

}

static AST_Node parseAssignment(LEXER::token_list& tokenstream) {

}

static AST_Node parseObjectExpression(LEXER::token_list& tokenstream) {
	
}

static AST_Node parseBoolean(LEXER::token_list& tokenstream) {
	AST_Node object = parseComparison(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::boolea) {
		LEXER::lexpair current = moveFront(tokenstream);
		object = AST_Node(command::BooleanExpression, {
			{"left", object},
			{"operator", current},
			{"right", parseComparison(tokenstream)}
			});
	}
	return object;
}

static AST_Node parseComparison(LEXER::token_list& tokenstream) {
	AST_Node object = parseAdditive(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::compar) {
		LEXER::lexpair current = moveFront(tokenstream);
		object = AST_Node(command::ComparisonExpression, {
			{"left", object},
			{"operator", current},
			{"right", parseAdditive(tokenstream)}
			});
	}
	return object;
}

static AST_Node parseAdditive(LEXER::token_list& tokenstream) {
	AST_Node object = parseMultiplicative(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::addito) {
		LEXER::lexpair current = moveFront(tokenstream);
		object = AST_Node(command::AdditiveExpression, {
			{"left", object},
			{"operator", current},
			{"right", parseMultiplicative(tokenstream)}
			});
	}
	return object;
}

static AST_Node parseMultiplicative(LEXER::token_list& tokenstream) {
	AST_Node object = parseBinary(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::multio) {
		LEXER::lexpair current = moveFront(tokenstream);
		object = AST_Node(command::MultiplicativeExpression, {
			{"left", object},
			{"operator", current},
			{"right", parseBinary(tokenstream)}
			});
	}
	return object;
}

static AST_Node parseBinary(LEXER::token_list& tokenstream) {
	AST_Node object = parseUnary(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::binary) {
		LEXER::lexpair current = moveFront(tokenstream);
		object = AST_Node(command::BinaryExpression, {
			{"left", object},
			{"operator", current},
			{"right", parseUnary(tokenstream)}
			});
	}
	return object;
}

static AST_Node parseUnary(LEXER::token_list& tokenstream) {
	if (grabFront(tokenstream).second == LEXER::token::unaryo) {
		LEXER::lexpair current = moveFront(tokenstream);
		return AST_Node(command::UnaryExpression, {
			{"operator", current.first},
			{"right", parseUnary(tokenstream)}
			});
	}
	return parseFunctionCalls(tokenstream);
}

static AST_Node parseFunctionCalls(LEXER::token_list& tokenstream) {
	AST_Node object = parseObjectMember(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::oparen) {
		moveFront(tokenstream);
		vector<AST_Node> args = {};
		if (grabFront(tokenstream).second != LEXER::token::cparen) {
			do {
				args.push_back(parseExpression(tokenstream));
			} while (moveFront(tokenstream).second == LEXER::token::commag);
			if (grabFront(tokenstream).second != LEXER::token::cparen) {
				// Throw an error
				throw 0;
			}
		}
		object = AST_Node(command::CallExpression, {
			{"caller", object},
			{"arguments", args}
			});
	}
	return object;
}

static AST_Node parseObjectMember(LEXER::token_list& tokenstream) {
	AST_Node object = parsePrimary(tokenstream);
	while (grabFront(tokenstream).second == LEXER::token::period) {
		moveFront(tokenstream);
		AST_Node member = parsePrimary(tokenstream);
		if (member.type != command::Identifier) {
			// Throw an error
			throw 0;
		}
		object = AST_Node(command::MemberExpression, {
			{"object", object},
			{"member", member}
			});
	}
	return object;
}

static AST_Node parsePrimary(LEXER::token_list& tokenstream) {
	LEXER::lexpair current = moveFront(tokenstream);
	switch (current.second) {
	case LEXER::token::identf:
	{
		return AST_Node(command::Identifier, {
			{"value", current.first}
			});
	}
	case LEXER::token::number:
	{
		return AST_Node(command::NumericLiteral, {
			{"value", stod(current.first)}
			});
	}
	case LEXER::token::string:
	{
		return AST_Node(command::StringLiteral, {
			{"value", current.first}
			});
	}
	case LEXER::token::oparen:
	{
		AST_Node object = parseExpression(tokenstream);
		current = moveFront(tokenstream);
		if (current.second != LEXER::token::cparen) {
			// Throw an error
			throw 0;
		}
		return object;
	}
	default:
	{
		// Throw an error
		throw 0;
	}
	}
}

static AST_Node parseStatement(LEXER::token_list& tokenstream) {
	LEXER::lexpair current = grabFront(tokenstream);
	switch (current.second) {
	case LEXER::token::variab:
		moveFront(tokenstream);
		return parseVariableDeclaration(tokenstream);
	case LEXER::token::funcin:
		moveFront(tokenstream);
		return parseFunctionDeclaration(tokenstream);
	case LEXER::token::classi:
		moveFront(tokenstream);
		return parseClassDeclaration(tokenstream);
	case LEXER::token::ifthis:
		moveFront(tokenstream);
		return parseIfStatement(tokenstream);
	default:
		return parseExpression(tokenstream);
	}
}

vector<AST_Node> PARSER::parse(LEXER::token_list tokenstream)
{
	vector<AST_Node> program;
	while (!tokenstream.empty()) {
		program.push_back(parseStatement(tokenstream));
	}
	return program;
}
