#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "result.txt";

void writeInFile(int a, int b, int c, std::ofstream& out)
{
	int sum = a + b + c;
	int product = a * b * c;

	out << sum << " " << product;


}

void readFileSumProduct(std::ifstream& in,int& sum,int& product)
{
	
	in >> sum;
	in >> product;
	

}


int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::ofstream out(FILE_NAME, std::ios::out);
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


	int sum =0, product =0, diff;


	readFileSumProduct(in,sum,product);
	in.close();
	diff = sum - product;
	std::cout << diff;

	return 0;

}