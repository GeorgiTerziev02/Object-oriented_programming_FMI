#pragma once
#include "FileReader.h"
class CSVFileReader : public FileReader {
public:
	CSVFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};