#include "Command.h"
#include "CommandManager.h"

Command::Command(std::string _name, InputStreamGenerationGroup _inputStreamGroup, int _minNumOfArgs) : name(_name), inputStreamGroup(_inputStreamGroup), minNumOfArgs(_minNumOfArgs) {
	CommandManager::Instance()->registerCommand(this);
}

std::string Command::getName(){
	return this->name;
}

Command::InputStreamGenerationGroup Command::getInputStreamGroup()
{
	return this->inputStreamGroup;
}

int Command::getMinNumOfArgs()
{
	return this->minNumOfArgs;
}

void Command::execute(InputStream* inStream, OutputStream* outStream, std::string option, Collection<std::string>* arguments)
{
	
	std::string inputString = inStream->read();

	std::string result = process(inputString, option);
	
	outStream->writeLine(result);
	
}


