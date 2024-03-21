#include "header.h"

// the preprocess will include the content of header.h here
// which will result in a definition of f
// which will exist in the obj file of main.cpp

int main() {
	f(); // linker error => multiple definition of f
    // f is defined both in main.obj and other.obj
}