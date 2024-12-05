#ifndef CommandManager_h
#define CommandManager_h

#include "Collection.h"
#include "Command.h"




class CommandManager {

public:
	static CommandManager* Instance();
	void registerCommand (Command* com);
	void executeCommand(std::string cmdName,std::string cmdOption, Collection<std::string>* cmdArguments);
	void printCommands();
private:
	// Constructor, Singleton DP.
	CommandManager() { };
private:
	Collection<Command*> commands;
};

#endif





