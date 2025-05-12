#include <iostream>

// This class is abstract because it has a pure virtual destructor
class Test {
public:
	int a;

	void f() {
		std::cout << "hello";
	}

	virtual ~Test() = 0;
};

Test::~Test() { }

class Derived : public Test { };

int main() {
	// Test t; // error abstract class
	Derived d;
	d.a;
}