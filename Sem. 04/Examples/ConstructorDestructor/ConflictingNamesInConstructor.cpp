struct Test {
    int a;

    Test(int a) {
        // incorrect
        a = a; // a is the parameter of the constructor, not the data member
        // correct
        this->a = a;
    }
};