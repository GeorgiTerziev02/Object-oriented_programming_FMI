#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <new>
#include <exception>


void Vector::free()
{
	delete[] array;
	array = nullptr;
}

void Vector::copy(const Vector& other)
{
	array = new(std::nothrow) String[other.capacity];
	if (!array)
		throw std::bad_alloc();

	for (size_t i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}
}


void Vector::resize(unsigned capacity)
{

	String* newArray = new(std::nothrow) String[capacity];

	if (!newArray)
		throw std::bad_alloc();

	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}

}








Vector::Vector() :Vector(4) {}


Vector::Vector(unsigned capacityC): array(nullptr), capacity(capacityC), size(0)
{
	if (!capacityC)
		throw "Bad capacity";

	array = new(std::nothrow) String[capacityC];

	if (!array)
		throw std::bad_alloc();

}

Vector::Vector(const Vector& other)
	:array(nullptr),capacity(other.capacity), size(other.size)
{
	copy(other);
}

Vector::Vector(Vector&& other) noexcept
	: size(other.size), capacity(other.capacity), array(other.array)
{
	other.array = nullptr;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
		
	}
	return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if(this !=&other)
	{
		free();

		size = other.size;
		capacity = other.capacity;

		array = other.array;
		other.array = nullptr;
	}
	return *this;
	
}

Vector::~Vector() noexcept
{
	free();
}


unsigned Vector::getCapacity() const
{
	return this->capacity;
}

void Vector::push_back(const String& str)
{
	if (size == capacity)
		resize(capacity * 2);

	array[size++] = str;
}

void Vector::push_back(String&& str) 
{
	if (size == capacity)
		resize(capacity * 2);

	array[size++] = std::move(str);	

}

void Vector::pop_back()
{
	if (!size)
		return;

	if (size <= capacity / 4)
		resize(capacity / 4);

	size--;	
}

void Vector::insert(unsigned index, const String& str)
{
	if (index >= size)
		throw std::invalid_argument("bad index");
	 
	if (size + 1 == capacity)
		resize(capacity * 2);

	for (size_t i = index; i < size; i++)
	{
		array[i + 1] = array[i];
	}

	array[index] = str;
	size++;

}

void Vector::insert(unsigned index, String&& str) 
{

	if (index >= size)
		throw std::invalid_argument("bad index");

	if (size + 1 == capacity)
		resize(capacity * 2);



	for (size_t i = index; i < size; i++)
	{
		array[i + 1] = array[i];
	}

	array[index] = std::move(str);
	size++;

}

void Vector::erase(unsigned index)
{
	if (index >= size)
		return;

	for (size_t i = index; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;

	if (size <= capacity / 4)
		resize(capacity / 2);

}

void Vector::clear()
{
	size = 0;
}

String& Vector::at(unsigned index)
{
	return array[index];
}

const String& Vector::at(unsigned index) const
{
	return array[index];
}

bool Vector::empty()
{
	return size == 0;
}

unsigned Vector::sizeV() const
{
	return this->size;
}




