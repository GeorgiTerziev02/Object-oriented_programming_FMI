#pragma once
#include "../Common/MyString/MyString.h"

class FileWriter {
protected:
	MyString fileName;

public:
	FileWriter(const MyString& fileName);
	virtual void write(const int* arr, size_t size) const = 0;
	virtual ~FileWriter() = default;
};