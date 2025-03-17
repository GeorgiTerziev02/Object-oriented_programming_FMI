struct Test {
    int a;

    // initializing data member a with the value of the parameter a
    // using the member initializer list
    Test(int a) : a(a) {
        // at this point, this->a has the value of the parameter a
    }

    Test(int a, int b) {
        // at this point, this->a has the default int value;

        this->a = a; // we assign new value to a;
    }
};

struct Test1 {
    int a;
    Test1() : Test1(0) { }
    Test1(int a) : a(a) { }
};

struct Test2 {
    Test2(int a) {}
}

Test t[5]; // error: no default constructor => can not be initialized
