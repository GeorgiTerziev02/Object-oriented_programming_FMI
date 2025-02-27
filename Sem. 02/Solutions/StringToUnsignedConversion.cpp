#include <iostream>
#include <fstream>

namespace HelperFunctions {
	bool isDigit(char ch) {
		return '0' <= ch && ch <= '9';
	}

	unsigned getDigitFromChar(char ch) {
		return ch - '0';
	}
};

enum class ErrorCode {
	NoError,
	NullptrProvided,
	EmptyStringProvided,
	StringIsNotANumber
};

struct ConversionResult {
	ErrorCode errorCode;
	unsigned result;
};

ConversionResult strToUnsignedInt(const char* str) {
	if (!str) {
		return { ErrorCode::NullptrProvided, 0 };
	}

	if (!*str) {
		return { ErrorCode::EmptyStringProvided, 0 };
	}

	unsigned result = 0;
	while (*str) {
		if (!HelperFunctions::isDigit(*str)) {
			return { ErrorCode::StringIsNotANumber, 0 };
		}

		result *= 10;
		result += HelperFunctions::getDigitFromChar(*str);
		str++;
	}

	return { ErrorCode::NoError, result };
}

int main() {
	ConversionResult conversionResult = strToUnsignedInt("123b45");

	if (conversionResult.errorCode == ErrorCode::NoError) {
		std::cout << conversionResult.result;
	}
	else {
		std::cout << "Error occurred with status: " << (int)conversionResult.errorCode;
	}
}