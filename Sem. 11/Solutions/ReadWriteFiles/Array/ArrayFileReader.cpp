#include "ArrayFileReader.h"
#include <fstream>
#include "../StreamHelper/StreamHelper.h"

ArrayFileReader::ArrayFileReader(const MyString& fileName) : FileReader(fileName) { }

void ArrayFileReader::read(int*& arr, size_t& size) const {
	std::ifstream in(fileName.c_str());
	if (!in.is_open()) {
		throw std::exception("Couldn't open file");
	}

	size = StreamHelper::getCharCount(in, ' ') + 1;
	delete[] arr;
	arr = new int[size];
	for (size_t i = 0; i < size; i++) {
		in >> arr[i];
	}
}