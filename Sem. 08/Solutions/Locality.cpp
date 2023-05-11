#include <chrono>
#include <iostream>

const size_t ARRAY_SIZE = 10000;

struct Test {
	int a;
	Test() {}
	Test(int a) : a(a) { }
};

// Forget about const correctness for this examples
size_t iterateArrayWithInstances(Test* arr, size_t arrSize) {
	size_t result = 0;
	for (size_t i = 0; i < arrSize; i++) {
		result += arr[i].a;
	}

	return result;
}

size_t iterateArrayWithPointers(Test** arr, size_t arrSize) {
	size_t result = 0;
	for (size_t i = 0; i < arrSize; i++) {
		result += arr[i]->a;
	}

	return result;
}

void pointersExample() {
	Test** arr = new Test*[ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = new Test(i);
	}

	auto begin = std::chrono::high_resolution_clock::now();
	iterateArrayWithPointers(arr, ARRAY_SIZE);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
}

void instancesExample() {
	Test arr[ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		arr[i].a = i;
	}

	auto begin = std::chrono::high_resolution_clock::now();
	iterateArrayWithInstances(arr, ARRAY_SIZE);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
}

int main() {
	instancesExample();
	pointersExample();
}