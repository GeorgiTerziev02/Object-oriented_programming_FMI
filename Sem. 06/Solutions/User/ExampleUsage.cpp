#include "User.h"

int main() {
	User u1("abcde", "fff");

    // Think before using it
    // Two cases:

    // this is A NEW STRING which is a copy of the string
    MyString userName = u1.getUserName();

    // this users the provided const& from the getter
    const MyString& userName = u1.getUserName();

    std::cout << userName.c_str();
}