#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum class ErrorCodes {
	OK,
	EmptyString,
	WrongChar,
	NullPtr,
};

struct Pairz {
	ErrorCodes code;
	int value;
};

int convertDigit(const char& ch) {
	return ch - '0';
}

bool isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

Pairz convert(const char* str) {
	
	Pairz p;
	p.value = 0;
	if (!str) {
		p.code = ErrorCodes::NullPtr;
		return p;
	}
	if (!*str) {
		p.code = ErrorCodes::EmptyString;
		return p;
	}

	int i = 0;
	while (*str) {
	
		if (!isDigit(*str)) {
			p.code = ErrorCodes::WrongChar;
			return p;
		}
		else {
			int curr = convertDigit(*str);
			i *= 10;
			i += curr;
			str++;
		}
	}
	p.value = i;
	p.code = ErrorCodes::OK;

	return p;
}


int main()
{
	Pairz data = convert(nullptr);
	if (data.code == ErrorCodes::OK) {
		cout << "Final: " << data.value << " Fine " << endl;
	}
	else {
		cout << "Final: " << data.value << " Not fine "<< endl;
	}

	return 0;
}
