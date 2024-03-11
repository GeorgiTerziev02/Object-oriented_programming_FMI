#include <iostream>
#include <fstream>
#include <assert.h>

using std::cin;
using std::cout;

namespace Const {
    const size_t NUMBER_OF_NUMBERS = 3;
    const char* FILE_NAME = "result.txt";
}

struct Data
{
    size_t len = Const::NUMBER_OF_NUMBERS;
    int n[Const::NUMBER_OF_NUMBERS];
};

enum class OpeartionEnum {
    Add,
    Multiply
};

typedef void (*OpeartionFunction)(int&, int);

void add (int& sum, int b) {
    sum += b;
}
void multpily (int& sum, int b) {
    sum *= b;
}

int fmap(const Data& d, OpeartionEnum op) {
    int sum = -1;
    OpeartionFunction operation;
    if(op == OpeartionEnum::Add) {
        sum = 0;
        operation = add;
    } else if(op == OpeartionEnum::Multiply) {
        sum = 1;
        operation = multpily;
    } else {
        return sum;
    }

    for(size_t i = 0; i < d.len; i++) {
        operation(sum, d.n[i]);
        //cout << sum;
    }
    return sum;
}

Data EnterData() {
    Data d;
    for(size_t i = 0; i < d.len; i++) {
        cin >> d.n[i];
    }
    return d;
}

struct FileContent
{
    int sum, mult;
};


void WriteIntoFile(std::ofstream& ofs, const Data& d) {
    FileContent fC;
    fC.sum = fmap(d, OpeartionEnum::Add);
    fC.mult = fmap(d, OpeartionEnum::Multiply);

    ofs << fC.sum << " " << fC.mult;
}

void WriteIntoFile(const Data& d) {
    std::ofstream ofs(Const::FILE_NAME, std::ios::out | std::ios::trunc);

    assert(ofs.is_open());

    WriteIntoFile(ofs, d);

    ofs.close();
}

FileContent ReadFromFile(std::ifstream& ifs) {
    FileContent fC;
    ifs >> fC.sum >> fC.mult;
    return fC;
}

FileContent ReadFromFile() {
    std::ifstream ifs(Const::FILE_NAME, std::ios::in);
    assert(ifs.is_open());

    FileContent fC = ReadFromFile(ifs);

    ifs.close();
    return fC;
}

void PrintFileContent(const FileContent& fC) {
    cout << fC.sum << " " << fC.mult;
}

int main() {

    Data d = EnterData();
    WriteIntoFile(d);
    FileContent fC = ReadFromFile();
    PrintFileContent(fC);
}