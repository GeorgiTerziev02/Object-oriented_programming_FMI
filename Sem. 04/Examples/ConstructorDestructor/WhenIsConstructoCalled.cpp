#include <iostream>

struct Test{
    int a;
    Test(int a): a(a) {
        std::cout << "Test(int a) " << a << std::endl;
    }

    ~Test() {
        std::cout << "~Test() " << a << std::endl;
    }
};

int main() {
    Test t(5); // Test(int a) 5
    Test* ptr = new Test(10); // Test(int a) 10
    delete ptr; // ~Test() 10
} // ~Test() 5