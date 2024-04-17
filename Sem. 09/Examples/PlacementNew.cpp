#include <iostream>

int x = 0;
// https://en.cppreference.com/w/cpp/language/new ctrl+f "placement new" for more info
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
    // allocate memory for two Test objects in advance
    Test* ptr =(Test*) new char[capacity * sizeof(Test)];   
    // allocate the test object at the address of ptr[0]
    Test* test1 = new (&ptr[0]) Test();
    // allocate the test object at the address of ptr[1]
    Test* test2 = new (&ptr[1]) Test();

    // you should explicitly call the destructor of the objects!
    // deleting the allocated memory will not call the destructors!
    test1->~Test();
    test2->~Test();
    // finally, delete the allocated memory
    delete[] ((char*)ptr);
}