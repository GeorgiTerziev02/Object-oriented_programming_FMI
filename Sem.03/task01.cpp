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
const char* OUTPUT_FILE_NAME = "output.txt";
const size_t ADDRESS_SIZE = 25;

struct Delivery 
{
	double price;
	char address[ADDRESS_SIZE + 1];
};

int strCmp(const char* str1, const char* str2)
{
	while (*str1 && (*str1 == *str2))// compares two strings character by character
	{
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2; //ASCII difference
}

size_t getFileSize(ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos, ios::beg);

	return size;
}

void readFromFile(Delivery*& ptr, size_t& deliveriesCount, ifstream& ifs)
{
	size_t sizeOfFile = getFileSize(ifs);
	deliveriesCount = sizeOfFile / sizeof(Delivery);
	ptr = new Delivery[deliveriesCount];
	ifs.read((char*)ptr, sizeOfFile);
}

void writeToFile(const Delivery* deliveries, size_t deliveriesCount, ofstream& ofs)
{
	ofs.write((const char*)deliveries, deliveriesCount * sizeof(Delivery));
}

void printDeliveries(const Delivery* arr, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		cout << "Price: " << arr[i].price << "   " << "Address: " << arr[i].address << endl;
	}
}

void saveDeliveriesToCVS(ofstream& out, const Delivery* deliveries, size_t deliveriesCount)
{
	out << "Price, Address" << endl;
	for (size_t i = 0; i < deliveriesCount; i++)
	{
		out << deliveries[i].price << ", " << deliveries[i].address << endl;
	}
}

void selectionSort(Delivery* delivery)
{
	for (size_t i = 0; i < SIZE - 1; i++)
	{
		size_t minIndex = i;

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

	Delivery newDelivery = { 12.32, "Totion Street 4561" };

	Delivery* arr;
	size_t count = 0;

	{
		ofstream out(FILE_NAME, ios::out | ios::binary);

		if (!out.is_open())
		{
			cout << ERROR_MSG << endl;
			return -1;
		}

		writeToFile(orders, sizeof(orders) / sizeof(Delivery), out);

		out.close();
	}

	{
		ifstream in(FILE_NAME, ios::in | ios::binary);
		
		if (!in.is_open())
		{
			cout << ERROR_MSG << endl;
			return -1;
		}

		readFromFile(arr, count, in);

		in.close();
	}

	{
		ofstream output(OUTPUT_FILE_NAME);

		if (!output.is_open())
		{
			cout << ERROR_MSG << endl;
			return -1;
		}

		selectionSort(arr);

		printDeliveries(arr, count);

		saveDeliveriesToCVS(output, orders, count);

		output.close();
	}
    
	delete[] arr;
	
}