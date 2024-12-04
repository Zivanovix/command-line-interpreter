#ifndef CommandManager_h
#define CommandManager_h

#include "Collection.h"
#include "Command.h"
#include <iostream>



class CommandManager {

public:
	static CommandManager* Instance();
	void registerCommand (Command* com);
	void executeCommand(std::string cmdName,std::string cmdOption, Collection<std::string>* cmdArguments, bool hasPreviousCmd, bool hasNextCmd);
	void printCommands();
private:
	// Constructor, Singleton DP.
	CommandManager() { };
private:
	Collection<Command*> commands;
};

#endif





