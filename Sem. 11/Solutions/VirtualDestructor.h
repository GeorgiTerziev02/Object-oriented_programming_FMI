#pragma once
#include <iostream>

class VirtualDestructor {
public:
	virtual ~VirtualDestructor() {
		std::cout << "~VirtualDestructor()" << std::endl;
	}
};

class Derived : public VirtualDestructor {
public:
	~Derived() {
		std::cout << "~Derived()" << std::endl;
	}
};