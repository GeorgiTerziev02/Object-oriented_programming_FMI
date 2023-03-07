#include <iostream>
#include <fstream>

const char FILE_NAME[] = "results.txt";

void writeSumAndProductToFile(int a, int b, int c) {
    std::ofstream file(FILE_NAME);

    if (!file.is_open()) {
        return;
    }

    file << a + b + c << " " << a * b * c;
    file.close();
}

void readSumAndProductFromFile() {
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return;
    }

    int sum, product;
    file >> sum >> product;
    std::cout << sum - product << std::endl;
    
    file.close();
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    writeSumAndProductToFile(a, b, c);
    readSumAndProductFromFile();
}