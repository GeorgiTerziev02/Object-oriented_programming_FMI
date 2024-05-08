#include "BinaryFileWriter.h"
#include <fstream>

BinaryFileWriter::BinaryFileWriter(const MyString& fileName) : FileWriter(fileName)
{ }

void BinaryFileWriter::write(const int* arr, size_t size) const {
	std::ofstream out(fileName.c_str(), std::ios::binary);
	if (!out.is_open()) {
		throw std::exception("Couldn't open file");
	}

	out.write((const char*)arr, size * sizeof(int));
}