#pragma once
#include "../MyString/MyString.h"
#include "../StringView/StringView.h"

class FilePath {
private:
	StringView name;
	StringView extension;

public:
	FilePath(const MyString& fileName);

	const StringView& getName() const;
	const StringView& getExtension() const;
};