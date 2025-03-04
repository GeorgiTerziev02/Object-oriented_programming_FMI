#include <fstream>

const char FILE_NAME = "test.txt";

int main() {

    std::ofstream outfile(FILE_NAME);

    for (int n = 0; n < 100; ++n)
    {
        outfile << n;
    }
    // put debugger here and check the file
    outfile.close();
}
