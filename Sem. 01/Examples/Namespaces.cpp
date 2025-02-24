#include <iostream>
namespace Constants {
    const double PI = 3.14159;
    const double E = 2.71828;
}

void f() {
    std::cout << "::f()" << std::endl;
}

namespace {
    void f1() {
        std::cout << "f1()" << std::endl;
    }
}

namespace A {
    void f() {
        std::cout << "A::f()" << std::endl;
    }
}

namespace B {
    void f() {
        // using ::f() you can access the global f function from here
        std::cout << "B::f()" << std::endl;
    }
}

// easy to confuse with the std::sqrt
double sqrt(double x) {
    return x;
}

int main() {
    A::f();
    B::f();
    f();
    std::cout << Constants::PI << std::endl;
    std::cout << Constants::E << std::endl;

    std::cout << sqrt(4) << std::endl;

    return 0;
}
