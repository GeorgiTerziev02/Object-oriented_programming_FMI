#pragma once
#include <iostream>

class IntWrapper {
private:
	int value;

public:
	IntWrapper(int value);

	int getValue() const;

	IntWrapper& operator=(int other);

    // Prefix increment
	IntWrapper& operator++();
    // Postfix increment
	IntWrapper operator++(int);

    // this is first declaration of operator<< as a friend function
    // you can place the friend stuff also in the protected, private => it doesn't matter
	friend std::istream& operator>>(std::istream& in, IntWrapper& integer);
};

std::ostream& operator<<(std::ostream& out, const IntWrapper& integer);

// this is the same declaration of operator<< as a function
// No need to write it two times only the friend one is enough
std::istream& operator>>(std::istream& in, IntWrapper& integer);