#pragma once
#include <iostream>

struct Target {
	virtual void f() {
		std::cout << "test" << std::endl;
	}
};

struct Adaptee {
	int a = 5; // random property

	void g() {
		std::cout << this->a << std::endl;
	}
};

struct Adapter : Target {
	Adaptee* adaptee;

	Adapter(Adaptee* a) : adaptee(a) { }

	void f() {
		adaptee->g();
	}
};

// you can pass object of type Adapter to the following function
void f(Target& t) {
	t.f();
}

int main123() {
	Adaptee a;
	// f(a); // error
	Adapter adapter(&a);

	f(adapter);
}