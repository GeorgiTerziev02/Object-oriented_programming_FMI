#include <iostream>
#include <fstream>
using namespace std;
const int BUFFER_SIZE = 1024;
const char leftBracket = '(';
const char rightBracket = ')';
bool searchRightBracket(char(&buffer)[1024], int& i) {
    while (buffer[i] != '\0') {
        if (buffer[i] == rightBracket) {
            return true;
        }
        i++;
    }
    return false;
}
bool doesBufferHavePlaceholder(char(&buffer)[1024]) {
    int i = 0;
    bool leftBracketFlag = 0, rightBracketFlag = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == leftBracket) {
            leftBracketFlag = true;
            rightBracketFlag = searchRightBracket(buffer, i);
        }
        if (leftBracketFlag && rightBracketFlag) {
            return true;
        }
        i++;
    }
    return false;
}

void replacePlaceholder(ifstream& in, const char(&replacement)[1024]) {
    ofstream out;
    out.open("text1.txt");
    while (!in.eof()) {
        char buffer[BUFFER_SIZE];
        in.getline(buffer, BUFFER_SIZE);
        if (doesBufferHavePlaceholder(buffer)) {
            if (out.is_open()) {
                out << replacement;
            }
        }
    }
}
int main()
{
    char replacemnt[BUFFER_SIZE];
    cin.getline(replacemnt, BUFFER_SIZE);
    ifstream in;
    in.open("text.txt");
    replacePlaceholder(in, replacemnt);
}