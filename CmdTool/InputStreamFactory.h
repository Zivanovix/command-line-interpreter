#ifndef InputStreamFactory_h
#define InputStreamFactory_h

#include "Command.h"
#include "Streams.h"
#include "Collection.h"

class InputStreamFactory
{
public:
	static InputStream* createInputStream(Command::InputStreamGenerationGroup inputStreamGroup, Collection<std::string>* arguments, int minArgs);
protected:
	static InputStream* createMixedStream(Collection<std::string>* arguments, int minArgs);
	static InputStream* createNoneStream(Collection<std::string>* arguments);
	static InputStream* createStringOnlyStream(Collection<std::string>* arguments, int minArgs);
};

#endif