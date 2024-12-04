#include "Parsers.h"
#include <sstream>

//ide is that parse can return bool in order to include piping
void StandardParser::parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg)
{
	std::string word = "";
	std::istringstream stream(line);
	stream >> word;
	if (word != "") {
		cmdName = word;
		word = "";
	}
	
	stream >> word;
	//second token/word exists
	if (word != "") {
		if (word.front() == '-') {
			cmdOpt = word;
			word = "";
		}
		else {
			cmdArg = word;
			word = "";
		}
		stream >> word;
		//third word exists
		if (word != "") {
			cmdArg = word;
		}
	}
}

void NiceParser::parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg)
{
	std::istringstream stream(line);
	std::string token;

	// Resetovanje izlaznih promenljivih
	cmdName.clear();
	cmdOpt.clear();
	cmdArg.clear();

	// 1. Prva rec je uvek ime komande
	if (stream >> token) {
		cmdName = token;
	}
	else {
		return; // Linija je prazna, nista dalje ne radimo
	}
	// 2. Sledeci token moze biti opcija ako pocinje sa '-'
	if (stream >> token) {
		if (!token.empty() && token[0] == '-') {
			cmdOpt = token;

			// 3. Sledeci token moze biti argument
			if (stream >> token) {
				if (!token.empty() && token[0] == '"') {
					// Obrada argumenta sa navodnicima
					cmdArg = token;
					if (cmdArg.back() != '"') {//argument je jedna rec pod navodnicima
						while (stream >> token && token.back() != '"') {
							cmdArg += " " + token;
						}
						if (!token.empty()) {
							cmdArg += " " + token; // Dodajemo poslednji token sa '"'
						}
					}
				}
				else {
					cmdArg = token; // Argument bez navodnika
				}
			}
		}
		else {
			// Ako nije opcija, onda je to direktno argument
			if (!token.empty() && token[0] == '"') {
				// Obrada argumenta sa navodnicima
				cmdArg = token;
				if (cmdArg.back() != '"') { // argument je jedna rec pod navodnicima
					while (stream >> token && token.back() != '"') {
						cmdArg += " " + token;
					}
					if (!token.empty()) {
						cmdArg += " " + token; // Dodajemo poslednji token sa '"'
					}
				}
			}
			else {
				cmdArg = token; // Argument bez navodnika
			}
		}
	}

}

void AdvancedParser::parse(std::string& line, std::string& cmdName, std::string& cmdOpt, std::string& cmdArg)
{
	cmdName.clear();
	cmdOpt.clear();
	cmdArg.clear();

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
				insideQuotes = !insideQuotes; // Toggle quote state
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
					readTokens++;
					if (readTokens == 1) {
						cmdName = currentToken;
					}
					else if (readTokens == 2 && currentToken[0] == '-') {
						cmdOpt = currentToken;
					}
					else {
						cmdArg = currentToken;
					}
					currentToken = "";
				}

			}
		}
		if (insideToken) {
			currentToken += c;
			if (i == line.size() - 1) {
				readTokens++;
				if (readTokens == 1) {
					cmdName = currentToken;
				}
				else if (readTokens == 2 && currentToken[0] == '-') {
					cmdOpt = currentToken;
				}
				else {
					cmdArg = currentToken;
				}
				currentToken = "";
			}
		}

		lastCharInsideToken = insideToken;
		lastCharWasQuote = quote;
	}
}
