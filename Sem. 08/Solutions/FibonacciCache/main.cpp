#include <iostream>

class NumbersCache {
private:
	static constexpr size_t MAX_SIZE = 1024;
	size_t numbers[MAX_SIZE] = {};
	size_t length;

	void assertIndex(size_t index) const {
		if (index >= length) {
			throw std::out_of_range("Invalid index");
		}
	}
public:
	NumbersCache(size_t length, const size_t* initialData, size_t initialNumbersCount) {
		this->length = std::min(length, MAX_SIZE);
		size_t count = std::min(initialNumbersCount, MAX_SIZE);
		for (size_t i = 0; i < count; i++) {
			numbers[i] = initialData[i];
		}
	}

	size_t get(size_t index) {
		assertIndex(index);
		return numbers[index];
	}

	void insert(size_t index, size_t value) {
		assertIndex(index);
		numbers[index] = value;
	}
};

// TODO: how to fix???
size_t initialNumber[] = { 1, 1 };

size_t fibonacci(size_t number) {
	static NumbersCache cache((size_t)1024, initialNumber, 2);

	if (cache.get(number) == 0) {
		cache.insert(number, fibonacci(number - 1) + fibonacci(number - 2));
	}

	return cache.get(number);
}

static constexpr int MAX_FIBONACCI = 1024;
int fibonacciWithoutCacheObject(unsigned number) {
	static unsigned cache[MAX_FIBONACCI] = { 1, 1 };
	if (number >= MAX_FIBONACCI) {
		throw std::out_of_range("Number too big!");
	}
	if (cache[number] == 0) {
		cache[number] = fibonacci(number - 1) + fibonacci(number - 2);
	}

	return cache[number];
}

int main() {}