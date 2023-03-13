#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

//task06
void printSourceCode(const char fileName[])
{
	ifstream in(fileName);

	if (!in.is_open())
	{
		cout << "Error";
		return;
	}

	while (!in.eof())
	{
		char buffer[1024];
		in.getline(buffer, 1024);
		cout << buffer << endl;
	}

	in.close();
}

int main6()
{
	ifstream in("Task01.cpp");
	if (!in.is_open())
	{
		cout << "Error";
	}

	printSourceCode("Task01.cpp");

	in.close();

	return 0;
}