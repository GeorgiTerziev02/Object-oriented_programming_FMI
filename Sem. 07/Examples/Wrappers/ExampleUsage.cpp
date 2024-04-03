#include <iostream>
#include "IntWrapper/IntWrapper.h"
#include "CharWrapper/CharWrapper.h"

int main() {
    IntWrapper integer(5);
    std::cout << integer << std::endl;
    integer = 48;
    std::cout << integer << std::endl;

    CharWrapper character = integer;
    // if it was explicit
    CharWrapper character2 = (CharWrapper)integer;

    std::cout << character.getValue() << std::endl;
}