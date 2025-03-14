#include <iostream>
#include <fstream>

constexpr char FILE_NAME[] = "FileWithLInes.txt";

unsigned countLines(std::ifstream& in)
{
	char ch;
	unsigned count = 0;
	while (in.get(ch))
	{
		if (ch == '\n')
			count++;
	}
	if (ch != '\n' && in.eof())
	{
		count++;
	}
	if (!in && !in.eof())
	{
		std::cerr << "Problem reading file for lines\n";
		return 0;
	}
	return count;
}


int main()
{
	std::ifstream in(FILE_NAME,std::ios::in);

	if (!in)
	{
		std::cerr << "Problem with opeining file " << FILE_NAME << "\n";
		return -1;
	}
	std:: cout << countLines(in);



}