#ifndef Streams_h
#define Streams_h

#include <string>
#include <fstream>
#include <sstream>

class InputStream {

public:
	virtual std::string read() = 0;
	virtual std::string readLine() = 0;
	virtual ~InputStream() = default;
};



class FileInputStream : public InputStream {
public:
	FileInputStream(std::string _location);
	virtual std::string read();
	virtual std::string readLine() { return " "; }
private:
	std::ifstream inputFile;
	std::string location;
};



class ConsoleInputStream : public InputStream {
public:
	virtual std::string read();
	virtual std::string readLine();
};



class StringInputStream : public InputStream {
public:
	StringInputStream(std::string sourceString);
	virtual std::string read();
	virtual std::string readLine() { return " "; }
	bool hasNextWord();
private:
	std::string bufferString;
	std::istringstream buffer;
};



class OutputStream {

public:
	virtual void write(std::string& text) = 0;
	virtual void writeLine(std::string& text) {};
	virtual ~OutputStream() = default;
};



class FileOutputStream : public OutputStream {

public:
	FileOutputStream(std::string _location);
	virtual void write(std::string& text);
private:
	std::ofstream outputFile;
	std::string location;
};



class ConsoleOutputStream : public OutputStream {

public:
	virtual void write(std::string& text);
	virtual void writeLine(std::string& text);

};



class StringOutputStream : public OutputStream {

public:
	virtual void write(std::string& text);
	std::string getOutput();
private:
	std::ostringstream bufferString;
};
#endif
