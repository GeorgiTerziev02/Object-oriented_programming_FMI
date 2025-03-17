#pragma once

class Student {
private:
	char* name = nullptr;
	int grade;

	void copyName(const char* newName);
public:
	Student(int grade, const char* name);

	// delete generated functions by the compiler
	Student(const Student& other) = delete;
	Student& operator=(const Student& other) = delete;

	~Student();

	const char* getName() const;
	void setName(const char* newName);

	// TODO: grade get and set
};