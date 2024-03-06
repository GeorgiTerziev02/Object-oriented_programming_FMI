#include <iostream>
#include <fstream>

namespace FileNames
{
    constexpr char SOURCE_NAME[] = "test.bin";
    constexpr char ODD_NAME[] = "odd.bin";
    constexpr char EVEN_NAME[] = "even.bin";
}

struct FileData {
    int* buffer = nullptr;
    size_t arrSize = 0;
};

void freeFileData(FileData& data) {
    delete[] data.buffer;
    data.buffer = nullptr;
    data.arrSize = 0;
}

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

FileData readData(std::ifstream& in) {
    size_t fileSize = getFileSize(in);
    size_t arrSize = fileSize / sizeof(int);
    int* buffer = new int[arrSize];
    in.read((char*)buffer, fileSize);

    return { buffer, arrSize };
}

size_t getEvenCount(const int* arr, size_t length) {
    size_t count = 0;
    for (size_t i = 0; i < length; i++) {
        if (!(arr[i] & 1)) {
            count++;
        }
    }

    return count;
}

void divide(const FileData& data, int*& evenArr, int*& oddArr, size_t& evenCount) {
    evenCount = getEvenCount(data.buffer, data.arrSize);
    evenArr = new int[evenCount];
    oddArr = new int[data.arrSize - evenCount];
    size_t evenIndex = 0;
    size_t oddIndex = 0;
    for (size_t i = 0; i < data.arrSize; i++) {
        if (data.buffer[i] & 1) {
            evenArr[oddIndex++] = data.buffer[i];
        } else {
            evenArr[evenIndex++] = data.buffer[i];
        }
    }
}

// TOOD: refactor this function - personally do not like the way it is written
// first check if we can open the file
// if we can not open the file => no need to read from any of them
void divideOddAndEven(const char* sourceName, const char* oddName, const char* evenName) {
    std::ifstream in(sourceName, std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Cannot open file " << sourceName << std::endl;
        return;
    }

    std::ofstream odd(oddName, std::ios::binary);
    if (!odd.is_open()) {
        std::cout << "Cannot open file " << oddName << std::endl;
        in.close();
        return;
    }

    std::ofstream even(evenName, std::ios::binary);
    if (!even.is_open()) {
        std::cout << "Cannot open file " << evenName << std::endl;
        in.close();
        odd.close();
        return;
    }

    FileData data = readData(in);
    in.close();
    int* evenArr = nullptr;
    int* oddArr = nullptr;
    size_t evenCount;
    divide(data, evenArr, oddArr, evenCount);
    odd.write((char*)oddArr, (data.arrSize - evenCount) * sizeof(int));
    even.write((char*)evenArr, evenCount * sizeof(int));
    
    freeFileData(data);
    delete[] evenArr;
    delete[] oddArr;

    odd.close();
    even.close();
}

int main() {
    divideOddAndEven(FileNames::SOURCE_NAME, FileNames::ODD_NAME, FileNames::EVEN_NAME);
}