#pragma once
#include <iostream>

class A {
public:
	A(int a) {
		std::cout << "A(int a)" << std::endl;
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

	virtual ~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B : virtual public A {
public:
	// by default call the default constructor of A
	// you do not have to write it explicitly
	B() : A(5) {
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
	}
};

class C : virtual public A {
public:
	// by default call the default constructor of A
	// you do not have to write it explicitly
	C() : A(5) {
		std::cout << "C()" << std::endl;
	}

	C(const C& other) : A(other) {
		std::cout << "C(const C& other)" << std::endl;
	}

	C(C&& other) noexcept : A(std::move(other)) {
		std::cout << "C(C&& other)" << std::endl;
	}

	C& operator=(const C& other) {
		if (this != &other) {
			A::operator=(other);
			std::cout << "operator=(const C& other)" << std::endl;
		}
		return *this;
	}

	C& operator=(C&& other) noexcept {
		if (this != &other) {
			A::operator=(std::move(other));
			std::cout << "operator=(C&& other)" << std::endl;
		}

		return *this;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};


class D : public B, public C {
public:
	// by default call the default constructor of A
	// you do not have to write it explicitly
	D() : A(5), B(), C() {
		std::cout << "D()" << std::endl;
	}

	D(const D& other) : A(other), B(other), C(other) {
		std::cout << "D(const D& other)" << std::endl;
	}

	D(D&& other) noexcept : A(std::move(other)), B(std::move(other)), C(std::move(other)) {
		std::cout << "D(D&& other)" << std::endl;
	}

	D& operator=(const D& other) {
		if (this != &other) {
			// A::operator=(other);
			// Unfortunatelly there is no "good practice" way to escape from calling A::op= two times
			// Invoking B and C op= will both call the A::operator=
			B::operator=(other);
			C::operator=(other);
			std::cout << "operator=(const D& other)" << std::endl;
			
			// One way to escape it:
			// Create free and copyFrom functions in B and C
			// These two functions should be responsible only for free/copying data related to the class they are defined in.
			// This means that B::free should only clear B resources and should not invoke anything from A. Similarly for the other.
			// then here you can invoke these functions in the following order
			// A::operator=
			// B::free();
			// B::copy(other);
			// C::free();
			// C::copy(other);
		}
		return *this;
	}

	D& operator=(D&& other) noexcept {
		if (this != &other) {
			A::operator=(std::move(other));
			B::operator=(std::move(other));
			C::operator=(std::move(other));
			std::cout << "operator=(D&& other)" << std::endl;
		}

		return *this;
	}

	~D() noexcept {
		std::cout << "~D()" << std::endl;
	}
};

int main() {
	std::cout << "Constructor" << std::endl;
	D d1;
	std::cout << "Copy Constructor" << std::endl;
	D d2 = d1;
	std::cout << "Operator=" << std::endl;
	d1 = d2;
}
