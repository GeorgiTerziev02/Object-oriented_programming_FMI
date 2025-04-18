#pragma once
#include <iostream>



class Nvector
{
public:
	Nvector(unsigned n);
	Nvector(const Nvector& other);
	Nvector& operator=(const Nvector& other);
	~Nvector();

	unsigned getSize() const { return this->size; }
	

	Nvector& operator+=(const Nvector& other);
	Nvector& operator-=(const Nvector& other);
	Nvector& operator*=(int scalar);
	int& operator[](int index);
	int operator[](int index) const;

	bool areDiffSize(const Nvector& other) const;

private:
	unsigned size;
	int* vector;

private:
	void copyDynamic(const Nvector& other);
	void freeDynamic();
	
	friend std::ostream& operator<<(std::ostream& lhs, const Nvector& rhs);
	friend std::istream& operator>>(std::istream& lhs, Nvector& rhs);
	

};


Nvector operator-(const Nvector& lhs, const Nvector& rhs);
Nvector operator+(const Nvector& lhs, const Nvector& rhs);


