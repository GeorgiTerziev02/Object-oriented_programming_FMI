#include <fstream>

size_t getFileSize(const char* name) {
	std::ifstream in(name);
	if (!in.is_open()) {
		return 0;
    }
	
	in.seekg(0, std::ios::end);
	size_t currentPos = in.tellg();
	in.close();
    
	return currentPos;
}