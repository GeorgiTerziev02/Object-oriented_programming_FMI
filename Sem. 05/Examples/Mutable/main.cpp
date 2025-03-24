#include <iostream>

class Test {
    mutable unsigned xAccessCounter = 0;
    int x;
public:
    Test(int x) : x(x) { }

    int getX() const {
        xAccessCounter++; // can be done because is mutable
        return x;
    }

    unsigned getXAccessCounter() const {
        return xAccessCounter;
    }
};

int main() {
    Test t(5);
    t.getX();

    std::cout << t.getXAccessCounter(); // 1
}