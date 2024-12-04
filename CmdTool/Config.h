#ifndef Config_h
#define Config_h

#include "AllCommands.h"

void buildCommands() {
	
	TouchCommand* touch = new TouchCommand();
	EchoCommand* echo = new EchoCommand();
	TimeCommand* time = new TimeCommand();
	DateCommand* date = new DateCommand();
	WcCommand* wc = new WcCommand();
}

#endif
