// Grammar Name
parser grammar ValuescriptParser;

// Tokens
options {
	tokenVocab = ValuescriptLexer;
}

// Follows directly after the standard #includes in h + cpp files
@parser::postinclude {
/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// BEGIN GRAMMAR HERE

file						:	extra* statement+ EOF ;
extra						:	IMPORT IDENTIFIER (AS IDENTIFIER)? SEMICOLON ;
statement					:	variabledeclaration SEMICOLON
							|	functiondeclaration
							|	classdeclaration
							|	ifstatement
							|	whilestatement
							|	dostatement
							|	forstatement
							|	RETURN expression SEMICOLON
							|	expression SEMICOLON
							;
variabledeclaration			:	(STATIC | VARIABLE)* IDENTIFIER ARROW_OPERATOR typenameexpression
							|	(STATIC | VARIABLE | CONSTANT)* IDENTIFIER ARROW_OPERATOR typenameexpression ASSIGNMENT_GENERIC expression
							;
functiondeclaration			:	templatedeclaration? FUNCTION? IDENTIFIER functionparameters ARROW_OPERATOR typenameexpression codeblock ;
functionparameters			:	OPEN_PARENTHESES variabledeclaration? (COMMA variabledeclaration)* CLOSED_PARENTHESES ;
classdeclaration			:	templatedeclaration? CLASS? IDENTIFIER codeblock;
templatedeclaration			:	AT_SYMBOL TYPENAMES COLON IDENTIFIER (COMMA IDENTIFIER)* ;
typenameexpression			:	INTEGER | DOUBLE | STRING | BOOLEAN
							|	IDENTIFIER
							|	IDENTIFIER OPEN_ANGLE_BRACKET typenameexpression (COMMA typenameexpression)* CLOSED_ANGLE_BRACKET
							;
ifstatement					:	IF OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock (ELSE (codeblock | ifstatement))? ;
whilestatement				:	WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock ;
dostatement					:	DO codeblock WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES ;
forstatement				:	FOR OPEN_PARENTHESES variabledeclaration (COMMA variabledeclaration)* SEMICOLON expression SEMICOLON expression (COMMA expression)* CLOSED_PARENTHESES codeblock
							|	FOR OPEN_PARENTHESES variabledeclaration COLON expression CLOSED_PARENTHESES codeblock
							;
codeblock					:	OPEN_CURLY_BRACE statement+ CLOSED_CURLY_BRACE
							|	statement
							;
expression					:	primaryexpression
							|	expression PERIOD expression
							|	expression OPEN_PARENTHESES (expression (COMMA expression)*)? CLOSED_PARENTHESES
							|	expression OPEN_SQUARE expression CLOSED_SQUARE
							|	expression incrementaloperator
							|	notoperator expression
							|	expression multiplicativeoperator expression
							|	expression additiveoperator expression
							|	expression comparisonoperator expression
							|	expression booleanoperator expression
							|	OPEN_CURLY_BRACE (expression (COMMA expression)*)? CLOSED_CURLY_BRACE
							|	expression assignmentoperator expression
							;
assignmentoperator			:	ASSIGNMENT_GENERIC
							|	ASSIGNMENT_ADD
							|	ASSIGNMENT_SUB
							|	ASSIGNMENT_MULTI
							|	ASSIGNMENT_DIV
							|	ASSIGNMENT_MOD
							;
booleanoperator				:	BOOLEAN_AND
							|	BOOLEAN_OR
							;
comparisonoperator			:	EQUALITY
							|	NON_EQUALITY
							|	GREATER_OR_EQUAL
							|	LESS_OR_EQUAL
							|	OPEN_ANGLE_BRACKET
							|	CLOSED_ANGLE_BRACKET
							;
additiveoperator			:	ADDITION
							|	SUBTRACTION
							;
multiplicativeoperator		:	MULTIPLICATION
							|	DIVISION
							|	MODULUS
							;
notoperator					:	EXCLAMATION_POINT ;
incrementaloperator			:	INCREMENT
							|	DECREMENT
							;
primaryexpression			:	IDENTIFIER
							|	INTEGER_LITERAL PERIOD INTEGER_LITERAL
							|	INTEGER_LITERAL
							|	TRUE
							|	FALSE
							|	STRING_LITERAL
							|	OPEN_PARENTHESES expression CLOSED_PARENTHESES
							;