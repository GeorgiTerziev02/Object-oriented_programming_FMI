#pragma once

class Set {
private:
	char* numbers;
	size_t size = 0; // how many bytes we have allocated

	void resize(size_t number);
public:
	Set();
	Set(const Set& other);
	Set& operator=(const Set& other);
	~Set();

	void addNumber(size_t number);
	void removeNumber(size_t number);
	bool containsNumber(size_t number) const;

	Set merge(const Set& other) const;
	Set intersect(const Set& other) const;

	void print() const;
	void printBits() const;
private:
	void free();
	void copyFrom(const Set& other);
};
