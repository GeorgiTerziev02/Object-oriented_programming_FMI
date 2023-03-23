#pragma once
#include <iostream>

class Task {
	char* name = nullptr;
	char* description = nullptr;
	unsigned points = 0;

public:
	Task();

	Task(const char* name, const char* description, unsigned points);

	void setName(const char* name);
	void setDescription(const char* description);
	void setNameFromFile(std::ifstream& ifs, unsigned nameLen);
	void setDescriptionFromFile(std::ifstream& ifs, unsigned descriptionLen);
	void setPoints(unsigned points);

	const char* getName() const;
	const char* getDescription() const;
	unsigned getPoints() const;

	void print();

	~Task();
};