// Grammar Name
lexer grammar ValuescriptLexer;

// Follows directly after the standard #includes in h + cpp files
@lexer::postinclude {
/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// BEGIN GRAMMAR HERE

STATIC		:	'static'	;
CONSTANT	:	'const'		;
VARIABLE	:	'var'		;
FUNCTION	:	'func'		;
CLASS		:	'class'		;
RETURN		:	'return'	;
TYPENAMES   :   'typenames' ;
TEMPLATE    :   'template'  ;
IMPORT      :   'import'    ;
AS          :   'as'        ;

INTEGER		:	'int'		;
DOUBLE		:	'double'	;
BOOLEAN		:	'bool'		;
STRING		:	'str'		;
VOID        :   'void'      ;

TRUE	:	'true'	;
FALSE	:	'false'	;

IF		:	'if'	;
ELSE	:	'else'	;
DO		:	'do'	;
WHILE	:	'while'	;
FOR		:	'for'	;

OPEN_PARENTHESES		:	'('	;
CLOSED_PARENTHESES		:	')'	;
OPEN_CURLY_BRACE		:	'{'	;
CLOSED_CURLY_BRACE		:	'}'	;
OPEN_ANGLE_BRACKET		:	'<'	;
CLOSED_ANGLE_BRACKET	:	'>'	;
OPEN_SQUARE				:	'['	;
CLOSED_SQUARE			:	']'	;

PERIOD				:	'.'		;
COMMA               :   ','     ;
COLON				:	':'		;
SEMICOLON			:	';'		;
EXCLAMATION_POINT	:	'!'		;
ARROW_OPERATOR		:	'->'	;

BITWISE_AND		:	'&'		;
BOOLEAN_AND		:	'&&'	;
BITWISE_OR		:	'|'		;
BOOLEAN_OR		:	'||'	;
BITWISE_XOR		:	'^'		;

ADDITION		:	'+'	;
SUBTRACTION		:	'-'	;
MULTIPLICATION	:	'*'	;
DIVISION		:	'/'	;
MODULUS			:	'%'	;

INCREMENT   :   '++'    ;
DECREMENT   :   '--'    ;

ASSIGNMENT_GENERIC	:	'='		;
ASSIGNMENT_ADD		:	'+='	;
ASSIGNMENT_SUB		:	'-='	;
ASSIGNMENT_MULTI	:	'*='	;
ASSIGNMENT_DIV		:	'/='	;
ASSIGNMENT_MOD		:	'%='	;

EQUALITY			:	'=='	;
NON_EQUALITY		:	'!='	;
GREATER_OR_EQUAL	:	'>='	;
LESS_OR_EQUAL		:	'<='	;

SINGLE_LINE_COMMENT	:	'//' .*? '\r'? '\n'	->	skip	;
MULTI_LINE_COMMENT	:	'/*' .*? '*/'		->	skip	;
WHITESPACE			:	[ \t\n\r]			->	skip	;

FLOATING_LITERAL        :   [0-9]+ '.' [0-9]*       
                        |          '.' [0-9]+       ;
INTEGER_LITERAL			:	[0-9]+		            ;
STRING_LITERAL			:	'"' (ESCAPE|.)*? '"'	;
IDENTIFIER              : LETTER (LETTER | [0-9])*  ;
LETTER                  : 'a'..'z'|'A'..'Z'|'_'     ;
ESCAPE                  :   '\\"' | '\\\\'          ;