#pragma once
#include <fstream>

namespace StreamHelper {
    int getCharCount(std::ifstream& in, char ch);
    
	size_t getFileSize(std::ifstream& in);
};
