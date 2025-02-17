#include <iostream>

#pragma warning (disable:4996)

struct A {
	int a;
	char s;
	char f[];
};

int main() {
	A a;

	char* ptr = (char*)&a;
	strcpy(ptr, "1234567");
	std::cout << a.s;
	std::cout << a.f;
}
