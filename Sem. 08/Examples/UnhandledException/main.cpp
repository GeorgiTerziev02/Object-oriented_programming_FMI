#include <iostream>

void test() {
    throw 3;
}

int main() {
    try {
        test();
    }
    // does not catch ints
    catch(const std::exception& e) {
        std::cout << e.what();
    }
    
}