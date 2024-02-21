#include <iostream>

struct Test {
    char test;
    char test2;
    int x;
};
// sizeof(Test); // 8

struct A {
    char a;
    int b;
};
// sizeof(A); // 8

// The important thing about the next example is to
// check the visualization with the struct layout extension
struct Nested {
    int b;
    A a;
    double d;
};
// sizeof(Nested); // 24

struct Test2 {
    int a;
    char b;
    char c[]; // You can access the padding
};
// sizeof(Test2); // 8

struct Test3 {
    int a[50];
    double b;
};
// sizeof(Test3); // 208

int main() {
    int a = 5;
    sizeof(int); // 4
    sizeof(a); // 4
}