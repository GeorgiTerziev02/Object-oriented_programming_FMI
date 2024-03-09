#include <iostream>
#include <fstream>

namespace Constants {
    constexpr char FILE_NAME[] = "test.bin";   
}

struct Test {
    char ch;
    int n;
};

int main() {
    {
        Test t = {'A', 12345};
        std::ofstream ofs(Constants::FILE_NAME, std::ios::out | std::ios::binary);
        if (!ofs.is_open()) {
            return -1;
        }
        ofs.write((const char*)&t, sizeof(t));
    }
    {
        Test t;
        std::ifstream ifs(Constants::FILE_NAME, std::ios::in | std::ios::binary);
        if (!ifs.is_open()) {
            return -1;
        }
        ifs.read((char*)&t, sizeof(t));
        std::cout << t.ch << " " << t.n << std::endl;
    }
}