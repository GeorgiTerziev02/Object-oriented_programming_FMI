#include <iostream>

class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}

	A(const A& other) {
		std::cout << "A(const A& other)" << std::endl;
	}

	A(A&& other) noexcept {
		std::cout << "A(A&& other)" << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << "operator=(const A& other)" << std::endl;
		return *this;
	}

	A& operator=(A&& other) noexcept {
		std::cout << "operator=(A&& other)" << std::endl;
		return *this;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class Test {
	A a;

public:
	Test() {
		std::cout << "Test()" << std::endl;
	}

	Test(const Test& other) {
		std::cout << "Test(const Test& other)" << std::endl;
	}

	Test(Test&& other) noexcept : a(std::move(other.a)) {
		std::cout << "Test(Test&& other)" << std::endl;
	}

	Test& operator=(const Test& other) {
		std::cout << "operator=(const Test& other)" << std::endl;

		return *this;
	}

	Test& operator=(Test&& other) noexcept {
		std::cout << "operator=(Test&& other)" << std::endl;
		// if....
		a = std::move(other.a);
		return *this;
	}

	~Test() {
		std::cout << "~Test()" << std::endl;
	}
};

int main() {
	Test t;
	Test t2(std::move(t));
	t = std::move(t2);
}