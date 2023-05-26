#pragma once
#include"MyString.h"

class VectorOfStrings {
private:
	MyString* data = nullptr;
	size_t size = 0;
	size_t capacity;
	void resize(size_t newCapacity);

	void assertIndex(size_t index) const;
	void upsizeIfNeeded();
	void downsizeIfNeeded();
public:
	VectorOfStrings();
	VectorOfStrings(size_t capacity);
	VectorOfStrings(const VectorOfStrings& other);
	VectorOfStrings& operator=(const VectorOfStrings& other);
	~VectorOfStrings();

	size_t getSize() const;
	size_t getCapacity() const;

	void pushBack(const MyString& element);
	void pushAt(const MyString& element, size_t index);
	MyString popBack();
	MyString popAt(size_t index);

	bool empty() const;
	void clear();
	void shrinkToFit();

	MyString& operator[](size_t index);
	const MyString& operator[](size_t index) const;

private:
	void copyFrom(const VectorOfStrings& other);
	void free();
};