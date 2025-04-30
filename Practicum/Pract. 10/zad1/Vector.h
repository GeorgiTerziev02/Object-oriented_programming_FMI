#pragma once
#include "String.h"


class Vector
{
public:
	Vector();
	Vector(unsigned capacity);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(const Vector& other);
	Vector& operator=( Vector&& other) noexcept;
	~Vector() noexcept;

	unsigned getCapacity() const;

	void push_back(const String& str);
	void push_back(String&& str) ;
	void pop_back();
	void insert(unsigned index, const String& str);
	void insert(unsigned index, String&& str) ;
	void erase(unsigned index);
	void clear();
	String& at(unsigned index);
	const String& at(unsigned index) const;
	bool empty();
	unsigned sizeV() const;

private:
	void copy(const Vector& other);
	void free();
	void resize(unsigned capacity);




private:
	String* array;
	unsigned size;
	unsigned capacity;



};

