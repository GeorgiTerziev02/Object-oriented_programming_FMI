#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Hello, from constructor!" << std::endl;
    }

    ~Test() {
        std::cout << "Hello, from destructor!" << std::endl;
    }
};

int main() {
    // initilizing pointer which points to nullptr address
    Test* ptr = nullptr; // No constructor is called!
    Test* ptr2 = new Test(); // Constructor is called!
    delete ptr2;
}