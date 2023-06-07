#include "Vector.hpp"
#include <iostream>

int main() {
	Vector<int> v;
	for (size_t i = 0; i < 5; i++) {
		v.pushBack(i);
	}
	
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		std::cout << (*iter);
	}
}