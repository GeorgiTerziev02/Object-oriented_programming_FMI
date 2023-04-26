#pragma once
class Grade
{
	double value;
	char* task;
	char* teacher;

	void free();
	void copyFrom(const Grade& other);

public:
	Grade();
	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	Grade(double value, const char* task, const char* teacher);
	void setValue(double grade);
	void setCharArray(const char* content, char*& toBeChanged);

	double getValue() const;
	const char* getTask() const;
	const char* getTeacher() const;
};

