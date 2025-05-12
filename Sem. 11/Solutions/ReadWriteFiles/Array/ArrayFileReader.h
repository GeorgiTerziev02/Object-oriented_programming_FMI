#pragma once
#include "FileReader.h"

class ArrayFileReader : public FileReader {
public:
	ArrayFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};