#include <iostream>
#include "SingletonFactory.h"

int main() {
	auto factory = SingletonFactory::getInstance();

	auto ptr1 = factory->create(BaseType::Der1);
	auto ptr2 = factory->create(BaseType::Der2);
	auto ptr3 = factory->create(BaseType::Der3);

	factory->freeInstance();
}