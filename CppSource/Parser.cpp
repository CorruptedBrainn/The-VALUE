// Code from my achievement standard
// Using this because it was open and I am lazy
// It is bugged and unfinished :/

#include "Parser.h"
#include <vector>
#include <exception>

using namespace PARSER;

// Declare the existance of a few functions before defining them
// Done for the compiler so it knows a function exists when converting to assembly

static AST_Node parseVariableDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseDecorationDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseTypenames(LEXER::token_list& tokenstream);
static AST_Node parseFunctionDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseClassDeclaration(LEXER::token_list& tokenstream);
static AST_Node parseIfStatement(LEXER::token_list& tokenstream);
static vector<AST_Node> parseExecutionBlock(LEXER::token_list& tokenstream);
static AST_Node parseExpression(LEXER::token_list& tokenstream);
static AST_Node parseAssignment(LEXER::token_list& tokenstream);
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
	moveFront(tokenstream);
	if (moveFront(tokenstream).second != LEXER::token::oangle) {
		throw exception("Open Angle Bracket expected in variable declaration.");
	}
	AST_Node type = parseTypenames(tokenstream);
	LEXER::lexpair current = moveFront(tokenstream);
	AST_Node value(command::UndefinedLiteral, {});
	if (current.second != LEXER::token::identf) {
		throw exception("Identifier expected in variable declaration.");
	}
	if (grabFront(tokenstream).second == LEXER::token::assign) {
		moveFront(tokenstream);
		value = parseExpression(tokenstream);
	}
	return AST_Node(command::VariableDeclaration, {
		{"name", current.first},
		{"type", type},
		{"static", false},
		{"const", false},
		{"value", value}
		});
}

static AST_Node parseDecorationDeclaration(LEXER::token_list& tokenstream) {
	LEXER::lexpair current = moveFront(tokenstream);
	AST_Node object = parseStatement(tokenstream);
	if (object.type != command::VariableDeclaration && object.type != command::FunctionDeclaration) {
		throw exception("Variable or Function Declaration expected after decoration.");
	}
	if (current.second == LEXER::token::statdc) {
		object.data["static"] = true;
	}
	else if (current.second == LEXER::token::constd) {
		object.data["const"] = true;
		if (object.type == command::VariableDeclaration) {
			if (any_cast<AST_Node>(object.data["value"]).type == command::UndefinedLiteral) {
				throw exception("Unassigned value with constant variable declaration.");
			}
		}
	}
	return object;
}

static AST_Node parseTypenames(LEXER::token_list& tokenstream) {
	LEXER::lexpair current = moveFront(tokenstream);
	AST_Node object(command::TypenameExpression, {
		{"type", current.first},
		{"child", vector<AST_Node>{}}
		});
	if (current.second != LEXER::token::identf && current.second != LEXER::token::vardec) {
		throw exception("Cannot have empty typename in typename declaration.");
	}
	/*if (grabFront(tokenstream).second == LEXER::token::oangle) {
		moveFront(tokenstream);
		any_cast<vector<AST_Node>>(object.data["child"]).push_back(parseTypenames(tokenstream));
		while (grabFront(tokenstream).second == LEXER::token::commag) {
			moveFront(tokenstream);
			any_cast<vector<AST_Node>>(object.data["child"]).push_back(parseTypenames(tokenstream));
		}
		if (moveFront(tokenstream).second != LEXER::token::cangle) {
			throw exception("Closed angle bracket expected in typename declaration.");
		}
	}
	current = grabFront(tokenstream);
	if (current.second != LEXER::token::oangle && moveFront(tokenstream).second != LEXER::token::cangle && grabFront(tokenstream).second != LEXER::token::commag) {
		throw exception("Cannot have empty typename in typename declaration.");
	}*/
	// Expect either < or > or ,
	// < should call recursively, after which we will end on a >
	// , should call iteratively, after which we will land on a >
	// > should return and move forward
	while (grabFront(tokenstream).second == LEXER::token::oangle || grabFront(tokenstream).second == LEXER::token::commag) {
		moveFront(tokenstream);
		any_cast<vector<AST_Node>>(object.data["child"]).push_back(parseTypenames(tokenstream));
	}
	if (moveFront(tokenstream).second != LEXER::token::cangle) {
		throw exception("Closed angle bracket expected in typename declaration.");
	}
	return object;
}

static AST_Node parseFunctionDeclaration(LEXER::token_list& tokenstream) {
	moveFront(tokenstream);
	if (moveFront(tokenstream).second != LEXER::token::oangle) {
		throw exception("Open angle bracket expected in function declaration.");
	}
	AST_Node type = parseTypenames(tokenstream);
	LEXER::lexpair current = moveFront(tokenstream);
	if (current.second != LEXER::token::identf) {
		throw exception("Identifier expected in function declaration.");
	}
	if (moveFront(tokenstream).second != LEXER::token::oparen) {
		throw exception("Open parentheses expected in function declaration.");
	}
	vector<AST_Node> parameters;
	if (grabFront(tokenstream).second != LEXER::token::cparen) {
		parameters.push_back(parseVariableDeclaration(tokenstream));
		while (grabFront(tokenstream).second == LEXER::token::commag) {
			moveFront(tokenstream);
			parameters.push_back(parseVariableDeclaration(tokenstream));
		}
	}
	if (moveFront(tokenstream).second != LEXER::token::cparen) {
		throw exception("Closed parentheses expected in function declaration.");
	}
	vector<AST_Node> body = parseExecutionBlock(tokenstream);
	return AST_Node(command::FunctionDeclaration, {
		{"name", current.first},
		{"type", type},
		{"static", false},
		{"const", false},
		{"parameters", parameters},
		{"body", body}
		});
}

static AST_Node parseClassDeclaration(LEXER::token_list& tokenstream) {
	moveFront(tokenstream);
	LEXER::lexpair current = moveFront(tokenstream);
	vector<AST_Node> body = parseExecutionBlock(tokenstream);
	return AST_Node(command::ClassDeclaration, {
		{"name", current.first},
		{"body", body}
		});
}

static AST_Node parseIfStatement(LEXER::token_list& tokenstream) {
	moveFront(tokenstream);
	if (moveFront(tokenstream).second != LEXER::token::oparen) {
		throw exception("Open parentheses expected in if statement.");
	}
	if (grabFront(tokenstream).second == LEXER::token::cparen) {
		throw exception("Conditional expected in if statement.");
	}
	AST_Node condition = parseExpression(tokenstream);
	if (moveFront(tokenstream).second != LEXER::token::cparen) {
		throw exception("Closed parentheses expected in if statement.");
	}
	vector<AST_Node> truthyBody = parseExecutionBlock(tokenstream);
	vector<AST_Node> falseyBody;
	if (grabFront(tokenstream).second == LEXER::token::elseth) {
		moveFront(tokenstream);
		if (grabFront(tokenstream).second == LEXER::token::ifthis) {
			falseyBody.push_back(parseIfStatement(tokenstream));
		}
		else falseyBody = parseExecutionBlock(tokenstream);
	}
	return AST_Node(command::IfStatement, {
		{"condition", condition},
		{"truthy", truthyBody},
		{"falsey", falseyBody}
		});
}

static vector<AST_Node> parseExecutionBlock(LEXER::token_list& tokenstream) {
	if (moveFront(tokenstream).second != LEXER::token::ocurly) {
		throw exception("Open curly brace expected in execution block.");
	}
	if (grabFront(tokenstream).second == LEXER::token::ccurly) {
		throw exception("Statements expected in execution block.");
	}
	LEXER::lexpair current = grabFront(tokenstream);
	vector<AST_Node> statements;
	while (current.second != LEXER::token::eofcmd && current.second != LEXER::token::ccurly) {
		statements.push_back(parseStatement(tokenstream));
		current = grabFront(tokenstream);
	}
	if (grabFront(tokenstream).second != LEXER::token::ccurly) {
		throw exception("Closed curly brace expected in execution block.");
	}
	return statements;
}

static AST_Node parseExpression(LEXER::token_list& tokenstream) {
	return parseAssignment(tokenstream);
}

static AST_Node parseAssignment(LEXER::token_list& tokenstream) {
	AST_Node object = parseBoolean(tokenstream);
	if (grabFront(tokenstream).second == LEXER::token::assign) {
		moveFront(tokenstream);
		return AST_Node(command::AssignmentExpression, {
			{"left", object},
			{"right", parseAssignment(tokenstream)}
			});
	}
	return object;
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
	while (grabFront(tokenstream).second == LEXER::token::compar ||
		grabFront(tokenstream).second == LEXER::token::oangle ||
		grabFront(tokenstream).second == LEXER::token::cangle) {
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
		}
		if (moveFront(tokenstream).second != LEXER::token::cparen) {
			throw exception("Closed parentheses expected in function call.");
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
			throw exception("Identifier expected in object member call.");
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
		if (moveFront(tokenstream).second != LEXER::token::cparen) {
			throw exception("Closed parentheses expected with open parentheses.");
		}
		return object;
	}
	default:
	{
		throw exception("Unknown token type.");
	}
	}
}

static AST_Node parseStatement(LEXER::token_list& tokenstream) {
	LEXER::lexpair current = grabFront(tokenstream);
	switch (current.second) {
	case LEXER::token::vardec:
		return parseVariableDeclaration(tokenstream);
	case LEXER::token::statdc:
	case LEXER::token::constd:
		return parseDecorationDeclaration(tokenstream);
	case LEXER::token::funcin:
		return parseFunctionDeclaration(tokenstream);
	case LEXER::token::classi:
		return parseClassDeclaration(tokenstream);
	case LEXER::token::ifthis:
		return parseIfStatement(tokenstream);
	default:
		return parseExpression(tokenstream);
	}
}

vector<AST_Node> PARSER::parse(LEXER::token_list tokenstream)
{
	vector<AST_Node> program;
	while (!tokenstream.empty()) {
		if (grabFront(tokenstream).second == LEXER::token::endcmd) {
			tokenstream.pop();
			continue;
		}
		program.push_back(parseStatement(tokenstream));
	}
	return program;
}
