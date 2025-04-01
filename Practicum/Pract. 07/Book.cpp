#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>
#include <new>
#include <iostream>

unsigned Book::idCounter = 0;

Book::Book()
	:title(nullptr), author(nullptr)
{
	
	title = new char [strlen("Invalid_name") + 1];
	strcpy(title,"Invalid_name");
	author = new char[strlen("Invalid_name") + 1];
	strcpy(author, "Invalid_name");
	status = false;
	id = Book::idCounter++;
}

Book::Book(const char* titleIn, const char* authorIn, bool statusIn)
	: title(nullptr), author(nullptr)
{
	if (!setTitle(titleIn) || !setAuthor(authorIn))
	{
		free();
		throw "Error in setters\n";
	}
	setStatus(statusIn);
	id = Book::idCounter++;
}


Book::Book(const Book& other) 
	: title(nullptr), author(nullptr)
{
	copyFrom(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Book::~Book() 
{
	free();
}



bool Book::setTitle(const char* title) 
{
	if (!title || title[0] == '\0')
		return false;

	delete[] this->title;
	unsigned len = strlen(title) + 1;

	this->title = new(std::nothrow) char[len];

	if (!this->title)
		throw std::bad_alloc();

	strcpy(this->title, title);
	return true;
}

bool Book::setAuthor(const char* author) 
{
	if (!author || author[0] == '\0')
		return false;
	

	delete[] this->author;
	unsigned len = strlen(author) + 1;

	this->author = new(std::nothrow) char[len];

	if (!this->author)
		throw std::bad_alloc();

	strcpy(this->author, author);
	return true;
}

void Book::setStatus(bool status) 
{
	this->status = status;
}

void Book::print() const
{
	std::cout << "Title: " << getTitle() << " Author: " << getAuthor() << " ";

	(0 == getStatus()) ? std::cout << "free " : std::cout << "taken\n";
	std::cout << "id: " << id << "\n";

}




void Book::free() 
{
	delete[] author;
	author = nullptr;
	delete[] title;
	title = nullptr;
}

void Book::copyFrom(const Book& other) 
{
	if (!setTitle(other.title) || !setAuthor(other.author))
	{
		free();
		throw std::bad_alloc();
	}

	status = other.status;
	id = Book::idCounter++;
}