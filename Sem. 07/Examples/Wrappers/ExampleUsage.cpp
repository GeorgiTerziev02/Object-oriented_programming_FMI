#include <iostream>
#include "IntWrapper/IntWrapper.h"
#include "CharWrapper/CharWrapper.h"

int main() {
    // operators:
    // we can't overload:
	// priority/precedence
	// associativity
	// position according to the operands
	// arguments type and count
	// 
    // we can overload:
	// return type - but it is not recommended, better stich to the expected return type of operator

    IntWrapper integer(5);
    std::cout << integer << std::endl;
    integer = 48;
    std::cout << integer << std::endl;

    CharWrapper character = integer;
    // if it was explicit
    CharWrapper character2 = (CharWrapper)integer;

    std::cout << character.getValue() << std::endl;
}