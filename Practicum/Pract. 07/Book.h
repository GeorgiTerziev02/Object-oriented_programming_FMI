#pragma once


class Book
{
	static unsigned idCounter;

public:
	Book();
	Book(const char* title, const char* author, bool status);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	unsigned getId() const { return id; }
	const char* getTitle() const { return this->title; }
	const char* getAuthor() const { return this->author; }
	bool getStatus() const { return status; }

	bool setTitle(const char* title);
	bool setAuthor(const char* author);
	void setStatus(bool status);

	void print() const;


private:
	unsigned id;
	char* title;
	char* author;
	bool status;


	void free();
	void copyFrom(const Book& other);
};

