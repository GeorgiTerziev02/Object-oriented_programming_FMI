#pragma once
#include "FileReader.h"
class BinaryFileReader : public FileReader {
public:
	BinaryFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};