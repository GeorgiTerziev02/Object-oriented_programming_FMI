#include "FilePath.h"

FilePath::FilePath(const MyString& fileName) {
	const char* begin = fileName.c_str();
	const char* iter = begin;
	const char* end = fileName.c_str() + fileName.getLength();
    
	while (iter != end && *iter != '.') {
		iter++;
	}
    
	name = StringView(begin, iter);
	extension = StringView(iter, end);
}

const StringView& FilePath::getName() const {
	return name;
}

const StringView& FilePath::getExtension() const {
	return extension;
}