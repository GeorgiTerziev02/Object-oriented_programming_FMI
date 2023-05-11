#pragma once
#include <iostream>
#include <fstream>

class Logger {
public:
	virtual void log(const char* message) = 0;

	virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
	virtual void log(const char* message) override {
		std::cout << message;
	}
};

class FileLogger : public Logger {
	std::ofstream out;
public:
	FileLogger(const char* fileName) : out(fileName) {
		if (!out.is_open()) {
			throw std::exception("Could not open file");
		}
	}

	~FileLogger() {
		out.close();
	}

	virtual void log(const char* message) override {
		out << message;
	}
};


void test() {
	Logger* logger = new ConsoleLogger();
	Logger* logger2 = new FileLogger("test.txt");

	logger->log("123");
	logger2->log("123");

    delete logger;
    delete logger2;
}