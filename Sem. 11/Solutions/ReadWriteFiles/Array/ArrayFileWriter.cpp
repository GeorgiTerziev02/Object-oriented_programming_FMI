#include "ArrayFileWriter.h"
#include <fstream>

ArrayFileWriter::ArrayFileWriter(const MyString& fileName) : FileWriter(fileName)
{ }

void ArrayFileWriter::write(const int* arr, size_t size) const {
	std::ofstream out(fileName.c_str());
	if (!out.is_open()) {
		throw std::exception("Couldn't open file");
	}

	out << '[';
	for (size_t i = 0; i < size; i++) {
		out << arr[i];
		if (i != size - 1) {
			out << ' ';
		}
	}

	out << ']';
}