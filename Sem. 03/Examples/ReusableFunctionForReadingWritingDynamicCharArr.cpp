#include <fstream>
#include <cstring> // strlen

void readDynamicCharArrayFromBinaryFile(std::ifstream& in, char*& str) {
	size_t nameLength;
	in.read((char*)&nameLength, sizeof(nameLength));
	str = new char[nameLength + 1];
	in.read((char*)str, nameLength);
	str[nameLength] = '\0';
}

void writeDynamicCharArrayToBinaryFile(std::ofstream& out, const char* str) {
	size_t nameLength = strlen(str);
	out.write((const char*)&nameLength, sizeof(nameLength));
	out.write((const char*)str, nameLength);
}