#include <iostream>

int global = 1;

struct A {
	int a;
	A() {
		a = global;
		global++;
	}
};

struct B : /* virtual */ A {
	void printAFromB() {
		std::cout << a;
	}
};

struct C : /* virtual */ A {
	void printAFromC() {
		std::cout << a;
	}
};

struct D : B, C { };

int main() {
	D d;

	d.printAFromB();
	d.printAFromC();
}
