#include "valuescript.h"

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

std::queue<VS::CALLABLE> VS::COMPILE(std::wstring& contents)
{
	// TODO: REWRITE
	std::queue<VS::CALLABLE> commands;
	int keywordStart = 0;
	VS::CALLABLE line;
	for (int i = 0; i < contents.size(); i++) {
		if (contents[i] == L';') {
			commands.push(line);
			keywordStart = i + 1;
		}
		else if (contents[i] == L'(') {
			line.function = contents.substr(keywordStart, i - keywordStart);
			keywordStart = i + 1;
		}
		else if (contents[i] == L')') {
			if (i == keywordStart) line.args = {};
			else line.args = { contents.substr(keywordStart, i - keywordStart) };
		}
	}
	return commands;
}

VS::RETURN VS::FUNCTIONS::PRINT(VS::param& args)
{
	std::wcout << std::any_cast<std::wstring>(args[0]);
	return VS::RETURN("Print(string)", 0, VS::VS_NULL);
}

VS::RETURN VS::TYPES::INT(VS::param& args)
{
	// TODO: IMPLEMENT
	return VS::RETURN("Integer()", 0, VS::VS_VARIABLE);
}

VS::RETURN VS::TYPES::DOUBLE(VS::param& args)
{
	// TODO: IMPLEMENT
	return VS::RETURN("Double()", 0, VS::VS_VARIABLE);
}

VS::RETURN VS::TYPES::BOOLEAN(VS::param& args)
{
	// TODO: IMPLEMENT
	return VS::RETURN("Boolean()", 0, VS::VS_VARIABLE);
}

VS::RETURN VS::TYPES::STRING(VS::param& args)
{
	// TODO: IMPLEMENT
	return VS::RETURN("String()", 0, VS::VS_VARIABLE);
}