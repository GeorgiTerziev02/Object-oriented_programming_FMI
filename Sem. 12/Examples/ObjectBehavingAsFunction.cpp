#include <iostream>

template<typename T>
void invoke(T& obj) {
	obj();
}

void printHello() {
	std::cout << "Hello from some func" << std::endl;
}

struct ObjAsFunc {
	int a;
	void operator()() const {
		std::cout << "Hello from obj " << a << std::endl;
	}
};

int main() {
	invoke(printHello);
	ObjAsFunc oaf;
	oaf.a = 5;
	invoke(oaf);
}
