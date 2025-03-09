#include <iostream>
#include <fstream>

struct Pair
{
	int first;
	int second;

};

struct Relation
{

	Pair pairArr[25];
	int size;


};

void writePairToFile(const Pair& pr, std::ofstream& out)
{
	out << pr.first << " " << pr.second << "   ";
}

void writeRelationToFile(const Relation& rel, std::ofstream& out)
{


	out << rel.size << "\n";
	for (size_t i = 0; i < rel.size; i++)
	{
		writePairToFile(rel.pairArr[i], out);
		out << "\n";

	}

	



}

void readPairFromFile(Pair& pr, std::ifstream& in)
{
	in >> pr.first;
	in >> pr.second;
	std::cout << pr.first << " " << pr.second << "\n";
}

void readRelationFromFile(Relation& rel, std::ifstream& in)
{
	in >> rel.size;
	std::cout << rel.size << std::endl;

	for (size_t i = 0; i < rel.size; i++)
	{
		readPairFromFile(rel.pairArr[i], in);

	}
	
	


}

int main()
{

	std::ofstream out("Relation.txt", std::ios::out);
	if (!out)
	{
		std::cout << "error with writing the file";
		return -1;
	}


	Relation pairArrInput;
	pairArrInput.size = 3;
	pairArrInput.pairArr[0] = { 1, 2 };
	pairArrInput.pairArr[1] = { 3, 4 };
	pairArrInput.pairArr[2] = { 5, 6 };

	writeRelationToFile(pairArrInput, out);


	out.close();




	std::ifstream in("Relation.txt", std::ios::in);
	if (!in)
	{
		std::cout << "error with reading the file";
		return -1;
	}
	Relation pairArrOuptput;
	readRelationFromFile(pairArrOuptput, in);
	in.close();

}