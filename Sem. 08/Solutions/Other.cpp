#include <iostream>
#include <exception>

struct Test {
	void func() noexcept {  // if no except function throws => std::terminate
		throw std::exception();
	}
};

struct Test2 {
	~Test2() { }
};

struct T {
	// Destructor is always noexcept!!! 
	~T() noexcept { }
};

struct Test4 {
	Test4() {
		std::cout << "Constructor";
	}
	~Test4() {
		std::cout << "Destructor";
	}
};

void test123() {
	static Test4 t;
}

int main() {
	for (size_t i = 0; i < 1000; i++) {
		test123(); // Constructor is printed only once
	}
} // Destructor
