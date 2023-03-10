#include <iostream>
#include <fstream>

const int MAX_PAIRS_COUNT = 25;
const char FILE_NAME[] = "relation.txt";
const char ERROR_MESSAGE[] = "Error";

struct Pair {
	int a, b;
};

struct Relation {
	Pair pairs[MAX_PAIRS_COUNT];
	unsigned int size = 0;
};

void initPair(Pair& pair) {
	std::cin >> pair.a >> pair.b;
}

void readPairFromFile(std::ifstream& src, Pair& pair) {
	src >> pair.a >> pair.b;
}

void writePairToFile(std::ofstream& dest, const Pair& pair) {
	dest << pair.a << " " << pair.b << std::endl;
}

void addPairToRelation(Relation& relation, const Pair& pair) {
	if (relation.size >= MAX_PAIRS_COUNT) {
		std::cout << "Max number of pairs reached\n";
		return;
	}

	relation.pairs[relation.size++] = pair;
}

void writeRelationToFile(const char fileName[], const Relation& relation) {
	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	//Add the relation size on the first row
	file << relation.size << std::endl;
	for (int i = 0; i < relation.size; i++) {
		writePairToFile(file, relation.pairs[i]);
	}

	file.close();
}

void readRelationFromFile(const char fileName[], Relation& relation) {
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << ERROR_MESSAGE << std::endl;
		return;
	}

	file >> relation.size;
	for (int i = 0; i < relation.size; i++) {
		readPairFromFile(file, relation.pairs[i]);
	}

	file.close();
}

void printPair(const Pair& pair) {
	std::cout << "a = " << pair.a << ", b = " << pair.b << std::endl;
}

void printRealtion(const Relation& relation) {
	std::cout << "Pairs:" << std::endl;
	for (int i = 0; i < relation.size; i++) {
		printPair(relation.pairs[i]);
	}
}

int main()
{
	const int RELATION_SIZE = 10;
	Relation myRelation;
	myRelation.size = RELATION_SIZE;

	for (int i = 0; i < RELATION_SIZE; i++) {
		initPair(myRelation.pairs[i]);
	}

	printRealtion(myRelation);
	writeRelationToFile(FILE_NAME, myRelation);

	Relation fileRelation;
	readRelationFromFile(FILE_NAME, fileRelation);
	printRealtion(fileRelation);
}