#include <iostream>
#include "MyString.h"

int main() {
	MyString s;
	std::cin >> s;

    // here there is additional MyString constructor called
	s += "Test";

    // also here is additional MyString constructor called
    MyString s2 = s + "Test2";
	std::cout << s << std::endl;
    std::cout << s2;
}