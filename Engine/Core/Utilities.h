#pragma once
#include <string>
#include <SDL.h>

namespace luck
{
	std::string string_tolower(const std::string& str);
	bool istring_compare(const std::string& str1, const std::string& str2);
	std::string unique_string(const std::string& str);
}