#pragma once

#include <fstream>
#include "file.h"

bool saveToFile(const File& file, const char* fileName);

int getFileSize(std::ifstream& file);

bool readFile(File& file);