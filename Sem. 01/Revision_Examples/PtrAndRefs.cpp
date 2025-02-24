#include <iostream>

void test(int* ptr) {
	*ptr = 10;
}
void test2(int& ref) {
	ref = 10;
}
void test3(int arr[]) {
	arr[0] = 10;
}
void test4(int* arr) {
	arr[0] = 10;
}
void test5(int ref) {
	ref = 10;
}
int main() {
	int a = 5;
	int b = 10;

	int& aRef = a;

	aRef++;

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* arrPtr = arr;
	arrPtr++;
	arrPtr++;

	std::cout << *arrPtr;

	arrPtr = nullptr;

	// charptr++ vs intptr++;
}
