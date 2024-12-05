#include "MainController.h"
#include <iostream>
#include "AllCommands.h"
#include "Collection.h"
#include "CommandManager.h"

MainController::MainController(InputStream* _inStream, OutputStream* _outStream, IParser* _parser, std::string _commandPromptChar) : commandPromptChar(_commandPromptChar), inStream(_inStream), outStream(_outStream), parser(_parser){}

void MainController::run()
{
	
	Collection<std::string>* cmdArguments;
	
	while (true) {
		try {

			std::string cmdName, cmdOption;
			cmdArguments = new Collection<std::string>();

			outStream->write(commandPromptChar);
			std::string line = inStream->readLine();

			if (line == "") continue;

			parser->parse(line, cmdName, cmdOption, cmdArguments);
			
			/*std::cout << "Name: " << cmdName << std::endl;
			std::cout << "Option: " << cmdOption << std::endl;
			std::cout << "Arguments: ";
			cmdArguments->print();*/

			CommandManager::Instance()->executeCommand(cmdName, cmdOption, cmdArguments);

			delete cmdArguments;
			
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}


