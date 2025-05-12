#include "BinaryFileReader.h"
#include <fstream>
#include "../StreamHelper/StreamHelper.h"

BinaryFileReader::BinaryFileReader(const MyString& fileName) : FileReader(fileName)
{ }

void BinaryFileReader::read(int*& arr, size_t& size) const {
	std::ifstream in(fileName.c_str(), std::ios::binary);
	if (!in.is_open()) {
		throw std::exception("Couldn't open file");
	}

	size = StreamHelper::getFileSize(in) / sizeof(int);
	delete[] arr;
	arr = new int[size];
	in.read((char*)arr, size * sizeof(int));
}