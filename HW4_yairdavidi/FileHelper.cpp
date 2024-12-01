#include "FileHelper.h"
#include <fstream>
#include <string>

std::string FileHelper::readFileToString(std::string fileName)
{
	/*
	* Opens the file to read.
	* Copying each line and adding to a string that eventually will be returned.
	* 
	* Input: std::string filename- the path of the file(in case the file in the project dir, it's just gonna be a name).
	* Output: NONE
	* Returned: The file content by std::string
	*/
	std::string file_string = "";
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "couldn't open file" << std::endl;
		return "";
	}

	std::string line;
	while (std::getline(file, line))
	{
		file_string += line + '\n';
	}
	file.close();

	return file_string;
}

void FileHelper::writeWordsToFile(std::string inputFileName, std::string outputFileName)
{
	/*
	* Copies each words from a source file and writes the word in dest file.
	* 
	* Input: std::string inputFileName - src file (for reading), std::string outputFileName - dst file (for writing).
	* Output: NONE
	* Returned: NONE
	*/
	
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Couldn't open input file." << std::endl;
		return;
	}

	if (!outputFile.is_open())
	{
		std::cout << "Could'nt open output file." << std::endl;
		return;
	}

	std::string word;
	while (inputFile >> word)
	{
		outputFile << word << std::endl; // writes every word in a line.
	}

	inputFile.close();
	outputFile.close();
}

void FileHelper::saveTextInFile(std::string text, std::string outputFileName)
{
	/*
	* Writes given text (type string) into file.
	* 
	* Input: std::string text - text to write into:, std::string outputFileName - file to write to.
	* Output: NONE
	* Returned: NONE
	*/
	std::ofstream file(outputFileName);

	if (!file.is_open())
	{
		std::cerr << "Couldn't open file for writing." << std::endl;
		return;
	}

	// Writing the text into the file content;
	file << text;

	file.close();
}