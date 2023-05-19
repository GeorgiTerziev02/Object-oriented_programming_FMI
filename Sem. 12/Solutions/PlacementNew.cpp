#include <iostream>

int x = 0;

struct Test {
	int a;
	
	Test() {
		a = ++x;
		std::cout << a << std::endl;
	}

	~Test() {
		--x;
		std::cout << "rip";
	}
};

int main() {
    const size_t capacity = 4;
	Test* ptr =(Test*) new char[capacity * sizeof(Test)];

	Test* test1 = new (&ptr[0]) Test();
	Test* test2 = new (&ptr[1]) Test();
	
	test1->~Test();    
	test2->~Test();
	delete[] ((char*)ptr);
}