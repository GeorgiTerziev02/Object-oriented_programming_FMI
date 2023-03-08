#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

const char* FILE_NAME = "result.dat";
const char* ERROR_MSG = "Error!";
const size_t SIZE = 6;

struct Delivery 
{
	double price;
	char address[25];
};

size_t getFileSize(ifstream& f)
{
	size_t currPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();
	f.seekg(currPos, ios::beg);

	return size;
}

void readFromFile(Delivery*& ptr, size_t& deliveriesCount, ifstream& f)
{
	size_t sizeOfFile = getFileSize(f);
	deliveriesCount = sizeOfFile / sizeof(Delivery);
	ptr = new Delivery[deliveriesCount];
	f.read((char*)ptr, sizeOfFile);
}

void writeToFile(const Delivery* deliveries, size_t deliveriesCount, ofstream& f)
{
	f.write((const char*)deliveries, deliveriesCount * sizeof(Delivery));
}

int strCmp(const char* str1, const char* str2)
{
	while (*str1 && (*str1 == *str2))// compares two strings character by character
	{
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2; //ASCII difference
}

void selectionSort(Delivery* delivery)
{
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		int minIndex = i;

		for (size_t j = i + 1; j < SIZE; j++)
		{
			if (strCmp(delivery[j].address, delivery[minIndex].address) < 0)
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(delivery[minIndex], delivery[i]);
		}
	}
}

int main()
{
	Delivery orders[SIZE];
	orders[0] = { 5.40, "Westfall Avenue 4336" };
	orders[1] = { 20.9,"Rodney Street 4163" };
	orders[2] = { 16.80, "Penn Street 4464" };
	orders[3] = { 36.15, "Elk Street 2620" };
	orders[4] = { 25.85, "Elk Avenue 2564" };
	orders[5] = { 42.22, "Austin Avenue 1973" };

	ifstream in(FILE_NAME,ios::in | ios::binary);
	ofstream out(FILE_NAME, ios::out | ios::binary);

	if (!in.is_open() || !out.is_open())
	{
		cout << ERROR_MSG << endl;
		return -1;
	}

	writeToFile(orders,  sizeof(orders) / sizeof(Delivery), out);
	out.close();

    Delivery* arr;
	size_t count = 0;
	readFromFile(arr, count, in);
	selectionSort(arr);

	for (size_t i = 0; i < count; i++)
	{
		cout << "price: " << arr[i].price  << "   " << "Address: " << arr[i].address << endl;
	}

	in.close();
}