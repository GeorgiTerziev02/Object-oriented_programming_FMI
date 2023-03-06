#include <iostream>
#include <fstream>
using namespace std;
const int BUFFER_SIZE=1024;
void countOneLine(const char (&buffer)[BUFFER_SIZE], int& count) {
    int i = 0;
    while (buffer[i] != '\0') {
        i++;
        count++;
    }
}
int lengthOfFile(ifstream& in,int& count) {
    in.open("text.txt");
    if (!in.is_open()) {
        return -1;
    }
    while (!in.eof()) {
        char buffer[BUFFER_SIZE];
        in.getline(buffer, BUFFER_SIZE);
        countOneLine(buffer, count);
    }
    return count;
}
int main()
{
    ifstream in;
    int count = 0;
    count = lengthOfFile(in, count);
    cout << count;
    return 0;
}