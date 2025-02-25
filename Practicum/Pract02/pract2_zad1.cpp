#include <iostream>
#include <fstream>


void writeInFile(int a, int b, int c, std::ofstream& out)
{
	int sum = a + b + c;
	int product = a * b * c;

	out << sum << " " << product;


}

void readFileAndPrint(std::ifstream& in)
{
	int sum, product, diff;
	in >> sum;
	in >> product;
	diff = sum - product;
	std::cout << diff;

}


int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::ofstream out("result.txt", std::ios::out);
	if (!out)
	{
		std::cout << "problem with file writing";
		return -1;
	}


	writeInFile(a, b, c, out);
	out.close();


	std::ifstream in("result.txt", std::ios::in);
	if (!in)
	{
		std::cout << "problem with file reading ";
		return -1;
	}




	readFileAndPrint(in);
	in.close();
	return 0;

}