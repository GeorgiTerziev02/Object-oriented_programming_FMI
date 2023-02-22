#include <iostream>

struct Student{
	char* name;
	size_t fn;
};

Student initStudent(char* name, size_t fn) {
	Student st;
	st.name = name;	
	st.fn = fn;
	return st;
}

void printSt(const Student& st) {
	std::cout << "name: " << st.name << std::endl;
	std::cout << "fn: " << st.fn;
}

int main() {
	char name[30];
	size_t fn;
	std::cin >> name;
	std::cin >> fn;
	Student st1 = initStudent(name, fn);
	printSt(st1);
	return 0;
}