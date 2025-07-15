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
statement					:	variabledeclaration SEMICOLON	# statementvardecl
							|	functiondeclaration				# statementfuncdecl
							|	classdeclaration				# statementclassdecl
							|	ifstatement						# statementif
							|	whilestatement					# statementwhile
							|	dostatement						# statementdo
							|	forstatement					# statementfor
							|	expression SEMICOLON			# statementexpr
							|	RETURN expression? SEMICOLON	# statementret
							;
variabledeclaration			:	(STATIC | VARIABLE)* IDENTIFIER ARROW_OPERATOR typenameexpression
							|	(STATIC | VARIABLE | CONSTANT)* IDENTIFIER ARROW_OPERATOR typenameexpression ASSIGNMENT_GENERIC expression
							;
functiondeclaration			:	templatedeclaration? FUNCTION? IDENTIFIER functionparameters ARROW_OPERATOR typenameexpression codeblock ;
functionparameters			:	OPEN_PARENTHESES variabledeclaration? (COMMA variabledeclaration)* CLOSED_PARENTHESES ;
classdeclaration			:	templatedeclaration? CLASS? IDENTIFIER codeblock;
templateexpression			:	TEMPLATE ARROW_OPERATOR typenameexpression (COMMA typenameexpression)* SEMICOLON ;
templatedeclaration			:	TYPENAMES COLON IDENTIFIER (COMMA IDENTIFIER)* ;
typenameexpression			:	INTEGER																								# tyinteger
							|	DOUBLE																								# tydouble
							|	STRING																								# tystring
							|	BOOLEAN																								# tyboolean
							|	IDENTIFIER																							# tyident
							|	IDENTIFIER OPEN_ANGLE_BRACKET typenameexpression (COMMA typenameexpression)* CLOSED_ANGLE_BRACKET	# tynested
							;
ifstatement					:	IF OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock (ELSE (codeblock | ifstatement))? ;
whilestatement				:	WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES codeblock ;
dostatement					:	DO codeblock WHILE OPEN_PARENTHESES expression CLOSED_PARENTHESES ;
forstatement				:	FOR OPEN_PARENTHESES variabledeclaration (COMMA variabledeclaration)* SEMICOLON expression SEMICOLON expression (COMMA expression)* CLOSED_PARENTHESES codeblock	# rangefor
							|	FOR OPEN_PARENTHESES variabledeclaration COLON expression CLOSED_PARENTHESES codeblock																				# itemfor
							;
codeblock					:	OPEN_CURLY_BRACE statement+ CLOSED_CURLY_BRACE
							|	statement
							;
expression					:	primaryexpression																					# primexpr
							|	expression PERIOD expression																		# membexpr
							|	expression OPEN_PARENTHESES (expression (COMMA expression)*)? CLOSED_PARENTHESES					# parenexpr
							|	templateexpression expression OPEN_PARENTHESES expression (COMMA expression)* CLOSED_PARENTHESES	# typarexpr
							|	expression OPEN_SQUARE expression CLOSED_SQUARE														# accessexpr
							|	expression incrementaloperator																		# incexpr
							|	notoperator expression																				# notexpr
							|	expression multiplicativeoperator expression														# multexpr
							|	expression additiveoperator expression																# addexpr
							|	expression comparisonoperator expression															# compexpr
							|	expression booleanoperator expression																# boolexpr
							|	expression binaryoperator expression																# binexpr
							|	OPEN_CURLY_BRACE (expression (COMMA expression)*)? CLOSED_CURLY_BRACE								# objexpr
							|	expression assignmentoperator expression															# assignexpr
							;
assignmentoperator			:	ASSIGNMENT_GENERIC	# asseql
							|	ASSIGNMENT_ADD		# assadd
							|	ASSIGNMENT_SUB		# asssub
							|	ASSIGNMENT_MULTI	# assmul
							|	ASSIGNMENT_DIV		# assdiv
							|	ASSIGNMENT_MOD		# assmod
							;
binaryoperator				:	BITWISE_AND	# bitand
							|	BITWISE_OR	# bitor
							|	BITWISE_XOR	# bitxor
							;
booleanoperator				:	BOOLEAN_AND	# booland
							|	BOOLEAN_OR	# boolor
							;
comparisonoperator			:	EQUALITY				# compeql
							|	NON_EQUALITY			# compnon
							|	GREATER_OR_EQUAL		# compgoe
							|	LESS_OR_EQUAL			# comploe
							|	OPEN_ANGLE_BRACKET		# complss
							|	CLOSED_ANGLE_BRACKET	# compgre
							;
additiveoperator			:	ADDITION		# plus
							|	SUBTRACTION		# minus
							;
multiplicativeoperator		:	MULTIPLICATION	# times
							|	DIVISION		# divide
							|	MODULUS			# modulo
							;
notoperator					:	EXCLAMATION_POINT ;
incrementaloperator			:	INCREMENT	# plusplus
							|	DECREMENT	# minusminus
							;
primaryexpression			:	IDENTIFIER										# ident
							|	FLOATING_LITERAL								# decimal
							|	INTEGER_LITERAL									# number
							|	TRUE											# true
							|	FALSE											# false
							|	STRING_LITERAL									# string
							|	OPEN_PARENTHESES expression CLOSED_PARENTHESES	# order
							;