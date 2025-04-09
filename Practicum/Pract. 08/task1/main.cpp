#include <iostream>
#include "StringVector.h"
using namespace std;

int main() {
    StringVector sv;

    try {
        sv.push_back("apple");
        sv.push_back("banana");
        sv.push_back("cherry");

        cout << "Size: " << sv.size() << endl;
        cout << "At(1): " << sv.at(1) << endl;

        sv.insert(1, "orange");
        cout << "After insert at 1:\n";
        for (unsigned i = 0; i < sv.size(); i++)
            cout << sv.at(i) << " ";
        cout << endl;

        sv.erase(2);
        cout << "After erase at 2:\n";
        for (unsigned i = 0; i < sv.size(); i++)
            cout << sv.at(i) << " ";
        cout << endl;

        sv.pop_back();
        cout << "After pop_back:\n";
        for (unsigned i = 0; i < sv.size(); i++)
            cout << sv.at(i) << " ";
        cout << endl;

        sv.clear();
        cout << "After clear, is empty: " << (sv.empty() ? "yes" : "no") << endl;

    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
