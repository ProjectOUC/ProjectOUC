#pragma once
#include <string>
#include <Windows.h>

namespace Converter
{
	std::string UnicodeToANSI(const std::wstring& src);
};