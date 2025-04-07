#include <iostream>

// macros
#define OOP {
#define END }

int main() OOP
#if _DEBUG
    std::cout << "Debug mode" << std::endl;
#else
    std::cout << "Release mode" << std::endl;
#endif
END