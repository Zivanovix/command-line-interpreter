#ifndef DateCommand_h
#define DateCommand_h

#include "Command.h"
#include "Streams.h"
#include <iostream>
#include <string>

class DateCommand : public Command{
public:
	DateCommand();
	virtual std::string process(std::string inputString, std::string option);
	virtual InputStream* createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd);
};

#endif