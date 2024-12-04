#include "DateCommand.h"
#include <chrono>
#include <ctime>
#include <iomanip>

DateCommand::DateCommand() : Command("date") {}

std::string DateCommand::process(std::string inputString, std::string option)
{
    if (option != "") {
        throw std::runtime_error("Date command doesn't support option " + option);
    }
    std::string format = "%d.%m.%Y";
    std::time_t now = std::time(nullptr);
    std::tm localtime = {};

    // Windows-specific secure version
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&localtime, &now);
    // POSIX systems
#else
    localtime_r(&now, &localtime);
#endif

    std::stringstream ss;
    ss << std::put_time(&localtime, format.c_str());
    return ss.str();
}

InputStream* DateCommand::createInputStream(Collection<std::string>* arguments, bool hasPreviousCmd)
{
	if (arguments->getSize() > 0) {
		throw std::runtime_error("Date command has no arguments");
	}
	//date does not work with a sequence of characters
	return new StringInputStream("");
}


