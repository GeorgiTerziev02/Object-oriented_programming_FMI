class Test {
private:
    // Compile error: Destructor is private
    ~Test() { }
};

class Test2 {
public:
    Test2() {}
    // Compile error: Copy constructor can't have parameter of type Test2
    // should be Test&!
    Test2(const Test2 t) {}
};