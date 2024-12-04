#ifndef WcCommand_h
#define WcCommand_h

#include <iostream>
#include <string>
#include "Command.h"
class WcCommand : public Command {
public:
	WcCommand();
	virtual std::string process(std::string inputString, std::string option);
protected:
	std::string countWords(std::string inputSequence);
	std::string countChars(std::string inputSequence);

};

#endif

