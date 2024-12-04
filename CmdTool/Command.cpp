#include "Command.h"
#include "CommandManager.h"

Command::Command(std::string _name) : name(_name){
	CommandManager::Instance()->registerCommand(this);
}

std::string Command::getName(){
	return name;
}

std::string Command::execute(std::string option, Collection<std::string>* arguments, bool hasPreviousCmd, bool hasNextCmd)
{
	InputStream* inStream = createInputStream(arguments, hasPreviousCmd);

	std::string inputString = inStream->read();
	std::string result = process(inputString, option);
	
	OutputStream* outStream = createOutputStream();
	if (!hasNextCmd) {
		outStream->writeLine(result);
	}
	return result;
}

InputStream* Command::createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd)
{
	auto iterator = arguments->getIterator();
	if (iterator.hasNext()) {
		std::string& argument = iterator.next();

		if (argument.front() == '"' && argument.back() == '"') {
			return new StringInputStream(argument.substr(1, argument.size()-2));
		}

		return new FileInputStream(argument);
	}

	return new ConsoleInputStream();
	
}

OutputStream* Command::createOutputStream()
{
	return new ConsoleOutputStream();
}

