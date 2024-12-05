#ifndef TouchCommand_h
#define TouchCommand_h

#include <string>
#include <iostream>
#include "Command.h"
#include "Collection.h"


class TouchCommand : public Command {
public:
	TouchCommand();
	virtual std::string process(std::string inputString, std::string option);

protected:
	virtual std::string getExtension(std::string fileName);
private:
	std::string defaultExtension;
};

#endif