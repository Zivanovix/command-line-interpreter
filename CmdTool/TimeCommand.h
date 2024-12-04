#ifndef TimeCommand_h
#define TimeCommand_h

#include "Command.h"
#include <string>
#include <iostream>

class TimeCommand : public Command{
public:
	TimeCommand();
	virtual std::string process(std::string inputString, std::string option);
	virtual InputStream* createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd);

};

#endif