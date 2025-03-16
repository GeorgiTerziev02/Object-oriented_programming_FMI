#include <iostream>

void t(const Test& t) {
    t.func1(); // incorrect => error
    t.func2(); // incorrect => error
    t.constFunc(); // correct
    t.constFunc2(); // correct
}

struct Test{
    int a;

    void func1() {
        std::cout << "func1" << std::endl;
    }

    void func2();

    void constFunc() const {
        std::cout << "constFunc" << std::endl;
    }

    void constFunc2() const {
        std::cout << "constFunc2" << std::endl;
        constFunc(); // correct
        func1(); // incorrect! => error
    }
};

void Test::func2() {
    std::cout << "func2" << std::endl;
}