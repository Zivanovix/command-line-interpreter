#include "CommandManager.h"



CommandManager* CommandManager::Instance() {
	static CommandManager instance;
	return &instance;
}


void CommandManager::registerCommand(Command* com) {
	if (com) {
		commands.add(com);
	}
}

void CommandManager::executeCommand(std::string cmdName, std::string cmdOption, Collection<std::string>* cmdArguments, bool hasPreviousCmd, bool hasNextCmd)
{
	auto iterator = commands.getIterator();
	while (iterator.hasNext()) {

		Command* command = iterator.next();
		if (command->getName() == cmdName) {
			command->execute(cmdOption, cmdArguments, hasPreviousCmd, hasNextCmd);
			break;
		}
	}
}



void CommandManager::printCommands(){
	//commands.print();
}
