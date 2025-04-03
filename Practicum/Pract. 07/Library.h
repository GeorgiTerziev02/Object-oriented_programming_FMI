#pragma once
#include "Book.h"
#include "User.h"

const unsigned MAX_BOOKS = 50;

class Library
{

public:
	Library();
	Library(const Book* books, unsigned count);

	bool addBook(const Book& book);
	bool takeBook(unsigned indexBook, User& user);
	bool returnBook(unsigned indexBook, User& user);
	void printInfo(unsigned indexBook);



private:
	Book books[MAX_BOOKS];
	unsigned count;
	

};

