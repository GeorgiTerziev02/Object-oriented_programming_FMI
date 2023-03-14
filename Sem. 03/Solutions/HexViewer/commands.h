#pragma once

#include "file.h"

void viewFile(const File& file);

bool changeByteAtIndex(File& file, const char& character, int index);

bool removeByteFromEnd(File& file);

bool addByteToEnd(File& file, const char& character);