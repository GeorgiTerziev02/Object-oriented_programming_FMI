#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

//task04
const char FILE_NAME[] = "realtions.txt";
const int MAX_PAIR_SIZE = 25;
const char INVALID_FILE_MSG[] = "Error!";

struct Pair
{
    int x;
    int y;
};

struct Relation
{
    Pair pairs[MAX_PAIR_SIZE];
    int size;
};

Pair CreatePair(int first, int second)
{
    Pair p;
    p.x = first;
    p.y = second;
    return p;
}

void initPair(Pair& p, const int first, const int second)
{
    p.x = first;
    p.y = second;
}

void readPairFromFile(ifstream& in, Pair& p)
{
    in >> p.x >> p.y;
}

void writePairToFile(ofstream& out, const Pair& p)
{
    out << p.x << " " << p.y << endl;
}

void addPairToRelation(Relation& r, const Pair& p)
{
    if (r.size < MAX_PAIR_SIZE)
    {
        r.pairs[r.size++] = p;
    }
}

void writeRelationToFile(const Relation& r, const char* filename)
{
    ofstream out(filename);
    if (out.is_open())
    {
        out << r.size << endl;
        for (int i = 0; i < r.size; i++)
        {
            writePairToFile(out, r.pairs[i]);
        }
        out.close();
    }
    else
    {
        cout << INVALID_FILE_MSG << filename << endl;
    }
}

void readRelationFromFile(Relation& r, const char* filename)
{
    ifstream in(filename);
    if (in.is_open())
    {
        in >> r.size;
        for (int i = 0; i < r.size; i++)
        {
            readPairFromFile(in, r.pairs[i]);
        }
        in.close();
    }
    else
    {
        cout << INVALID_FILE_MSG << endl;
    }
}

int main4()
{
    Relation r;
    r.size = 0;
    addPairToRelation(r, CreatePair(1, 2));
    addPairToRelation(r, CreatePair(2, 3));
    addPairToRelation(r, CreatePair(3, 4));

    writeRelationToFile(r, FILE_NAME);

    Relation r2;
    readRelationFromFile(r2, FILE_NAME);

    for (int i = 0; i < r2.size; i++)
    {
        cout << r2.pairs[i].x << " " << r2.pairs[i].y << endl;
    }

    return 0;
}