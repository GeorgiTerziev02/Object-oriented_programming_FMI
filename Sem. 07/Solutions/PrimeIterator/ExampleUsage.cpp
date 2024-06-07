#include <iostream>

#include "PrimeIterator.h"

int main() {
    // print all the prime numbers from which are less than 100
    for (PrimeIterator it(2); *it < 100; it++) {
		std::cout << *it << " ";
    }

}