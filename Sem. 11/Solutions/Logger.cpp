#include <iostream>
#include <fstream>

class Logger {
public:
	virtual void log(const char* message) = 0;
	virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
	void log(const char* message) override {
		std::cout << message;
	}
};

class FileLogger : public Logger {
private:
	std::ofstream out;
public:
	FileLogger(const char* fileName) : out(fileName) {
		if (!out.is_open()) {
			throw std::exception("Couldn't open file");
		}
	}

	void log(const char* message) override {
		out << message;
	}
};

void run(Logger* logger) {
	while (true) {
		try {
			//...
		}
		catch (const std::exception& ex) {
			logger->log(ex.what());
		}
	}

}

int main() {
#if _DEBUG
	Logger* logger = new ConsoleLogger();
#else
	Logger* logger = new FileLogger("logs.txt");
#endif
	run(logger);
    delete logger;
}