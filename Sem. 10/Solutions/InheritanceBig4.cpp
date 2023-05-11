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
		if (this != &other) {
			std::cout << "operator=(const A& other)" << std::endl;
		}
		return *this;
	}

	A& operator=(A&& other) noexcept {
		if (this != &other) {
			std::cout << "operator=(A&& other)" << std::endl;
		}
		return *this;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B : public A {
public:
	// by default call the default constructor of A
	// you do not have to write it explicitly
	B() {
		std::cout << "B()" << std::endl;
	}

	B(const B& other) : A(other) {
		std::cout << "B(const B& other)" << std::endl;
	}

	B(B&& other) noexcept : A(std::move(other))  {
		std::cout << "B(B&& other)" << std::endl;
	}

	B& operator=(const B& other) {
		if (this != &other) {
			A::operator=(other);
			std::cout << "operator=(const B& other)" << std::endl;
		}
		return *this;
	}

	B& operator=(B&& other) noexcept {
		if (this != &other) {
			A::operator=(std::move(other));
			std::cout << "operator=(B&& other)" << std::endl;
		}

		return *this;
	}

	~B() {
		std::cout << "~B()" << std::endl;
		// call the ~A after it finishes
	}
};

int main() {
	std::cout << "---Normal initialization" << std::endl;
	B b;
	std::cout << "---Copy constructor" << std::endl;
	B b1 = b;
	std::cout << "---operator=" << std::endl;
	b = b1;
	std::cout << "---Move constructor" << std::endl;
	B b2 = std::move(b);
	std::cout << "---Move operator=" << std::endl;
	b1 = std::move(b2);
}