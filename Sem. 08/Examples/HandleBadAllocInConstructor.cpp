#include <iostream>

class Grade {
	int value;
	int randomStuff[50000];
};

// imagine we are not using any collections and strings
class Student {
private:
	char* userName = nullptr;
	Grade* grades = nullptr;
	int gradesCount;
public:
	Student(int gradesCount): gradesCount(gradesCount) {
		userName = new char[50]; // no need to wrap in try catch, if it fails to allocated, we won't have memory leak

		try {
			grades = new Grade[gradesCount];
		}
		catch (const std::exception& ex) {
			delete[] userName; // !!!
			std::cout << ex.what() << std::endl; // bad alloc
			throw ex;
		}
	}
	Student(const Student& other) = delete;
	Student& operator=(const Student& other) = delete;
	~Student() { // in case of thrown error in the constructor => the destructor won't be called
		delete[] userName;
		delete[] grades;
	}
};

int main() {
	try {
		Student s(5000000);
	}
	catch (const std::exception& ex) {
		std::cout << "";
	}
}
