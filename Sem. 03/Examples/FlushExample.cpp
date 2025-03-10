#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "FlushExample.bin";

int main() {
    std::ofstream out(FILE_NAME, std::ios::binary);
    if(!out.is_open()) {
        std::cout << "Cannot open file " << FILE_NAME << std::endl;
        return 1;
    }

    int data = 155555;
    out.write((char*)&data, sizeof(data));
    out.flush(); // try to comment this line and check the file
    out.write((char*)&data, sizeof(data));
    out.write((char*)&data, sizeof(data));
    out.write((char*)&data, sizeof(data));

    // place the breakpoint here and check the file
    out.close();
}
