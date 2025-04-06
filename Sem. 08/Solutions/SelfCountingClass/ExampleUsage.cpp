#include <iostream>
#include "SelfCounting.h"

int main() {
    SelfCounting s;
	SelfCounting* ptr = new SelfCounting();
	std::cout << SelfCounting::getLivingInstances() << " " << SelfCounting::getCreatedInstances() << std::endl;
	delete ptr;
	SelfCounting s2 = s;
	std::cout << SelfCounting::getLivingInstances() << " " << SelfCounting::getCreatedInstances() << std::endl;
}