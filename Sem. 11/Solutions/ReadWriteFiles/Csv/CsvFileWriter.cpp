#include "CSVFileWriter.h"
#include <fstream>

CSVFileWriter::CSVFileWriter(const MyString& fileName) : FileWriter(fileName)
{ }

void CSVFileWriter::write(const int* arr, size_t size) const {
	std::ofstream out(fileName.c_str());
	if (!out.is_open()) {
		throw std::exception("Couldn't open file");
	}

	for (size_t i = 0; i < size; i++) {
		out << arr[i];

		if (i != size - 1) {
			out << ',';
		}
	}
}