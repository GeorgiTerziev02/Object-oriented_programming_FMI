#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "Vector.h"

class Base {
	int a;
public:
	virtual void print() const {
		std::cout << "Base";
	}
	virtual ~Base() = default;
};

class Der1: public Base {
	int b;
public:
	void print() const override {
		std::cout << "Der1";
	}
};
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //first line in main function

	Vector<Base*>tmp;

	Base* b1 = new Der1();
	Base* b2 = new Der1();
	Base* b3 = new Base();
	tmp.pushBack(b1);
	tmp.pushBack(b2);
	tmp.pushBack(b3);


	return 0;
}