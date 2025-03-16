class ExplicitConstructor {
public:
    explicit ExplicitConstructor(int a) { }
};

class ImplicitConstructor {
public:
    ImplicitConstructor(int a) { }
};

int main() {
    // ExplicitConstructor ec = 5; // error: cannot convert 'int' to 'ExplicitConstructor' in initialization
    ExplicitConstructor ec2 = ExplicitConstructor(5);
    ExplicitConstructor ec3(5);
    ImplicitConstructor ic = 5; // OK
}
