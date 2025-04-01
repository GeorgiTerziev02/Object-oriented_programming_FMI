#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include <cstring>
#include <stdexcept>




User::User(const char* name, const char* tel): bookIndex(0)
{
	if (!setName(name) || !setTelNumber(tel))
	{
		throw std::invalid_argument("Invalid argument: input cannot be null");
	}
	for (int i = 0; i < 10; ++i)
		takenBooks[i] = nullptr;
}

bool User::setName(const char* name)
{
	if (!name || name[0] == '\0')
		return false;

	strcpy(userName,name);
	return true;
	
}

bool User::setTelNumber(const char* tel)
{
	if (!tel || tel[0] == '\0')
		return false;

	strcpy(telNumber, tel);
	return true;
}

bool User::getBook(const Book* ptr)
{
	if (bookIndex == TAKEN_BOOKS)
		return false;

	takenBooks[bookIndex++] = ptr;
	return true;
}

Book* User::returnBook()
{
	if (bookIndex == 0)
		return nullptr;

	const Book* returnPtr = takenBooks[--bookIndex];
	
}