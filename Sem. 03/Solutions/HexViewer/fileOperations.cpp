#include <iostream>
#include <fstream>
#include "fileOperations.h"

using namespace std;

bool readFile(File& file) {
	ifstream inputFile(file.name, ios::binary);

	if (!inputFile.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	int size = getFileSize(inputFile);
	file.size = size;

	int index = 0;
	while (!inputFile.eof())
	{
		inputFile.read((char*)&file.data[index++], sizeof(char));
	}

	inputFile.close();
	return true;
}

int getFileSize(std::ifstream& file) {
	int current = file.tellg();
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.seekg(current, ios::beg);

	return size;
}

bool saveToFile(const File& file, const char* fileName) {
	ofstream outputFile(fileName);

	if (!outputFile.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	for (size_t i = 0; i < file.size; i++)
	{
		outputFile.write((char*)&file.data[i], sizeof(char));
	}

	outputFile.close();
	return true;
}