#ifndef Parsers_h
#define Parsers_h

#include <string>
#include "Collection.h"

class IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, Collection<std::string>* cmdArguments) = 0;
};

class AdvancedParser : public IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, Collection<std::string>* cmdArguments);

protected:
	virtual void assignToken(std::string& cmdName, std::string& cmdOpt, Collection<std::string>* cmdArguments, std::string& currentToken, int& cntReadTokens);
};

#endif
