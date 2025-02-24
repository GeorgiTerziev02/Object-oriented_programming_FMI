#include <iostream>

size_t getCharCountByCondition(const char* str, bool(*predicate)(char ch)) {
	if (!str) {
		return 0;
	}

	size_t count = 0;
	while (*str) {
		if (predicate(*str)) {
			count++;
		}
		str++;
	}

	return count;
}

bool isLowerLetter(char ch) {
	return 'a' <= ch && ch <= 'z';
}

size_t getLowerCount(const char* str) {
	return getCharCountByCondition(str, isLowerLetter);
}

size_t getDigitsCount(const char* str) {
	return getCharCountByCondition(str, [](char ch) {
		return '0' <= ch && ch <= '9';
	});
}

int main() {
	char str[] = "Hello World!123";
	std::cout << getDigitsCount(str);
}
