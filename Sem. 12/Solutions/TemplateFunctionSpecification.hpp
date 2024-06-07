#include <iostream>

template<typename T>
void print(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<>
void print(char* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ---- ";
	}
	std::cout << std::endl;
}

int main() {
	int arr1[] = { 1, 2 };
	print(arr1, 2);
	char arr2[] = { 'a', 'b' };
	print(arr2, 2);
}

// This is not a specialization
// void print(char* arr, size_t size) {
// 	for (size_t i = 0; i < size; i++) {
// 		std::cout << arr[i] << " ---- ";
// 	}
// 	std::cout << std::endl;
// }
