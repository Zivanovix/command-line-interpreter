#include "WcCommand.h"


WcCommand::WcCommand() : Command("wc") {}

std::string WcCommand::process(std::string inputString, std::string option)
{
	if (option == "-w") {
		return countWords(inputString);
	}
	else if (option == "-c") {
		return countChars(inputString);
	}
	else {
		throw std::runtime_error("Wrong option for wc command");
	}
}

std::string WcCommand::countChars(std::string inputSequence)
{
	int cnt = 0;
	for (char c : inputSequence) {
		cnt++;
	}
	return std::to_string(cnt);
}

std::string WcCommand::countWords(std::string inputSequence)
{

	StringInputStream* stream = new StringInputStream(inputSequence);
	int cnt = 0;
	while (stream->hasNextWord()) {
		cnt++;
	}
	delete stream;
	return std::to_string(cnt);
}


