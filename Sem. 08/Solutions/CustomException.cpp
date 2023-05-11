#include <cstring>
#include <exception>
#include <iostream>
#pragma warning(disable : 4996)

class MyCustomException : public std::exception {
private:
	char* message;

public:
	MyCustomException(const char* message) {
		this->message = new char[strlen(message) + 1];
		strcpy(this->message, message);
	}
	const char* what() const {
		return message;
	}
};


int function() {
	try {
		throw MyCustomException("Custom C++ Exception");
	}
	catch (const MyCustomException& ex) {
		std::cout << ex.what();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
	//catch (int a) {
	//	std::cout << a;
	//}
}