#include "valuescript.h"

VS::RETURN_TYPE VS::BLOCK_CONTROLLERS::START(parameters& args)
{
	return VS::RETURN_TYPE();
}

VS::RETURN_TYPE VS::BLOCK_CONTROLLERS::END(parameters& args)
{
	return VS::RETURN_TYPE();
}

VS::RETURN_TYPE VS::INITIALISERS::INTEGER(parameters& args)
{
	std::wcout << "Created Integer " << std::any_cast<std::wstring>(args[L"name"]) << "\n";
	return VS::RETURN_TYPE();
}

VS::RETURN_TYPE VS::OPERATORS::ASSIGNMENT(parameters& args)
{
	std::wcout << "Assigned Value " << std::any_cast<int>(args[L"value"]) << " to variable " << std::any_cast<std::wstring>(args[L"name"]) << "\n";
	return VS::RETURN_TYPE();
}