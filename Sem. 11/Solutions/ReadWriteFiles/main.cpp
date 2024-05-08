#include <iostream>
#include "ArrayFileReader.h"
#include "ArrayFileWriter.h"
#include "BinaryFileReader.h"
#include "BinaryFileWriter.h"
#include "CSVFileReader.h"
#include "CSVFileWriter.h"
#include "./Common/FilePath/FilePath.h"

FileReader* fileReaderFactory(const MyString& fileName) {
	FilePath filePath(fileName);

	if (filePath.getExtension() == ".csv") {
		return new CSVFileReader(fileName);
	}
	if (filePath.getExtension() == ".dat") {
		return new BinaryFileReader(fileName);
	}
	if (filePath.getExtension() == ".arr") {
		return new ArrayFileReader(fileName);
	}

	throw std::invalid_argument("Files with this extension can't be read.");
}

FileWriter* fileWriterFactory(const MyString& fileName) {
	FilePath filePath(fileName);

	if (filePath.getExtension() == ".csv") {
		return new CSVFileWriter(fileName);
	}
	if (filePath.getExtension() == ".dat") {
		return new BinaryFileWriter(fileName);
	}
	if (filePath.getExtension() == ".arr") {
		return new ArrayFileWriter(fileName);
	}

	throw std::invalid_argument("Files with this extension can't be read.");
}

void transfer(const MyString& fromName, const MyString& toName) {
	FileReader* reader = fileReaderFactory(fromName);
	int* arr;
	size_t size;
	reader->read(arr, size);
	// sort
	FileWriter* writer = fileWriterFactory(toName);
	writer->write(arr, size);

	delete[] arr;
	delete reader;
	delete writer;
}

int main() {
	transfer("numbers.csv", "numbers.arr");
}