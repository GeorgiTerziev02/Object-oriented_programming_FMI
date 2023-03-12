#include "commands.h"
#include "helperFunctions.h"
#include <iostream>

using namespace std;

void viewFile(const File& file) {
	int index = 0;
	while (index < file.size)
	{
		printHex(file.data[index++]);
	}

	cout << endl;

	index = 0;
	while (index < file.size)
	{
		printLetter(file.data[index++]);
	}

	cout << endl;
}

bool changeByteAtIndex(File& file, const char& character, int index) {
	if (index >= file.size)
	{
		return false;
	}

	file.data[index] = character;
	return true;
}

bool removeByteFromEnd(File& file) {
	if (file.size == 0)
	{
		return false;
	}

	file.data[--file.size] = '\0';
	return true;
}

bool addByteToEnd(File& file, const char& character) {
	if (file.size == FILE_SIZE)
	{
		return false;
	}

	file.data[file.size++] = character;
	return true;
}