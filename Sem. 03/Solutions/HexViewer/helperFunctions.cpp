#include <iostream>
#include "helperFunctions.h"
#include "stringHelperFunctions.h"
#include "constants.h"

using namespace std;


void flushStream() {
	cin.clear();
	cin.ignore(255, '\n');
}

void printInputCharacter() {
	cout << ">";
}

void printOperationResultMessage(bool result) {
	cout << (result ? SUCCESSFUL_OPERATION_MESSAGE : UNSUCCESSFUL_OPERATION_MESSAGE) << endl;
}

bool isLetter(const char& character) {
	return (UPPERCASE_A_ASCII_CODE <= character && character <= UPPERCASE_Z_ASCII_CODE)
		|| (LOWERCASE_A_ASCII_CODE <= character && character <= LOWERCASE_Z_ASCII_CODE);
}

void printLetter(const char& byte) {
	if (isLetter(byte))
	{
		cout << byte;
	}
	else
	{
		cout << ".";
	}
	cout << "  ";
}

void moveIndexToNextSeparator(const char* str, int& startIndex, const char& separator) {
	while (str[startIndex] != separator && str[startIndex] != '\0')
	{
		startIndex++;
	}
}

void printHex(const char& byte) {
	char hex[HEX_SIZE];

	// definitely not the right way
	int quotient = byte / 16;
	int remainder = byte % 16;
	hex[0] = quotient > 9 ? (quotient - 10 + UPPERCASE_A_ASCII_CODE) : (quotient + '0');
	hex[1] = remainder > 9 ? (remainder - 10 + UPPERCASE_A_ASCII_CODE) : (remainder + '0');
	hex[2] = '\0';

	cout << hex << " ";
}

bool isValidHex(char* hex) {
	for (size_t i = 0; i < hex[i] != '\0'; i++)
	{
		if (!(('0' <= hex[i] && hex[i] <= '9') || (UPPERCASE_A_ASCII_CODE <= hex[i] && hex[i] <= UPPERCASE_F_ASCII_CODE)))
		{
			return false;
		}
	}

	return true;
}

int customPow(int number, int degree) {
	if (degree == 0)
	{
		return 1;
	}

	int result = 1;
	for (size_t i = 0; i < degree; i++)
	{
		result *= number;
	}

	return result;
}

int hexToDecimal(char* hex) {
	size_t length = strLength(hex);

	int result = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (UPPERCASE_A_ASCII_CODE <= hex[i])
		{
			int num = hex[i] - UPPERCASE_A_ASCII_CODE + 10;
			result += num * customPow(16, length - i - 1);
		}
		else {
			int num = hex[i] - '0';
			result += num * customPow(16, length - i - 1);
		}
	}

	return result;
}