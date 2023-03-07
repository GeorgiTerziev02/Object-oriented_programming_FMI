#include <iostream>
#include <fstream>

using namespace std;

const int MAX_STRING_LENGTH = 100;

void preparingFiles() {
    ofstream placeholder("placeholder.txt");

    if (!placeholder.is_open()) {
        return;
    }

    placeholder << "title Veliki" << endl;
    placeholder << "recipient_name Pop Armeniya" << endl;
    placeholder << "message Iskam da se oplacha!!! " << endl;
    placeholder << "sender_name FMI-student" << endl;

    placeholder.close();

    ofstream out("task03.txt");
    if (!out.is_open()) {
        return;
    }
    out << "Dear, {title} {recipient_name}." << endl;
    out << "{message}" << endl << endl;
    out << "Sincerely," << endl;
    out << "{sender_name}" << endl;

    out.close();
}

int strLen(const char* arr) {
    int count = 0;

    while (arr[count] != '\0') {
        count++;
    }
    return count;
}

bool strCmp(const char* arr1, const char* arr2) {
    if (strLen(arr1) != strLen(arr2)) {
        return false;
    }
    unsigned int length = strLen(arr1);
    for (unsigned int i = 0; i < length; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}
unsigned getFileLength(ifstream& in)
{
    size_t currentPosition = in.tellg();
    in.seekg(0,ios::beg);

    if (!in.is_open())
        return 0;

    unsigned int count = 0;

    while (true)
    {
        char current = in.get();
        if (in.eof())
            break;

        if (current == '\n')
            count++;
    }

    in.clear();
    in.seekg(currentPosition);
    return count;
}
void getReplacementValuesInArray(char** type_placeholder, char** replacement, ifstream& placeholder, unsigned int len) {

    for(int i=0;i<len;i++){
        placeholder.getline(type_placeholder[i], MAX_STRING_LENGTH,' ');
        placeholder.getline(replacement[i], MAX_STRING_LENGTH);

        if (placeholder.eof()) {
            break;
        }
    }
}
void writeReplacementFromPlaceholder(const char* name, ofstream& out, char** type_placeholder, char** replacement, unsigned int len) {

    for (int i = 0; i < len; i++) {
        if (strCmp(type_placeholder[i], name)) {
            out << replacement[i];
        }
    }
}

int replacingPlaceholder() {

    ifstream in("task03.txt");

    ofstream out("task03_copy.txt");

    ifstream placeholder("placeholder.txt");

    unsigned int len = getFileLength(placeholder)+1;

    char** type_placeholder = new char*[len];
    char** replacement = new char*[len];

    for (int i = 0; i < len; i++) {
        type_placeholder[i] = new char[MAX_STRING_LENGTH];
        replacement[i] = new char[MAX_STRING_LENGTH];
    }

    size_t currentPosition = in.tellg();

    if (!in.is_open() || !out.is_open() || !placeholder.is_open()) {
        cout << "Error";
        return -1;
    }

    getReplacementValuesInArray(type_placeholder, replacement, placeholder,len);

    while (true) {
        placeholder.clear();
        placeholder.seekg(0, ios::beg);

        char current = in.get();

        if (in.eof()) {
            break;
        }

        if (current == '{') {
            char name[MAX_STRING_LENGTH];

            in.getline(name, MAX_STRING_LENGTH, '}');

            writeReplacementFromPlaceholder(name, out,type_placeholder,replacement,len);
            continue;
        }

        out << current;
    }
    in.close();
    out.close();
    placeholder.close();
}

int main() {
    preparingFiles();

    replacingPlaceholder();
}