#include "CommandManager.h"
#include "Streams.h"
#include "InputStreamFactory.h"

CommandManager* CommandManager::Instance() {
	static CommandManager instance;
	return &instance;
}


void CommandManager::registerCommand(Command* com) {
	if (com) {
		commands.add(com);
	}
}

void CommandManager::executeCommand(std::string cmdName, std::string cmdOption, Collection<std::string>* cmdArguments)
{
	auto iterator = commands.getIterator();
	while (iterator.hasNext()) {
		Command* command = iterator.next();
		if (command->getName() == cmdName) {

			InputStream* inStream = InputStreamFactory::createInputStream(command->getInputStreamGroup(), cmdArguments, command->getMinNumOfArgs());
			OutputStream* defaultOutStream = new ConsoleOutputStream();

			command->execute(inStream, defaultOutStream, cmdOption, cmdArguments);

			delete inStream;
			delete defaultOutStream;

			return;
		}
	}
	throw std::runtime_error("No command named " + cmdName);
}



void CommandManager::printCommands(){
	//commands.print();
}
