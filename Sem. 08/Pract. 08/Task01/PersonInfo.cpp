#include "PersonInfo.h"
#include <cstring>

#pragma warning(disable:4996)


PersonInfo::PersonInfo(const char* name)
{
	setName(name);
}

PersonInfo::PersonInfo(const PersonInfo& other)
{
	copyFrom(other);
}

PersonInfo& PersonInfo::operator=(const PersonInfo& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

const char* PersonInfo::getName() const
{
	return name;
}

void PersonInfo::setName(const char* name)
{
	free();

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void PersonInfo::free()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void PersonInfo::copyFrom(const PersonInfo& other)
{
	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);
}

PersonInfo::~PersonInfo()
{
	free();
}