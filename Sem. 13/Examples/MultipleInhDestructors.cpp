#include <iostream>

struct Base1 {
	Base1() {
		std::cout << "Base1";
	}


	virtual ~Base1() {
		std::cout << "~Base1";
	}
};

struct Base2 {
	Base2() {
		std::cout << "Base2";
	}

	~Base2() {
		std::cout << "~Base2";
	}
};

struct Der : Base2, Base1 {
	virtual void d() { }

	~Der() {
		std::cout << "~Der";
	}
};

int main() {
    Base1* ptr = new Der();
    Base2* ptr2 = new Der();

    delete ptr; // ~Base1~Base2~Der
    delete ptr2; // ~Base2
}