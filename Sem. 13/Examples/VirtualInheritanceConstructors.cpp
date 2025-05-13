#include <iostream>

struct A {
    A() {
        std::cout << "A";
    }

    virtual ~A() {
        std::cout << "~A";
    }
};

struct B : virtual A {
    B() {
        std::cout << "B";
    }

    ~B() {
        std::cout << "~B";
    }
};

struct C : virtual A {
    C() {
        std::cout << "C";
    }

    ~C() {
        std::cout << "~C";
    }
};

int main() {
    C c;
}