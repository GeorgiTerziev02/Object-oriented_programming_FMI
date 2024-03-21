#include "other.cpp"
// the preprocess will include the content of other.cpp here
// which will result of a seconds definition of f

int main() {
	f(); // linker error => multiple definition of f
}