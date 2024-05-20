
struct A {
	A() {
		std::cout << "A Default" << std::endl;
	}
	A(int b) {
		std::cout << "A With parameter" << std::endl;
	}
};

struct B : virtual public A {
	B() {
		std::cout << "B constructor" << std::endl;
	}
};

struct C : public B {
	C() : B(), A(6) {
		std::cout << "C constructor";
	}
};

struct D : public C {
	D() : A(5) {
		std::cout << "3131";
	}
};

int main1() {
	D d;
	return 0;
}
