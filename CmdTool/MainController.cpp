#include "MainController.h"
#include <iostream>
#include "AllCommands.h"
#include "Collection.h"
#include "CommandManager.h"

MainController::MainController(std::string _commandPromptChar, InputStream* _inStream, OutputStream* _outStream, IParser* _parser) : commandPromptChar(_commandPromptChar), inStream(_inStream), outStream(_outStream), parser(_parser){}

void MainController::run()
{
	//Command* wcCmd = new WcCommand();
	Collection<std::string>* arguments;
	
	
	while (true) {
		try {
			std::string cmdName = "", cmdOption = "", cmdArgument = "";
			outStream->write(commandPromptChar);
			arguments = new Collection<std::string>();
			std::string line = inStream->readLine();
			if (line == "") continue;

			parser->parse(line, cmdName, cmdOption, cmdArgument);
		
			if (!cmdArgument.empty()) {
				arguments->add(cmdArgument);
			}
		
		

			CommandManager::Instance()->executeCommand(cmdName, cmdOption, arguments, false, false);
			delete arguments;
			
		}
		catch (const std::exception& e) {
			std::cerr << "Unhandled exception: " << e.what() << std::endl;
		}
	}
}


