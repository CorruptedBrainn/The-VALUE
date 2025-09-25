#include "warnings.h"

void ValuescriptWarningListener::syntaxError(Recognizer* recogniser, Token* offendingSymbol, size_t line, size_t charPositionInLine, const string& msg, exception_ptr e)
{
	wchar_t* buffer = convert::strtowchar(msg);
	ValuescriptError ret = { buffer, line, charPositionInLine };
	this->warningList.push(ret);
	return;
}