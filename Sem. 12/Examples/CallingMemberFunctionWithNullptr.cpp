#include <iostream>

struct Test {
	int a = 5;

	void f1() {
		std::cout << a;
	}

	void f2() {
		std::cout << 1;
	}
};

int main() {
	Test* t = nullptr;
	// t->f1(); // error is thrown
	t->f2(); // 1
}