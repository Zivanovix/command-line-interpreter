#ifndef Parsers_h
#define Parsers_h

#include <string>

class IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg) = 0;
};

class StandardParser : public IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg);
};
class NiceParser : public IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg);
};
class AdvancedParser : public IParser {
public:
	virtual void parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg);
};

#endif
