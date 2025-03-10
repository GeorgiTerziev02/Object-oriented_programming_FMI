#include <iostream>
#include <fstream>

namespace Constants {
    constexpr char FILE_NAME[] = "test.bin";   
}

int main() {
	{
		int n = 12345;
		std::ofstream ofs(Constants::FILE_NAME, std::ios::out | std::ios::binary);
        if (!ofs.is_open()) {
            return -1;
        }
		ofs.write((const char*)&n, sizeof(n));
        ofs.close();
	}
	{
		int n;
		std::ifstream ifs(Constants::FILE_NAME, std::ios::in | std::ios::binary);
        if (!ifs.is_open()) {
            return -1;
        }
		ifs.read((char*)&n, sizeof(n));
		std::cout << n << std::endl;
        ifs.close();
	}
}