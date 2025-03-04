#include <fstream>

int main() {

    std::ofstream outfile("test.txt");

    for (int n = 0; n < 100; ++n)
    {
        outfile << n;
    }
    // put debugger here and check the file
    outfile.close();
}
