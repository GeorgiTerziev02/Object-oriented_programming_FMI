#include <iostream>
#include <fstream>

namespace Constants {
	constexpr char FILE_NAME[] = "test.bin";
	constexpr int HEX_ARRAY_SIZE = 2 + 1;
}

namespace HelperFunctions {
	size_t getFileSize(std::ifstream& in) {
		size_t current = in.tellg();
		in.seekg(0, std::ios::end);
		size_t size = in.tellg();
		in.seekg(current, std::ios::beg);

		return size;
	}

	void getHexValue(unsigned char byte, char hex[Constants::HEX_ARRAY_SIZE]) {
		// definitely not the best way to do it
		int quotient = byte / 16;
		int remainder = byte % 16;
		hex[0] = quotient > 9 ? (quotient - 10 + 'A') : (quotient + '0');
		hex[1] = remainder > 9 ? (remainder - 10 + 'A') : (remainder + '0');
		hex[2] = '\0';
	}

	bool isValidByteForPrinting(unsigned char ch) {
		return ('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'Z');
	}
}

void changeByteAtIndex(const char* fileName, size_t index, char newValue) {
	// opening with std::ios::in | std::ios::ate to prevent truncating the file
	// other solution opening with std::ios::_Nocreate
	std::ofstream out(fileName, std::ios::binary | std::ios::in | std::ios::ate);
	if (!out.is_open()) {
		return;
	}

	out.seekp(index, std::ios::beg);
	out.write((const char*)&newValue, sizeof(newValue));
	out.close();
}

void printHexFile(const char* fileName) {
	std::ifstream in(fileName, std::ios::binary);
	if (!in.is_open()) {
		return;
	}

	size_t arrSize = HelperFunctions::getFileSize(in);
	unsigned char* arr = new unsigned char[arrSize];
	in.read((char*)arr, arrSize);
	in.close();

	for (size_t i = 0; i < arrSize; i++) {
		if (HelperFunctions::isValidByteForPrinting(arr[i])) {
			char hexValue[Constants::HEX_ARRAY_SIZE];
			HelperFunctions::getHexValue(arr[i], hexValue);
			std::cout << hexValue;
		}
		else {
			std::cout << "..";
		}
	}

	delete[] arr;
}

int main() {
	changeByteAtIndex(Constants::FILE_NAME, 3, 'M');
}
