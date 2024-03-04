#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum ErrorCodes {
	OK,
	NullPointer,
	EmptyString,
	HasALetter,
	HasOtherSymbol,
	NumberIsNegative
};

struct Pair {
	int number;
	ErrorCodes statusCode;
};

Pair createNumberFromString(const char* str) {
	if (!str) {
		return Pair{ 0, NullPointer };
	}

	if (str == "") {
		return Pair{ 0, EmptyString };
	}

	if (str[0] == '-') {
		return Pair{ 0, NumberIsNegative };
	}

	int number = 0;
	unsigned int i = 0;
	while (str[i]) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			return Pair{ 0, HasALetter };
		}

		if (str[i] < 0 || str[i] > 9) {
			return Pair{ 0, HasOtherSymbol };
		}

		number = (number * 10) + str[i] - '0';

		i++;
	}

	return Pair{ number, OK };
}

void outputPair(const Pair& p) {
	cout << p.number << ", ";

	switch (p.statusCode) {
		case 0: cout << "OK"; break;
		case 1: cout << "NullPointer"; break;
		case 2: cout << "EmptyString"; break;
		case 3: cout << "HasALetter"; break;
		case 4: cout << "HasOtherSymbol"; break;
		case 5: cout << "NumberIsNegative"; break;
	}

	cout << endl;
}

int main()
{
	char str[] = "-12345";

	outputPair(createNumberFromString(str));
}