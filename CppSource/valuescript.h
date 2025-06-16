#pragma once

#ifndef VALUESCRIPT_H
#define VALUESCRIPT_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <any>
#include <stack>
#include <utility>
#include <ranges>
#include <iomanip>
#include <string_view>

/// <summary>
/// The namespace used for all Valuescript Language References
/// </summary>
namespace VS {
	typedef std::unordered_map<std::wstring, std::any> parameters;

	enum flags {
		VS_NEED_NONE = 0,
		VS_NEED_NAME = 1,
		VS_NEED_TYPE = 2,
		VS_NEED_PARAMETER = 4,
		VS_NEED_INT_VALUE = 8
	};

	class RETURN_TYPE {
	public:
		bool state = true;
	};

	class ERROR_TYPE {

	};
	
	namespace BLOCK_CONTROLLERS {
		RETURN_TYPE START(parameters& args);
		RETURN_TYPE END(parameters& args);
	}

	namespace INITIALISERS {
		RETURN_TYPE INTEGER(parameters& args);
	}

	namespace OPERATORS {
		RETURN_TYPE ASSIGNMENT(parameters& args);
	}

	struct callable {
		int type = VS_NEED_NONE;
		std::function<RETURN_TYPE(parameters&)> function = NULL;
		callable* next = nullptr;
		parameters args = {};
		callable(int type, std::function<RETURN_TYPE(parameters&)> function, parameters args) {
			this->type = type;
			this->function = function;
			this->args = args;
		}
		RETURN_TYPE call() {
			return function(args);
		}
	};

	inline static std::unordered_map<std::wstring, std::pair<int, std::function<RETURN_TYPE(parameters&)>>> CREATION = {
		{L"start", {VS_NEED_NONE, BLOCK_CONTROLLERS::START} },
		{L"end", {VS_NEED_NONE, BLOCK_CONTROLLERS::END} },
		{L"int", {VS_NEED_NAME, INITIALISERS::INTEGER} },
		{L"equals", {(VS_NEED_NAME | VS_NEED_INT_VALUE), OPERATORS::ASSIGNMENT} }
	};
}

#endif