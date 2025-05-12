#include <iostream>

class Base {
public:
	virtual ~Base() {
		std::cout << "~Base()" << std::endl;
	}

	virtual void test() {
		std::cout << 1 << std::endl;
	}
};

class Derived : public Base {
public:
	~Derived() {
		std::cout << "~Derived()" << std::endl;
	}

	void test() override final {
		std::cout << 2 << std::endl;
	}
};

class Derived2 : public Derived {
public:
    // can't override test() because it is final in Derived
	void test() override {
		std::cout << 3 << std::endl;
	}
};

int main() {
	Base* ptr = new Derived();

	ptr->test();
	delete ptr;
}