#include <iostream>

struct A {
	static int counter;
	A() {
		std::cout << "A()";
		counter++;
		if (counter == 3) {
			throw std::exception("fa");
		}
	}

	~A() {
		std::cout << "~A";
	}
};

int A::counter = 0;

int main() {
	try {
		A arr[5]; // A()A()A()
	}
	catch (const std::exception&) { // if no try catch => only the constructors will be printed!
	  // ~A~A
		std::cout << "";
	}
}
