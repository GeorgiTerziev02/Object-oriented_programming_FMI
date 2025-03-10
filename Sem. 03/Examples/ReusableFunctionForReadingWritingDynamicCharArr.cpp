#include <fstream>
#include <cstring> // strlen

namespace HelperFunctions {
	void readDynamicCharArrayFromBinaryFile(std::ifstream& in, char*& str) {
		size_t strLength;
		in.read((char*)&strLength, sizeof(strLength));
		str = new char[strLength + 1];
		in.read(str, strLength);
		str[strLength] = '\0';
	}

	void writeDynamicCharArrayToBinaryFile(std::ofstream& out, const char* str) {
		size_t strLength = strlen(str);
		out.write((const char*)&strLength, sizeof(strLength));
		out.write(str, strLength);
	}
}
