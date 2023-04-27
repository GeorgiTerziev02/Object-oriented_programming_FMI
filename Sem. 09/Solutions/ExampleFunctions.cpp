#include <iostream>
void a() {
    int x;

    int &getRef() {
        return x;
    }

    int p() {
        getRef() = 4;
    }
}

void b()
{
    int i = 1;
    int &iref = i;
    int &&rv = 42;
    int &&rv1 = i * 42; // rv1 will refer to a right value that will
                        // live up to the end of the scope
    // int&& rv2 = i; // error
    int &&rv2 = std::move(i);
    int b = rv1;
    std::cout << rv2;
}

void c()
{
    // copy
    void print(int number) {
        std::cout << number << std::endl;
    }

    // lvalue reference
    void print(int &number) {
        std::cout << number << std::endl;
    }

    // rvalue reference
    void print(int &&number) {
        std::cout << number << std::endl;
    }

    void print(const int &number) {
        std::cout << number << std::endl;
    }

    // lvalue & rvalue
    const int &test1 = 5;
}

int main()
{
}