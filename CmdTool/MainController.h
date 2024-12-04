#ifndef MainController_h
#define MainController_h

#include "Streams.h"
#include "Parsers.h"
class MainController
{
public:
	MainController(std::string _commandPromptChar, InputStream* _inStream, OutputStream* _outStream, IParser* _parser);
	void run();
private:
	IParser* parser;
	InputStream* inStream;
	OutputStream* outStream;
	std::string commandPromptChar;
};

#endif

