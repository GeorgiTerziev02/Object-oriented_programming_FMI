class Base {
public:
    int x;
};

class Derived : private Base { };

void f(Base& b) { }

int main() {
    Derived d;
    f(d); // Compilation error
    // Conversion from Derived to Base is inaccessible
    // because of private inheritance
}