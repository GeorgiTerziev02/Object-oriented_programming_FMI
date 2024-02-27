#include <iostream>

enum class Color {
    Orange
};

enum Color2 {
    Orange,
};

enum Fruit {
    Orange
};

// error: having same enumerator names
enum Test {
    T1,
    T1
};

// no problem having duplicate values
enum Test {
    T0, // 0
    T1 = 1,
    T2, // 2,
    T3 = 1,
    T4, // 2
};

// no need to write std:: before cout
// after this line
using std::cout;

void main() {
    // error
    // int a = Orange;
    
    // not a good practice
    if (Color2::Orange == Fruit::Orange) {

    }

    // error
    if(Color::Orange == Color2::Orange) {

    }
}
