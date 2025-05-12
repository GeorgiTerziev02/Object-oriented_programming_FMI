#pragma once
#include "../Common/MyString/MyString.h"

class FileReader {
protected:
	MyString fileName;

public:
	FileReader(const MyString& fileName);
	virtual void read(int*& arr, size_t& size) const = 0;
	virtual ~FileReader() = default;
};