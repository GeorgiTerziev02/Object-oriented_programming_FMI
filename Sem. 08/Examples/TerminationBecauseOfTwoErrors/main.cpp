#include <iostream>

struct Test {
    ~Test() {
        // 
        std::cout << "Hello from destructor" << std::endl;
        throw 3;
    }
};

void g() {
    // Test t;
    // first exception
    throw std::exception("Exception from g");
}

void f() {
    Test t; // second exception when the stack is unwinding
    // => terminate() is called
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
    catch (int code) {
        std::cout << "Catched in main()";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
}