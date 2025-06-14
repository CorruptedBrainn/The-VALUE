#include "valuescript.h"

std::ostream& VS::operator<<(std::ostream& os, const VS::COMPILE_ERROR& obj)
{
	std::cout << "\n------------------------------\n";
	std::wcout << "An error occurred.\nError: " << obj.message << "\nLine number: " << obj.line;
	std::cout << "\n------------------------------\n";
	return os;
}

std::ostream& VS::operator<<(std::ostream& os, const VS::RETURN& obj)
{
	std::cout << "\n------------------------------\n";
	std::cout << "Function: " << obj.name << "\nResult: " << obj.result << "\nReturn Value: ";
	std::visit([](auto&& arg) {std::wcout << arg; }, obj.value);
	std::cout << "\n------------------------------\n";
	return os;
}

VS::RETURN VS::CALL(VS::CALLABLE& obj)
{
	return VS::DEFINITIONS[obj.function](obj.args);
}

std::queue<VS::CALLABLE> VS::COMPILE(std::wstring& contents, VS::COMPILE_ERROR& err)
{
	// Now I can start determining what a command's purpose is
	// We do this by iterating on the first word until we hit a non alphabetic character -- ignore '_'
	// 
	// Assuming we get a decorator keyword such as const or static then we keep note of this and we continue
	// We can also check for regular keywords such as if else for while
	// 
	// Assuming we get one where the first keyword is a pregiven datatype, then we're creating an object
	// Knowing this, we're creating a new variable with a name -- if not assigned a value, give it VS_NULL
	// 
	// Assume that we get a data structure, then check for the type key <>
	// Then treat the block inside as getting the type, then outside like we do a variable
	//
	// It could be a custon class, so we do the same as if it were a normal type, just process seperately
	//
	// Once a class or variable is initialised, treat it like a second command, where we assign the value (if present)
	// Also to be used when we have a regular assignment operator
	//
	// Finally, we check for functions

	// Storage should map (in the same map, first is always a wstring for searching)
	// Decorator keywords such as const or static to their flagging functions (Create a new command with this)
	// Regular keywords such as if else for or while to their execution functions
	// Datatype keywords to their initialisation (not assignment) functions
	// Data structures to their initialisation functions
	// Operators to their behavioural functions
	// Regular functions to their functions

	// We need to somehow keep track of user defined stuff
	// I'll figure it out
	return std::queue<VS::CALLABLE>();
}

VS::RETURN VS::INITIALISERS::INTEGER(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::DOUBLE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::BOOLEAN(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::STRING(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::COORDINATE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::UNIT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::FOE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::PAIR(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::ARRAY(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::QUEUE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::STACK(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::MAP(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::FUNCTION(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::INITIALISERS::CLASS(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::ADD(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::SUBTRACT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::MULTIPLY(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::DIVIDE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::MODULUS(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BIT_AND(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BIT_OR(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BIT_NOT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BIT_XOR(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::ASSIGNMENT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::EQUALITY(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::UNEQUALITY(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BOOL_AND(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BOOL_OR(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::OPERATORS::BOOL_NOT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::CONDITIONALS::VS_IF(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::CONDITIONALS::VS_ELSE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::CONDITIONALS::VS_WHILE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::CONDITIONALS::VS_FOR(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::FUNCTIONS::MAXIMUM(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::FUNCTIONS::MINIMUM(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::FUNCTIONS::ABSOLUTE_VALUE(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::FUNCTIONS::PRINT(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::DECORATORS::VS_STATIC(VS::param& args)
{
	return VS::RETURN();
}

VS::RETURN VS::DECORATORS::VS_CONST(VS::param& args)
{
	return VS::RETURN();
}
