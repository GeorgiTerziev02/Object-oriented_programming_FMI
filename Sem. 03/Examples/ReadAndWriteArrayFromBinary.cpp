#include <iostream>
#include <fstream>

namespace Constants {
    constexpr char FILE_NAME[] = "test.bin";   
}

size_t getFileSize(std::ifstream& in) {
	size_t current = in.tellg();
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(current, std::ios::beg);

	return size;
}

int main() {
	{
		constexpr int SIZE = 5;
		int arr[SIZE] = {1, 2, 3, 4, 5};

		std::ofstream ofs(Constants::FILE_NAME, std::ios::binary);
        if (!ofs.is_open()) {
            return -1;
        }
		ofs.write((const char*)arr, SIZE * sizeof(int));
        ofs.close();
	}
    // if you know the size of the array
	{
		constexpr int SIZE = 5;
		int arr[SIZE] = {};

		std::ifstream ifs(Constants::FILE_NAME, std::ios::binary);
        if (!ifs.is_open()) {
            return -1;
        }
		ifs.read((char*)arr, SIZE * sizeof(int));

		for (int i = 0; i < SIZE; i++) {
			std::cout << arr[i] << " ";
        }
        ifs.close();
	}
    // if you don't know the size of the array
    {
        std::ifstream ifs(Constants::FILE_NAME, std::ios::binary);
        if (!ifs.is_open()) {
            return -1;
        }

        size_t fileSize = getFileSize(ifs);
        const int arraySize = fileSize / sizeof(int);
        int* arr = new int[arraySize];
        ifs.read((char*)arr, fileSize);

		for (int i = 0; i < arraySize; i++) {
			std::cout << arr[i] << " ";
        }
        delete[] arr;
        ifs.close();
    }
}