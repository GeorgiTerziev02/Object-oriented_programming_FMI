#include <iostream>

void encapsulation() {
	struct {
	private:
		int a = 5;
	} a;

	int* ptr = (int*)&a;
	std::cout << *ptr;
}

void constructLoop() {
	struct Test {
		Test() : Test(0, 0) {

		}

		// uncomment
		Test(int a, int b) /*: Test()*/ {

		}
	};
}


struct A {
	int a;
	char s;
	char f[];
};

int wle()
{
	A a;

	char* ptr = (char*)&a;
	strcpy(ptr, "1234567");
	std::cout << a.f;
}