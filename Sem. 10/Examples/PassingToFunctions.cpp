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

	B(B&& other) noexcept : A(std::move(other)) {
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

void acceptACopy(A a) { }
void acceptBCopy(B b) { }
void acceptA(const A& a) { }
void acceptB(const B& b) { }
void acceptAptr(const A* ptr) { }
void acceptBptr(const B* ptr) { }

void main() {
	A a;
	B b;

	acceptACopy(a);
	acceptACopy(b);
	acceptBCopy(b);

	acceptA(a);
	// only if b has inherited a as public
	acceptA(b);

	acceptAptr(&a);
	acceptAptr(&b); // address of the derived is the same as the base

	// acceptBptr(&a);
	acceptBptr(&b);
}