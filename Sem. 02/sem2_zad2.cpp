#include <iostream>
#include <fstream>


const char FILE_NAME[] = "CountLinesInFile.txt";
int main()
{
	std::ifstream file(FILE_NAME);

	if (!file)
	{
		std::cout << "error" << std::endl;
		return -1;

	}
	char buffer[1024];
	int count = 0;
	while (file.getline(buffer,1024))
	{
		count++;
	}
	std::cout << count;

}





