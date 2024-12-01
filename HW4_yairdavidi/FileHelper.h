#pragma once
#include <iostream>


class FileHelper
{
public:
	static std::string readFileToString(std::string fileName);
	static void writeWordsToFile(std::string inputFileName, std::string outputFileName);
	static void saveTextInFile(std::string text, std::string outputFileName);
};