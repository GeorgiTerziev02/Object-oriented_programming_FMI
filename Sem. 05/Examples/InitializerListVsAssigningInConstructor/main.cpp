#include <iostream>

class Test1 {
    int x;
public:
    Test1(int x) : x(x) {
        std::cout << this->x;
    }
};

class Test2 {
    int x;
public:
    Test2(int x) {
        std::cout << this->x;
        this->x = x;
        std::cout << this->x;
    }
};

int main() {
    Test1 t1(5); // 5
    Test2 t2(5); // -8589934605 (garbage value) then 5
}