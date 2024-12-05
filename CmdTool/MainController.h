#ifndef MainController_h
#define MainController_h

#include "Streams.h"
#include "Parsers.h"
class MainController
{
public:
	MainController(InputStream* _inStream, OutputStream* _outStream, IParser* _parser, std::string _commandPromptChar = "$ ");
	void run();
private:
	IParser* parser;
	InputStream* inStream;
	OutputStream* outStream;
	std::string commandPromptChar;
};

#endif

