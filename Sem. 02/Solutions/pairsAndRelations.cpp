#include <iostream>

const int MAX_PAIRS_IN_A_RELATION = 25;

struct pair{
    int num1;
    int num2;
};

struct relation{
    int arraySize;
    pair pairArray[MAX_PAIRS_IN_A_RELATION];
};

namespace pairFunctions{

    pair* createPair(){
        pair* newPair = new pair();

        return newPair;
    }

    void initializePair(pair& pair, int num1, int num2){

        pair.num1 = num1;
        pair.num2 = num2;
    }

    void writePairToFile(std::ofstream& out, const pair& pair){

        out << pair.num1 << " " << pair.num2 << '\n';
    }

    pair* readPairFromFile(std::ifstream& in){
        pair* pair = createPair();

        in >> (*pair).num1 >> (*pair).num2;

        return pair;
    }

    void printPair(const pair& pair){

        std::cout << pair.num1 << " " << pair.num2 << std::endl;
    }
}

namespace relationFunctions{

    relation* createRelation(){
        relation* newRelation = new relation();

        return newRelation;
    }

    void initializeRelation(relation& relation, int arraySize, const pair* pairArray){

        if(pairArray == nullptr){
            return;
        }

        relation.arraySize = arraySize;

        for(int i = 0; i < arraySize; ++i){
            relation.pairArray[i] = pairArray[i];
        }
    }

    void addPairToRelation(relation& relation, const pair& pair){

        if(relation.arraySize == 25){
            std::cerr << "Exceeding array size";
            return;
        }

        relation.pairArray[relation.arraySize] = pair;
        relation.arraySize++;
    }

    void writeRelationToFile(std::ofstream& out, const relation& relation){

        for(int i = 0; i < relation.arraySize; ++i){
            out << relation.pairArray[i].num1 << " " << relation.pairArray[i].num2 << '\n';
        }
    }

    relation* readRelationFromFile(std::ifstream& in){
        relation* relation = createRelation();
        (*relation).arraySize = -1;

        for(int i = 0; !in.eof(); ++i){
            (*relation).arraySize++;
            in >> (*relation).pairArray[i].num1 >> (*relation).pairArray[i].num2;
        }

        return relation;
    }

    void printRelation(const relation& relation){

        std::cout << relation.arraySize << std::endl;

        for(int i = 0; i < relation.arraySize; ++i){
            std::cout << relation.pairArray[i].num1 << " " << relation.pairArray[i].num2 << std::endl;
        }
    }

}
