#pragma once
class Teacher
{
	char* name = nullptr;

public:

	Teacher() = default;
	Teacher(const Teacher& other);
	Teacher(const char* name);
	Teacher& operator=(const Teacher& other);
	~Teacher();

	const char* getName() const;
	void setName(const char* name);

private:

	void free();
	void copyFrom(const Teacher& other);
};

