#pragma once
class PersonInfo
{
	char* name = nullptr;

	void free();
	void copyFrom(const PersonInfo& other);

public:
	PersonInfo() = default;
	PersonInfo(const char* name);
	PersonInfo(const PersonInfo& other);

	void setName(const char* name);

	PersonInfo& operator=(const PersonInfo& other);

	const char* getName() const;

	~PersonInfo();
};

