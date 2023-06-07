#pragma once
#include <string>

class Computer {
private:
	std::string processor;
	std::string ram;
public:
	Computer() = default;
	void setProcessor(const std::string& processor) { this->processor = processor; }
	void setRam(const std::string& ram) { this->ram = ram; }
};

class ComputerBuilder {
private:
	Computer computer;
public:
	ComputerBuilder& setProcessor(const std::string& processor) {
		computer.setProcessor(processor);
		return *this;
	}
	ComputerBuilder& setRam(const std::string& ram) {
		computer.setRam(ram);
		return *this;
	}
	void reset() {
		computer.setProcessor("");
		computer.setRam("");
	}
	Computer build() {
		return computer;
	}
};

void testMain() {
	ComputerBuilder builder;
	
	Computer pc = builder
		.setProcessor("Intel")
		.setRam("16GB")
		.build();
}

