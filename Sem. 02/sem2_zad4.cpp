#include <iostream>
#include<fstream>

void bubbleSort(int array[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}
		}
	}
}


int main()
{


	std::ifstream file1("file1.txt", std::ios::in);
	std::ifstream file2("file2.txt",std::ios::in);
	std::ofstream file3("file3.txt", std::ios::out);
	

	if (!file1 || !file2)
	{
		std::cout << "error opening file 1 or 2";
		return -1;
	}

	if (!file3)
	{
		std::cout << "error opening 3";
		return -2;
	}



	int count = 0;
	int num;
	while (file1>>num)
	{
		count++;
	}
	while (file2>>num)
	{
		count++;
	}
	int* arr = new int[count];

	file1.clear();
	file1.seekg(0, std::ios::beg);
	int index = 0;


	while (file1>>num)
	{
		arr[index] = num;
		index++;
	}

	file2.clear();
	file2.seekg(0, std::ios::beg);


	while (file2 >> num)
	{
		arr[index] = num;
		index++;
	}



	bubbleSort(arr, count);
	for (size_t i = 0; i < count; i++)
	{
		file3 << arr[i] << " ";
	}

	delete[] arr;
	file1.close();
	file2.close();
	file3.close();
	





}