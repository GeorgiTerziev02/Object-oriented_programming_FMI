#pragma once
#include "Book.h"

const unsigned NAME_LENGTH = 9;
const unsigned TELEPHONE_LENGTH = 11;
const unsigned TAKEN_BOOKS = 10;


class User
{
public:
	User() = default;
	User(const char* name, const char* tel);
	const char* getName() const { return this->userName; }
	const char* getNumber() const { return this->telNumber; }
	unsigned getBookNumber() const { return this->bookIndex; }

	bool getBook(const Book* ptr);
	Book* returnBook();

	bool setName(const char* name);
	bool setTelNumber(const char* tel);
	


private:
	char userName[NAME_LENGTH];
	char telNumber[TELEPHONE_LENGTH];
	const Book* takenBooks[TAKEN_BOOKS];
	unsigned bookIndex;

};

