#include <iostream>

void inputArr(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

int countBiggerSymbols(const int* arr, const int size, const char symbol) { 
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > symbol) {
			counter++;
		}
	}

	return counter;
}

int main() {
	int size = 0;
	std:: cin >> size;

	int* arr = new int[size];
	inputArr(arr, size);

	char symbol;
	std::cin >> symbol;

	std::cout << countBiggerSymbols(arr, size, symbol) << std::endl;

	delete[] arr;
}