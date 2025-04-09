#pragma once
#include "String.h"


class Vector
{
public:
	Vector();
	Vector(unsigned capacity);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	unsigned getCapacity() const;

	void push_back(const String& str);
	void pop_back();
	void insert(unsigned index, const String& str);
	void erase(unsigned index);
	void clear();
	String& at(unsigned index);
	const String& at(unsigned index) const;
	bool empty();
	unsigned sizeV() const;



private:
	String* array;
	unsigned size;
	unsigned capacity;

	void copy(const Vector& other);
	void free();
	void resize(unsigned capacity);

};

