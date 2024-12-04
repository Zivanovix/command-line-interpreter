#ifndef Command_h
#define Command_h


#include <string>
#include "Collection.h"
#include "Streams.h"

class Command
{
public:
	Command(std::string _name); 
	std::string getName();
	virtual std::string execute(std::string option, Collection<std::string>* arguments, bool hasPreviousCmd, bool hasNextCmd);
	virtual std::string process(std::string inputString, std::string option) = 0;
	virtual InputStream* createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd);
	virtual OutputStream* createOutputStream();
protected:

private:
	std::string name;
};


#endif

