class A {
public:
	int a;
};

class B : public A {
	void test() { a; }
};

class C /*final*/ : protected B {
	void test() { a; }
};

class D : private C {
	void test() { a; }
};

class E : public D {
	// void test() { a; }
};

int main() {
	A a;
	a.a;
	B b;
	b.a;
	C c;
	// c.a; //inaccessible
}