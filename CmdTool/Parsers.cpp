#include "Parsers.h"
#include <sstream>

void AdvancedParser::parse(std::string& line, std::string& cmdName, std::string& cmdOpt, Collection<std::string>* cmdArguments)
{
	cmdName.clear();
	cmdOpt.clear();
	
	int readTokens = 0;
	bool insideQuotes = false;
	bool insideToken = false;
	bool lastCharInsideToken = false;
	bool lastCharWasQuote = false;
	std::string currentToken;

	for (size_t i = 0; i < line.size(); ++i) {
		char c = line[i];
		bool space = std::isspace(c);
		bool quote = c == '"';

		if (!space) {
			insideToken = true;

			if (lastCharWasQuote && !insideQuotes) {
				throw std::runtime_error("There has to be a whitespace after quoted sequence");
			}
			if (quote) {
				// Toggle quote state
				insideQuotes = !insideQuotes; 
			}
		}
		else {
			if (insideQuotes) {
				insideToken = true;
			}
			else {
				//non token character is character that is whitespace and not in quotes
				insideToken = false;

				//finish token after first non token character
				if (lastCharInsideToken) {
					assignToken(cmdName, cmdOpt, cmdArguments, currentToken, readTokens);
				}

			}
		}
		if (insideToken) {
			currentToken += c;
			if (i == line.size() - 1) {
				assignToken(cmdName, cmdOpt, cmdArguments, currentToken, readTokens);
			}
		}

		lastCharInsideToken = insideToken;
		lastCharWasQuote = quote;
	}
}

void AdvancedParser::assignToken(std::string& cmdName, std::string& cmdOpt, Collection<std::string>* cmdArguments, std::string& currentToken, int& cntReadTokens)
{
	cntReadTokens++;
	if (cntReadTokens == 1) {
		cmdName = currentToken;
	}
	else if (cntReadTokens == 2 && currentToken[0] == '-') {
		cmdOpt = currentToken;
	}
	else {
		cmdArguments->add(currentToken);
	}
	currentToken = "";
}
