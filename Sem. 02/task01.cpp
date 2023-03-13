#include <iostream>
#include <fstream>
#include "Source.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;


const char FILE_NAME[] = "result.txt";

//task1

void printDifference()
{
	ifstream in(FILE_NAME);

	if (!in.is_open())
	{
		cout << "Error!" << endl;
	}

	int fileSum, fileProduct;
	in >> fileSum >> fileProduct;
	in.close();

	int difference = fileSum - fileProduct;
	cout << difference << endl;
}

void writeToFile(int& sum, int& product)
{
	ofstream out(FILE_NAME);

	if (!out.is_open())
	{
		cout << "Error!" << endl;
	}

	out << sum << " " << product << endl;
	out.close();
}

int main1()
{
	int n, m, s;
	cin >> n >> m >> s;

	int sum = m + n + s;
	int product = m * n * s;

	writeToFile(sum, product);

	printDifference();

	return 0;
}