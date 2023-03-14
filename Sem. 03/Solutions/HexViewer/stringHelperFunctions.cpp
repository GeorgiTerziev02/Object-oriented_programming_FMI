#include "stringHelperFunctions.h"

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

char* subStr(const char* str, const int& startIndex, const int& endIndex) {
	int resultSize = endIndex - startIndex + 2;
	char* result = new char[resultSize];

	int length = strLength(str);
	if (startIndex > endIndex || endIndex >= length)
	{
		return result;
	}

	for (size_t i = 0; i < resultSize - 1; i++)
	{
		result[i] = str[startIndex + i];
	}

	result[resultSize - 1] = '\0';

	return result;
}

bool strCmp(const char* str1, const char* str2) {
	int length1 = strLength(str1);
	int length2 = strLength(str2);

	if (length1 != length2) return false;

	for (size_t i = 0; i < length1; i++)
	{
		if (str1[i] != str2[i]) return false;
	}

	return true;
}
