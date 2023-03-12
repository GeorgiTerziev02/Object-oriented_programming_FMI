#pragma once

void flushStream();

void printInputCharacter();

void printOperationResultMessage(bool result);

bool isLetter(const char& character);

void printLetter(const char& byte);

void moveIndexToNextSeparator(const char* str, int& startIndex, const char& separator);

void printHex(const char& byte);

bool isValidHex(char* hex);

int customPow(int number, int degree);

int hexToDecimal(char* hex);