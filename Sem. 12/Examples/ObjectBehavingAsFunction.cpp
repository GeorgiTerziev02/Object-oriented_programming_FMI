#include <iostream>

void print() {
    std::cout << "hello";
}

struct Test {
    int a;
    void operator()() {
        std::cout << a;
    }
};
template<typename T>
void f(T t) {
    t();
}

int main() {
    f(print);

    Test t;
    t.a = 5;
    f(t);
}