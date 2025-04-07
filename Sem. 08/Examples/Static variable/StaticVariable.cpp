#include <iostream>
#include <exception>
#include <cstring>

#pragma warning(disable: 4996)

struct Test {
	Test() {
		std::cout << "Test";
	}
};

static Test a;

Test& f() {
	static Test a; // created only once, on the first call
	return a;
}

Test& f2() {
	static Test a; // created only once, on the first call
	return a;
}

int main() {
	Test& t1 = f();
	Test& t2 = f2();

	std::cout << (&t1 != &t2);
}