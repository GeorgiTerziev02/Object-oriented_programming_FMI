#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <cstring>

using std::cin;
using std::cout;

namespace Const
{
  const size_t SUBJECT_NAME_SIZE = 32;  
  const char* FILE_NAME = "ZUZI.csv";
  const size_t BUFF_SIZE = 1024;
};

#define endl '\n'

enum class Category {
    OKN,
    M,
    PM,
    PR,
    Other
};

struct Subject {
    Category category;
    uint16_t id;
    uint8_t credits;
    uint8_t subjectType; // 1 - Exam, 2 - Course Project, 4 - Test (Adding them results into multiple types at once)
    char name[Const::SUBJECT_NAME_SIZE];
};

struct Table {
    size_t len = 0;
    Subject* subjects = nullptr;
};

size_t GetFileSize(std::ifstream& ifs) {
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t len =  ifs.tellg();
    ifs.seekg(curr);
    return len;
}

size_t GetNumberOfSymbolInAFile(std::ifstream& ifs, char ch) {
    size_t curr = ifs.tellg();

    size_t numberOfLines = 0;
    while(!ifs.eof()) {
        char buff[Const::BUFF_SIZE];
        ifs.getline(buff, Const::BUFF_SIZE, ch);
        numberOfLines++;
    }
    ifs.clear();
    ifs.seekg(curr);
    return numberOfLines;
}

size_t GetNumberOfSubjectsInAFile(std::ifstream& ifs) {
    return GetNumberOfSymbolInAFile(ifs, '\n') - 1;
}

void ReadSubjectFromRow(const char* buff, Subject& subject) {
    std::stringstream sss(buff);

    sss >> subject.id;
    sss.ignore();
    sss.getline(subject.name,Const::SUBJECT_NAME_SIZE, ',');
    int category;
    sss >> category;
    subject.category = (Category)category;
    sss.ignore();
    sss >> subject.credits;
    sss.ignore();
    sss >> subject.subjectType;
}

Table* ReadFromFile() {
    std::ifstream ifs(Const::FILE_NAME);
    
    if(ifs.is_open()) {

        Table* t = new Table();
        t->len = GetNumberOfSubjectsInAFile(ifs);
        t->subjects = new Subject[t->len];

        size_t index = 0;
        while(!ifs.eof()) {
            char buff[Const::BUFF_SIZE];
            ifs.getline(buff, Const::BUFF_SIZE, '\n');
            ReadSubjectFromRow(buff, t->subjects[index++]);
        }

        ifs.close();
        return t;
    } else {
        return new Table();
    } 
} 

void WriteOneSubjectIntoFile(std::ofstream& ofs, const Subject& subject) {
    ofs << subject.id << "," << subject.name << "," << (int)subject.category << "," << subject.credits << ',' << subject.subjectType << endl;
} 

void WriteIntoFile(std::ofstream& ofs, const Table* table) {
    for(size_t i = 0; i < table->len; i++ ) {
        WriteOneSubjectIntoFile(ofs, table->subjects[i]);
    }
}

void WriteIntoFile(const Table* table) {
    std::ofstream ofs(Const::FILE_NAME, std::ios::out | std::ios::trunc);

    assert(ofs.is_open());

    WriteIntoFile(ofs, table);
    ofs.close();
}

void PrintSubject(const Subject& subject) {
    cout << subject.id << ' ' << subject.name << ' ' << (int) subject.category << ' ' <<  subject.credits << ' ' <<  subject.subjectType << endl;
}

void PrintTable(const Table* table) {
    for(size_t i = 0; i < table->len; i++) {
        PrintSubject(table->subjects[i]);
    }
}

Table* FindSubjectById(const Table* table, uint16_t id) {
    for(size_t i = 0; i < table->len; i++) {
        if(id == table->subjects[i].id) {
            return new Table{1, new Subject(table->subjects[i])};
        }
    }
    return new Table();
}

bool AddSubject(Table* table, const Subject& st) {
    Table* newTable = FindSubjectById(table, st.id);

    if(newTable->len == 0) {
        // No Subject with this Id was found 
        table->len++;
        Subject* subjects = new Subject[table->len];
        for(size_t i = 0; i < table->len - 1; i++) {
            subjects[i] = table->subjects[i];
        }
        subjects[table->len - 1] = st;
        table->subjects = subjects;

    } else {
        // Subject found we need to change its params

        for(size_t i = 0; i < table->len; i++) {
            if(st.id == table->subjects[i].id) {
                strcpy(table->subjects[i].name, st.name);
                table->subjects[i].category = st.category;
                table->subjects[i].credits = st.credits;
                table->subjects[i].subjectType =  st.subjectType;
                break;
            }
        }
    }

    return true;
}

bool DeleteSubject(Table* table, uint16_t id) {
    for(size_t i = 0; i < table->len; i++) {
        if(id == table->subjects[i].id) {
            table->subjects[i] = table->subjects[--table->len];
            return true;
        }
    }
    return false;
}

size_t GetNumberOfSubjectsByCategory(const Table* table, Category category) {
    size_t count = 0;
    for(size_t i = 0; i < table->len; i++) {
        if(category == table->subjects[i].category) {
            count++;
        }
    }
    return count;
}

Table* FindSubjectsByCategory(const Table* table, Category category) {
    size_t count = GetNumberOfSubjectsByCategory(table, category);
    Subject* subjects = new Subject[count];

    size_t index = 0;
    for(size_t i = 0; i < table->len; i++) {
        if(category == table->subjects[i].category) {
            subjects[index++] = table->subjects[i];
        }
    }
    return new Table{count, subjects};
}

size_t GetNumberOfSubjectsByCredits(const Table* table, uint8_t minC, uint8_t maxC) {
    size_t count = 0;
    for(size_t i = 0; i < table->len; i++) {
        if(minC <= table->subjects[i].credits && table->subjects[i].credits <= maxC) {
            count++;
        }
    }
    return count;
}

Table* FindSubjectsByCredits(const Table* table, uint8_t minC, uint8_t maxC) {
    size_t count = GetNumberOfSubjectsByCredits(table, minC, maxC);
    Subject* subjects = new Subject[count];

    size_t index = 0;
    for(size_t i = 0; i < table->len; i++) {
        if(minC <= table->subjects[i].credits && table->subjects[i].credits <= maxC) {
            subjects[index++] = table->subjects[i];
        }
    }
    return new Table{count, subjects};
}

Subject EnterSubjectFromConsole() {
    Subject subject;
    int c;
    cin >> subject.id >> subject.name >> subject.credits >> c >> subject.subjectType;
    subject.category = (Category) c;
    return subject;
}

int main() {

    Table* t = ReadFromFile();

    bool shouldExit = false;

    while(!shouldExit) {
        cout << "<===================================-------------------------------------===================================>" << endl;
        cout << "1 - Add; 2 - Delete; 3 - FindById; 4 - FindByCategory; 5 - FindByCreditRange; 6 - PrintTable; 7 - SaveAndExit" << endl;
        int commandNumber;
        cin >> commandNumber;

        switch (commandNumber) {
            case 1:
            {
                //Subject s = {Category::M, 3, 4, 1, "FP"};
                Subject s = EnterSubjectFromConsole();
                AddSubject(t, s);
                break;
            } 
            case 2:
            {
                //uint16_t id = 3;
                uint16_t id;
                cin >> id;
                DeleteSubject(t, id);
                break;
            }
            case 3:
            {
                //uint16_t id = 1;
                uint16_t id;
                cin >> id;
                Table* table = FindSubjectById(t, id);
                PrintTable(table);

                delete[] table->subjects;
                delete table;
                break;
            }
            case 4:
            {
                //Category c = Category::OKN;
                uint16_t cI;
                cin >> cI;
                Category c = (Category) cI;

                Table* table = FindSubjectsByCategory(t, c);
                PrintTable(table);
                
                delete[] table->subjects;
                delete table;
                break;
            }
            case 5:
            {
                //uint8_t minC = 1, maxC = 5;
                uint8_t minC, maxC;
                cin >> minC >> maxC;

                Table* table = FindSubjectsByCredits(t, minC, maxC);
                PrintTable(table);
                
                delete[] table->subjects;
                delete table;
                break;
            }
            case 6:
            {
                PrintTable(t);
                break;
            }
            case 7:
            {
                WriteIntoFile(t);
                shouldExit = true;
                break;
            }
        }
    }
    
    delete[] t->subjects;
    delete t;
}
