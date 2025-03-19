#pragma once
const unsigned NAME_SIZE = 30;
enum class Subject
{
	UNKNOWN = -1,
	MATH,
	MUSIC,
	ENGLISH,
	GEOGRAPHY,
	COUNT
};

class Teacher
{
private:
	char name[NAME_SIZE];
	unsigned age;
	Subject subject;
	unsigned salary;
	
public:

	Teacher(const char name[], unsigned age, Subject subject, unsigned salary);

	

	
	const char* getName() const;
	void setName(const char* name);
	
	unsigned getAge() const;
	void setAge(unsigned age);

	
	Subject getSubject() const;
	void setSubject(Subject subject);

	unsigned getSalary() const;
	void setSalary(unsigned salary);


	

	
};

