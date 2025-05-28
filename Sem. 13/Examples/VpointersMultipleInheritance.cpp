#include <iostream>
#include <optional>

struct A {
	virtual void f() {}
};
struct B {
	virtual void g() {}
};
struct C : A, B {
	virtual void h() {}
};

template<typename T>
void printVtable(T* t, size_t size) {
	void (**vt)() = *(void (***)())t;
	// auto funcAddress1 = vt[0];
	// auto funcAddress2 = vt[1];

	for (size_t i = 0; i < size; i++) {
		std::cout << vt[i] << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	A* aTableTest = new A();
	printVtable(aTableTest, 1);

	C* cTableTest = new C();
	printVtable(cTableTest, 2);

	B* bTableTest = new B();
	printVtable(bTableTest, 1);

	B* bTableFromCTest = (C*)cTableTest;
	printVtable(bTableFromCTest, 1);
}
