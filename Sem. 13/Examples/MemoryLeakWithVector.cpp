#include <vector>

struct Base {
    virtual ~Base() = default;
};

struct Derived1 : Base { };

struct Derived2 : Base { };


int main() {
    std::vector<Base*> objects;

    objects.push_back(new Derived1());
    objects.push_back(new Derived2());

    // Memory leak
    // we should iterate through the pointers and delete them
}