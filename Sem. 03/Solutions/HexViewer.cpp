#include <iostream>
#include <fstream>

void changeByteAtIndex(const char* fileName, size_t index, char newValue) {
  // TODO: why is this truncating the file???
	std::ofstream out("test.bin", std::ios::binary | std::ios::ate);
	if (!out.is_open()) {
		return;
	}

	out.seekp(index, std::ios::beg);
	out.write((const char*)&newValue, sizeof(newValue));

	out.close();
}

int main() {
	constexpr char FILE_NAME[] = "test.bin";
	std::ofstream out("test.bin", std::ios::binary | std::ios::ate);

	changeByteAtIndex(FILE_NAME, 3, 'Q');
}
