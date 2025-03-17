#pragma once

class Student {
private:
	char* name = nullptr;
	int grade;

	void copyName(const char* newName);
public:
	Student(int grade, const char* name);

	// TODO: grade setters
	const char* getName() const;
	void setName(const char* newName);
};