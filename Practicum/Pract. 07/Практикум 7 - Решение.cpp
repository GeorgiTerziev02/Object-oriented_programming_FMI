// Практикум 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book
{
private:
	int id;
	char* title = nullptr;
	char* author = nullptr;
	bool status;
	static int id_counter;

	void free()
	{
		delete[] title;
		title = nullptr;
		delete[] author;
		author = nullptr;
	}

	void CopyFrom(const Book& other)
	{
		title = new char[strlen(other.title) + 1];
		strcpy(title, other.title);
		author = new char[strlen(other.author) + 1];
		strcpy(author, other.author);
		status = other.status;
	}

public:
	Book(const char* title, const char* author, bool status)
	{
		id = id_counter;
		id_counter++;
		this->title = new char[strlen(title) + 1];
		this->author = new char[strlen(author) + 1];
		strcpy(this->title, title);
		strcpy(this->author, author);
		this->status = status;
	}

	Book(const Book& other)
	{
		CopyFrom(other);

	}

	Book& operator= (const Book& other)
	{

		if (this != &other)
		{
			free();
			CopyFrom(other);
		}
		return *this;
	}
	
	~Book()
	{
		free();
	}

	int getID() const
	{
		return id;
	}

	bool getstatus() const
	{
		return status;
	}

	void setstatus(bool st)
	{
		status = st;
	}

	const char* getTitle() const
	{
		return title;
	}

	const char* getAuthor() const
	{
		return author;
	}

	void printInfo() const
	{
		cout << "ID: " << id << endl;
		cout << "Title:" << title << endl;
		cout << "Author:" << author << endl;
		cout << "Status: " << (status ? "Avaliable" : "Taken") << endl;
	}

};

int Book::id_counter = 0;


class User
{
private:
	static const int username_length = 8;
	static const int number_length = 10;
	char username[username_length];
	int number[number_length];

public:
	User(const char* username, const int* number)
	{
		setUserName(username);
		setNumber(number);
	}

	const char* getUsername() const 
	{
		return username;
	}

	const int* getNumber() const
	{
		return number;
	}

	void setUserName(const char* un)
	{
		strcpy(username, un);
		username[username_length - 1] = '\0';
	}

	void setNumber(const int* num)
	{
		for (int i = 0; i < number_length; i++)
		{
			number[i] = num[i];
		}
	}


};


class Library
{
private:
	static const int MAX_BOOKS = 50;
	Book* books[MAX_BOOKS];
	int count;

public:
	Library() 
	{
		count = 0;
	}

	~Library()
	{
		for (int i = 0; i < count; i++)
		{
			delete books[i];
		}
	}

	void addBook(const char* title, const char* author)
	{
		if (count >= MAX_BOOKS)
		{
			throw runtime_error("No more capacity");
		}
		books[count++] = new Book(title, author, true);
	}

	void borrowBook(int id, const User& user)
	{
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (books[i]->getID() == id)
			{
				found = true;
				if (!books[i]->getstatus())
					throw runtime_error("The book is taken");
				books[i]->setstatus(false);
				break;
			}
		}
		if (!found)
			throw runtime_error("Book doesn't exist");
	}

	void returnBook(int id)
	{
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (books[i]->getID() == id)
			{
				found = true;
				if (books[i]->getstatus())
					throw runtime_error("Book is now avaliable.");
				books[i]->setstatus(true);
				break;
			}
		}
		if (!found)
			throw runtime_error("Book doesn't exist.");
	}

	void printBooks() const
	{
		for (int i = 0; i < count; i++)
		{
			books[i]->printInfo();
		}
	}

};


int main()
{
	Library lib;
	try {
		lib.addBook("Error", "Error");
		lib.addBook("Effective C++", "Meyers");
		lib.addBook("The C++ Programming Language", "Stroustrup");

		int phone[10] = { 0,1,2,3,4,5,6,7,8,9 };
		User user("Ana", phone);

		lib.borrowBook(1, user);
		lib.printBooks();


		try 
		{
			lib.borrowBook(1, user);
		}
		catch (const runtime_error& ex)
		{
			cout << "Error: " << "\n";
		}

		lib.returnBook(1);
		lib.printBooks();

		try 
		{
			lib.returnBook(1);
		}
		catch (const runtime_error& ex)
		{
			cout << "Error: " << "\n";
		}
	}
	catch (const runtime_error& ex) 
	{
		cout << "Error: " << "\n";
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
