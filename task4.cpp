#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SIZE = 25;
const int BUFFER_SIZE = 1024;
struct Pair {
	int x1, x2;
};
struct Relation {
	Pair relationSet[MAX_SIZE];
};
void createPair(Pair* pair,const int& x1,const int& x2) {
	pair->x1 = x1;
	pair->x2 = x2;
}
void addPairToRelation(Pair& pair, Relation (&set)[MAX_SIZE],int& i) {
	set->relationSet[i] = pair;
}
Pair* readPairFromFile(ifstream& in) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		Pair* pair = new Pair;
		createPair(pair, (int)buffer[0]-48, (int)buffer[2]-48);
		return pair;
}
void  readRelationFromFile(ifstream& in,Relation (&set)[MAX_SIZE],int& i) {
	i = 0;
	in.open("relation.txt");
	if (!in.is_open()) {
		return ;
	}
	while (!in.eof()) {
		Pair* pair = readPairFromFile(in);
		addPairToRelation(*pair, set,i);
		i++;
	}
}
void writePairToFile(ofstream& out, Pair& pair ) {
	out << pair.x1 << "," << pair.x2 << endl;
}
void writeRelationToFile(ofstream& out, Relation* set,int i) {
	for (int j = 0; j < i; j++) {
		writePairToFile(out,set->relationSet[j]);
	}
}
int main() {
	ifstream in;
	Relation set1[MAX_SIZE], set2[MAX_SIZE] = { {1,2},{3,5},{-5,6} };
	int i = 0;
	readRelationFromFile(in, set1, i);
	for (int j = 0; j < i; j++) {
		cout << set1->relationSet[j].x1<<","<<set1->relationSet[j].x2 << endl;
	}
	in.close();
	ofstream out;
	out.open("relation.txt");
	writeRelationToFile(out, set2, 3);
	
}