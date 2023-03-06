#include <iostream>
#include <fstream>
#include <ctime>

const char* PAIR_FILE = "pair_file.txt";
const char* RELATION_FILE = "relation_file.txt";

const int MAX_PAIRS_IN_A_RELATION = 25;

struct pair{
    int num1;
    int num2;
};

struct relation{
    int arraySize;
    pair pairArray[MAX_PAIRS_IN_A_RELATION];
};

void testFunctions(){
    int pairArraySize = 0;
    int num1 = 0;
    int num2 = 0;
    int randomNum = (int)time(nullptr);
    pair pairToAdd = {};
    pair pairFromFile = {};
    relation relation1 = {};
    relation relationFromFile = {};

    using namespace pairFunctions;
    using namespace relationFunctions;

    std::cin >> pairArraySize;

    pair* pairArray = new pair[pairArraySize];

    for(int i = 0; i < pairArraySize; ++i){

        std::cin >> num1;
        std::cin >> num2;
        initializePair(pairArray[i], num1, num2);
    }

    std::ofstream pairOut(PAIR_FILE);
    std::ofstream relationOut(RELATION_FILE);

    if(!pairOut.is_open() || !relationOut.is_open()){
        std::cerr << "File cannot be opened";
        return;
    }

    initializePair(pairToAdd, randomNum, randomNum);

    writePairToFile(pairOut, pairToAdd);

    initializeRelation(relation1, pairArraySize, pairArray);

    addPairToRelation(relation1, pairToAdd);

    writeRelationToFile(relationOut, relation1);

    pairOut.close();
    relationOut.close();

    std::ifstream pairIn(PAIR_FILE);
    std::ifstream relationIn(RELATION_FILE);

    pairFromFile = *readPairFromFile(pairIn);

    printPair(pairFromFile);

    relationFromFile = *readRelationFromFile(relationIn);

    printRelation(relationFromFile);

    pairIn.close();
    relationIn.close();

    delete[] readPairFromFile(pairIn);
    delete[] readRelationFromFile(relationIn);
    delete[] pairArray;
}
