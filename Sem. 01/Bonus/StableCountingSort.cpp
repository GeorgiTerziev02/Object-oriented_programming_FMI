#include <iostream>

void stableCountingSort(char* arr, size_t length) {
	size_t arrLength = strlen(arr);
	char* copy = new char[arrLength];
	for (size_t i = 0; i < arrLength; i++) {
		copy[i] = arr[i];
	}
	
	int counter[256] = { 0 };
	for (size_t i = 0; i < length; i++) {
		counter[arr[i]]++;
	}

	// the counter with become the index where the next element
	// of everytime should be placed
	for (size_t i = 1; i < 256; i++) {
		counter[i] += counter[i - 1];
	}

	for (int i = arrLength - 1; i >= 0; i--) {
		arr[--counter[copy[i]]] = copy[i];
	}

	delete[] copy;
}

int main() {
	char arr[] = "ababababababa";
	stableCountingSort(arr, 13);
	std::cout << arr;
}