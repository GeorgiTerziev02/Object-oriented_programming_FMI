#include <iostream>

class Base {
public:
    // !!!! virtual destructor - always
	virtual ~Base() {
		std::cout << "~Base()" << std::endl;
	}

	// virtual - the correct function will be called at runtime
	virtual void test() {
		std::cout << 1 << std::endl;
	}

	// this function is not virtual
	// the function from the base class will be called
	void test2() {
		std::cout << 1 << std::endl;
	}
};

class Derived : public Base {
public:
	~Derived() {
		std::cout << "~Derived()" << std::endl;
	}

	virtual void test() override {
		std::cout << 2 << std::endl;
	}

	// shadowing the function from the base class!
	void test2() {
		std::cout << 2 << std::endl;
	}
};

int main() {
	Base* ptr = new Derived();

	ptr->test();  // 2
	ptr->test2(); // 1
	delete ptr;
}