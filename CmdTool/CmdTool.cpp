
#include <iostream>
#include "Collection.h"
#include "Config.h"
#include "CommandManager.h"
#include "Streams.h"
#include "MainController.h"
#include "Parsers.h"



int main()
{
	buildCommands();

	IParser* parser = new AdvancedParser();
	ConsoleInputStream* consoleInput = new ConsoleInputStream();
	ConsoleOutputStream* consoleOutput = new ConsoleOutputStream();
	MainController* controler = new MainController(consoleInput, consoleOutput, parser);

	controler->run();

	delete parser;
	delete controler;
	delete consoleInput;
	delete consoleOutput;

	return 0;
}



