#include <iostream>
#include <fstream>



int main()
{
	std::ifstream fileFrom("CountLinesInFile.txt");
	std::ofstream fileTo("Copy.txt");

	if (!fileFrom)
	{
		std::cout << "error file from";
		return - 1;
	}

	if (!fileTo)
	{
		std::cout << "error file to";
		return -1;
	}

	char buffer[1024];

	while (fileFrom)
	{
		 fileFrom.getline(buffer,1024);
		 fileTo << buffer;
	}
	fileFrom.close();
	fileTo.close();

	/* 
	
	while (fileFrom.getline(buffer, 1024)) {
    fileTo << buffer << '\n';

	CORRECTED VERSION OF THE GPT - IT CLAIMS THAT WE COPY ONE EXTRA EMPTY LINE AT THE END 
}*/



}