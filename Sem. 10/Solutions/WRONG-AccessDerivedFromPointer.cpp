#include <iostream>

// violation example
struct C {
	int x = 4;
};

struct D : public C {
	int y = 5;
};

void get(C& c) {
	int* ptr = (int*)&c;
	++ptr;
	std::cout << ptr[0];
}