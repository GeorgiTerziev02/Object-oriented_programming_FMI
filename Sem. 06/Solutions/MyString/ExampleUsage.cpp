#include "MyString.h"

int main() {
    // Constructor(const char* str)
    MyString s1("abcde");

    // Constructor(const char* str)
    MyString s2 = "dasda";

    // Copy constructor
    MyString s3 = s1;

    // Copy assignment operator
    MyString s4;
    s4 = s2;

    // Consturctor for the right side and op=!!!
    // "aaa" becomes MyString and after that it is copied to s3
    s3 = "aaa";
}