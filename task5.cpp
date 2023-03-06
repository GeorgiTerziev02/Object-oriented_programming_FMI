#include <iostream>
#include <fstream>
using namespace std;
const int BUFFER_SIZE = 1024;
void printSourceCode(ifstream& in) {
	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		cout << buffer<<endl;
	}
}
int main()
{
	ifstream in;
	in.open("task5.cpp");
	if (!in.is_open()) {
		return -1;
	}
	printSourceCode(in);
}