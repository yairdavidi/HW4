#pragma once
#include "ShiftText.h"

class CaesarText: public ShiftText
{
public:
	CaesarText(std::string text);
	static std::string encrypt(std::string text);
	static std::string decrypt(std::string text);
	std::string encrypt();
	std::string decrypt();
};