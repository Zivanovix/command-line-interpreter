#include "EchoCommand.h"

EchoCommand::EchoCommand() : Command("echo", InputStreamGenerationGroup::Mixed) {}

std::string EchoCommand::process(std::string inputString, std::string option)
{
	if (option != "") {
		throw std::runtime_error("Echo command doesn't support option " + option);
	}

	return inputString;
}


