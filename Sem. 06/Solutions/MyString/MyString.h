#pragma once

class MyString {
private:
	char* str;
	size_t length;

	MyString(size_t length);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getLength() const;
	const char* c_str() const;

	char& at(size_t index);
	char at(size_t index) const;
	// const char& at(size_t index) const; alternative
private:
	void copyDynamic(const MyString& other);
	void freeDynamic();
};

