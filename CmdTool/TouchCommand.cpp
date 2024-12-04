#include "TouchCommand.h"
#include <fstream>
#include <filesystem>

TouchCommand::TouchCommand() : Command("touch"), defaultExtension(".txt") {}

std::string TouchCommand::process(std::string inputString, std::string option)
{
	if (option != "") {
		throw std::runtime_error("Touch command doesn't support any options");
	}
	std::string fileName = inputString;
	std::string extension = getExtension(fileName);
	if (extension == "") {
		fileName += defaultExtension;
	}
	if (std::filesystem::exists(fileName)) {
		throw std::runtime_error("Error! File already exists!");
	}

	// Create and open the file
	std::ofstream file(fileName);

	// Check if the file was successfully created
	if(!file) {
		
		throw std::runtime_error("Error! Failed to create the file!");
	}

	// Close the file
	file.close();
	return "File " + fileName + " created succesfully";

}

InputStream* TouchCommand::createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd)
{
	std::string fileName;
	if (arguments->getSize() == 0) {
		throw std::runtime_error("Touch command requires one argument that represents file name");
	}
	if (arguments->getSize() > 1) {
		throw std::runtime_error("Too many arguments specified, touch takes only one argument that represents file name");
	}
	fileName = arguments->getIterator().next();
	return new StringInputStream(fileName);
	
}

std::string TouchCommand::getExtension(std::string fileName)
{
	std::string ext = "";
	bool extChar = false;
	char c;
	for (size_t i = 0; i < fileName.size(); ++i) {
		c = fileName[i];
		if (extChar) {
			ext += c;
		}
		if (c == '.') {
			extChar = true;
		}
	}
	return ext;
}

