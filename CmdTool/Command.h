#ifndef Command_h
#define Command_h


#include <string>
#include "Collection.h"
#include "Streams.h"

class Command
{
public:
	//this will tell how should passed arguments be interpreted in terms of creating input stream for command 
	//it's public because it will be used inside of InputStreamFactory class
	enum class InputStreamGenerationGroup {
		None,
		StringOnly,
		Mixed
	};
	Command(std::string _name, InputStreamGenerationGroup _inputStreamGroup, int _minNumOfArgs = 0); 
	virtual ~Command() = default; //default destructor implementation by compiler

	std::string getName();
	InputStreamGenerationGroup getInputStreamGroup();
	int getMinNumOfArgs();


	virtual void execute(InputStream* inStream, OutputStream* outStream, std::string option, Collection<std::string>* arguments);

protected:
	virtual std::string process(std::string inputString, std::string option) = 0;
private:
	InputStreamGenerationGroup inputStreamGroup;
	std::string name;
	int minNumOfArgs;
};


#endif

