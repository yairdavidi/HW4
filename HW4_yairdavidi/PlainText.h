#pragma once
#include <string>
#include <iostream>

class PlainText
{
protected:
	std::string _text;
	bool _isEncrypted;

public:
	PlainText(std::string text);
	std::string getText() const;
	bool isEncrypted() const;
	static int numOfTexts;

	friend std::ostream& operator<<(std::ostream& os, const PlainText& obj);
};
