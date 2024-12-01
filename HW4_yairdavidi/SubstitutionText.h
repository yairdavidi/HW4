#pragma once
#include "PlainText.h"

class SubstitutionText : public PlainText
{
public:

	SubstitutionText(std::string text, std::string dictionaryFileName);
	static std::string encrypt(std::string text, std::string dictionaryFileName);
	static std::string decrypt(std::string text, std::string dictionaryFileName);
	std::string encrypt();
	std::string decrypt();

private:
	std::string _dictionaryFileName;
};