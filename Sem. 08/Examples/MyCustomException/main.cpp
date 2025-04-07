#include <iostream>

#pragma warning (disable:4996)

class MyCustomException : public std::exception {
private:
	char message[25] = "";
	int code;
public:
	// [My] message
	MyCustomException(const char* message, int code) : code(code) {
		strcat(this->message, "[My]");
		strcat(this->message, message);
	}

	int getCode() const {
		return code;
	}

	char const* what() const {
		return message;
	}
};

struct Test {
	~Test() {
		// throw "dada";
		std::cout << "hello" << std::endl;
	}
};

void g() {
	Test t;
	throw MyCustomException("Exception from g", 8);
}

void f() {
	Test t;
	try {
		g();
	}
	catch (int code) {
		std::cout << "Catched in f()";
		throw code;
	}
}

int main() {
	try {
		f();
	}
	catch (const MyCustomException& ex) {
		std::cout << ex.what() << " " << ex.getCode();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
}