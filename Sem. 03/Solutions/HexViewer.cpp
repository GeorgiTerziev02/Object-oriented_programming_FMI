#include <iostream>
#include <fstream>

namespace Constants {
	constexpr char FILE_NAME[] = "test.bin";
}

void changeByteAtIndex(const char* fileName, size_t index, char newValue) {
	std::ofstream out(fileName, std::ios::binary | std::ios::in | std::ios::ate);
	if (!out.is_open()) {
		return;
	}

	out.seekp(index, std::ios::beg);
	out.write((const char*)&newValue, sizeof(newValue));

	out.close();
}

int main() {
	changeByteAtIndex(Constants::FILE_NAME, 3, 'M');
}
