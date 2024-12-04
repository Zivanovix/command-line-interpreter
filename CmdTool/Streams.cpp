#include "Streams.h"
#include <iostream>
#include <ios>
#include <limits>

std::string FileInputStream::read()
{
	inputFile.open(location);
	if (!inputFile.is_open()) {
		throw std::runtime_error("Could not open file: " + location);
	}

	std::ostringstream content; 
	content << inputFile.rdbuf();                

	inputFile.close();
	return content.str();
}

FileInputStream::FileInputStream(std::string _location) : location(_location) {}

std::string ConsoleInputStream::read()
{
	std::string buffer;
	char c;

	//std::cout << std::endl;
	while (std::cin.get(c)) {
		buffer += c;
	}
	std::cin.clear();

	return buffer;
}

std::string ConsoleInputStream::readLine()
{
	std::string line;
	std::getline(std::cin, line);
	return line;
}

StringInputStream::StringInputStream(std::string sourceString) : bufferString(sourceString), buffer(sourceString + '\n') {}

std::string StringInputStream::read()
{
	return bufferString;
}

bool StringInputStream::hasNextWord()
{
	std::string word;
	buffer >> word;
	return !buffer.eof();
}

void FileOutputStream::write(std::string& text)
{
	outputFile.open(location, std::ios::out);
	if (!outputFile.is_open()) {
		throw std::runtime_error("Problem with opening file in FileOutputStream::write");
	}
	outputFile << text << std::endl;
	outputFile.close();

}

FileOutputStream::FileOutputStream(std::string _location) : location(_location) {}

void ConsoleOutputStream::write(std::string& text)
{
	//std::cout << std::endl;
	std::cout << text;
}

void ConsoleOutputStream::writeLine(std::string& text)
{
	std::cout << text << std::endl;
}



void StringOutputStream::write(std::string& text)
{
	bufferString.str(""); // reset the buffer
	bufferString.clear(); // clear any error flags
	
	bufferString << text;
}

std::string StringOutputStream::getOutput()
{
	return bufferString.str();
}
