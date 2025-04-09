#include "Library.h"
#include <iostream>

Library::Library() : count(0) {}


Library::Library(const Book* books, unsigned count)
{
	if (count >= MAX_BOOKS)
		throw "Too much books in ctor\n";


	for (size_t i = 0; i < count; i++)
	{
		this->books[i] = books[i];
	}

}

bool Library::addBook(const Book& book) 
{
	if (count == MAX_BOOKS)
		return false;

	books[count++] = book;
	return true;
}




bool Library::takeBook(unsigned indexBook,  User& user) 
{
	if (indexBook >= count)
		return false;



	if (user.getBook(&(books[indexBook])))
		books[indexBook].setStatus(true);

	else
		return false;

	return true;
}


bool Library::returnBook(unsigned indexBook, User& user) 
{
	if (indexBook >= count )
		return false;

	Book* result = user.returnBook();
	if (result == nullptr || result != &books[indexBook])
		return false;

	books[indexBook].setStatus(false);
	return true;

}

void Library::printInfo(unsigned index) 
{
	if (index >= count)
	{
		std::cout << "There is no such book in Library\n";
		return;
	}

	books[index].print();
}
