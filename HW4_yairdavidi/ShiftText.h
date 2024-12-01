#pragma once
#include  <string>
#include "PlainText.h"

class ShiftText: public PlainText
{
private:
	int _key;

public:
	ShiftText(std::string text, int key);
	static std::string encrypt(std::string text, int key);
	static std::string decrypt(std::string text, int key);
	std::string encrypt();
	std::string decrypt();
};