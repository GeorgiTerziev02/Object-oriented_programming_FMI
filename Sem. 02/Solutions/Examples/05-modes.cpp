#include <iostream>
#include <fstream>
#include "constants.h"

int modes() {
	std::fstream file(FILE_NAME, std::ios_base::ate | std::ios_base::out | std::ios_base::_Nocreate);
	// std::ios_base::in - read mode - base ifstream mode
	// std::ios_base::out - read mode - base ofstream mode
	// std::ios_base::binary - binary mode - next time
	// std::ios_base::trunc - if the file exists delets the content
	// std::ios_base::app - seekp at the end, write operations can be performed ONLY at the end
	// std::ios_base::ate - seekp at the end, write operations can be performed anywhere, we can move the seekp
	// std::ios_base::nocreate - opens the file only if it exist
	// std::ios_base::noreplace - opens the file only if it DOES NOT exist

	if (!file.is_open()) {
		std::cout << INVALID_FILE_ERR_MSG;
		return -1;
	}

	file.seekp(0, std::ios::beg);

	file << "fsdaf";
}
