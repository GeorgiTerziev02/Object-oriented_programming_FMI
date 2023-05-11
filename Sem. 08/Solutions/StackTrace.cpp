#include <stacktrace>
#include <iostream>

// StackTrace
void func2() {
	try {
		throw 3;
	}
	catch (int a) {
		// c++ 23
		std::cout << std::stacktrace::current() << '\n';
		throw;
	}
}

void func1() {
	func2();
}

void func() {
	func1();
}