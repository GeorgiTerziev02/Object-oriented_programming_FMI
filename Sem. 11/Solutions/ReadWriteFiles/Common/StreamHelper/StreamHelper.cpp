#include "StreamHelper.h"

namespace StreamHelper {
	int getCharCount(std::ifstream& ifs, char ch) {
		size_t currPos = ifs.tellg();

		if (!ifs.is_open()) {
			return -1;
		}

		int count = 0;
		while (true) {
			char current = ifs.get();

			if (ifs.eof()) {
				break;
			}

			if (current == ch) {
				count++;
			}
		}
		ifs.clear();
		ifs.seekg(currPos);
		return count;
	}

	size_t getFileSize(std::ifstream& inFile) {
		size_t currPos = inFile.tellg();
		inFile.seekg(0, std::ios::end);
		size_t res = inFile.tellg();
		inFile.seekg(currPos);

		return res;
	}
};