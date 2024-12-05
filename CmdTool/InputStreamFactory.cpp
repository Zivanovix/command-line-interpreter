#include "InputStreamFactory.h"

InputStream* InputStreamFactory::createInputStream(Command::InputStreamGenerationGroup inputStreamGroup, Collection<std::string>* arguments, int minArgs)
{
	if (inputStreamGroup == Command::InputStreamGenerationGroup::None) {
		return createNoneStream(arguments);
	}
	else if (inputStreamGroup == Command::InputStreamGenerationGroup::StringOnly) {
		return createStringOnlyStream(arguments, minArgs);
	}
	else if (inputStreamGroup == Command::InputStreamGenerationGroup::Mixed) {
		return createMixedStream(arguments, minArgs);
	}
}

InputStream* InputStreamFactory::createMixedStream(Collection<std::string>* arguments, int minArgs)
{
	auto iterator = arguments->getIterator();

	//Command supports any input stream type, and has enough arguments
	if (arguments->getSize() == minArgs + 1) {
		std::string& argument = iterator.next();

		if (argument.front() == '"' && argument.back() == '"') {
			return new StringInputStream(argument.substr(1, argument.size() - 2));
		}

		return new FileInputStream(argument);
	}
	else if (arguments->getSize() == minArgs) {
		return new ConsoleInputStream();
	}
	else {
		throw std::runtime_error("Too many arguments for this command");
	}
}

InputStream* InputStreamFactory::createNoneStream(Collection<std::string>* arguments)
{
	//argument checking will be moved in a separate module
	if (arguments->getSize() > 0) {
		throw std::runtime_error("This command has no arguments");
	}
	//date does not work with a sequence of characters
	return new StringInputStream("");
}

InputStream* InputStreamFactory::createStringOnlyStream(Collection<std::string>* arguments, int minArgs)
{
	std::string sourceString;
	
	if (arguments->getSize() != minArgs) {
		throw std::runtime_error("Incorect number of arguments for this command");
	}
	sourceString = arguments->getIterator().next();
	

	if (sourceString.front() == '"' && sourceString.back() == '"') {
		return new StringInputStream(sourceString.substr(1, sourceString.size() - 2));
	}

	return new StringInputStream(sourceString);
}
