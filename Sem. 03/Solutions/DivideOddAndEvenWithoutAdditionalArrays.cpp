#include <iostream>
#include <fstream>

namespace ErrorMessages {
    constexpr char CANNOT_OPEN_FILE[] = "Cannot open file ";
}

namespace FileNames {
    constexpr char SOURCE_NAME[] = "test.bin";
    constexpr char ODD_NAME[] = "odd.bin";
    constexpr char EVEN_NAME[] = "even.bin";
}

void divideOddAndEven(const char* sourceName, const char* oddName, const char* evenName) {
    std::ifstream in(sourceName, std::ios::binary);
    if (!in.is_open()) {
        std::cout << ErrorMessages::CANNOT_OPEN_FILE << sourceName << std::endl;
        return;
    }

    std::ofstream odd(oddName, std::ios::binary);
    if (!odd.is_open()) {
        std::cout << ErrorMessages::CANNOT_OPEN_FILE << oddName << std::endl;
        in.close();
        return;
    }

    std::ofstream even(evenName, std::ios::binary);
    if (!even.is_open()) {
        std::cout << ErrorMessages::CANNOT_OPEN_FILE << evenName << std::endl;
        in.close();
        odd.close();
        return;
    }
    
    while(true) {
        int number;
        in.read((char*)&number, sizeof(number));
        if (in.eof()) {
            break;
        }
        if (number & 1) {
            odd.write((char*)&number, sizeof(number));
        } else {
            even.write((char*)&number, sizeof(number));
        }
    }

    in.close();
    odd.close();
    even.close();
}

int main() {
    divideOddAndEven(FileNames::SOURCE_NAME, FileNames::ODD_NAME, FileNames::EVEN_NAME);
}