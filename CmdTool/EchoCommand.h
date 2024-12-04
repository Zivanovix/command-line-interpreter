#ifndef EchoCommand_h
#define EchoCommand_h

#include "Command.h"
#include <iostream>
#include <string>

class EchoCommand : public Command{
public:
	EchoCommand();
	virtual std::string process(std::string inputString, std::string option);
};

#endif