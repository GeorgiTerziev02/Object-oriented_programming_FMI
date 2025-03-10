#include <iostream>
#include <fstream>

namespace Constants {
    constexpr char FILE_NAME[] = "test.bin";
    constexpr int BYTES_COUNT = 256;
}

struct FileData {
    unsigned char* buffer = nullptr;
    size_t fileSize = 0;
};

void freeFileData(FileData& data) {
    delete[] data.buffer;
    data.buffer = nullptr;
    data.fileSize = 0;
}

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

FileData getFileContent(const char* fileName) {
    std::ifstream in(Constants::FILE_NAME, std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Cannot open file " << Constants::FILE_NAME << std::endl;
        return {};
    }

    size_t fileSize = getFileSize(in);
    unsigned char* buffer = new unsigned char[fileSize];
    in.read((char*)buffer, fileSize);
    in.close();

    return { buffer, fileSize };
}

void printMissingBytes(const FileData& data) {
    int counter[Constants::BYTES_COUNT] = { 0 };
    for (size_t i = 0; i < data.fileSize; i++) {
        counter[data.buffer[i]]++;
    }

    for (int i = 0; i < Constants::BYTES_COUNT; i++) {
        if (counter[i] == 0) {
            std::cout << "Byte " << i << " is missing" << std::endl;
        }
    }
}

int main() {
    FileData data = getFileContent(Constants::FILE_NAME);

    printMissingBytes(data);

    freeFileData(data);
}