#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

int main() {
    std::ifstream in("OOP.cpp");
    if (!in.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return -1;
    }

    std::cout << getFileSize(in) << std::endl;
}