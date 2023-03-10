#include<iostream>
#include<fstream>
using namespace std;

const int n = 2;
const char fileName[10] = "order.dat";

struct Order {
	char address[25];
	double price;
};

size_t getFileSize(ifstream& in) {
	size_t currentPos = in.tellg();
	in.seekg(0, ios::end);
	size_t size = in.tellg();

	in.seekg(currentPos);
	return size;
}

void writeToFile(ofstream& out,Order* order,int num) {
	if (!out.is_open()) {
		return;
	}
	out.write((const char*)&order, sizeof(order) * num);
}

void readFromFile(ifstream& in,Order* order,int num) {
	if (!in.is_open()) {
		return;
	}
	in.read((char*)&order, sizeof(order) * num);
}

void swap(Order& a, Order& b) {
	Order temp = a;
	a = b;
	b = temp;
}

int strCmp(const char* arr1,const  char* arr2)
{
	for (int i = 0; ; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return arr1[i] < arr2[i] ? -1 : 1;
		}

		if (arr1[i] == '\0')
		{
			return 0;
		}
	}
}

void selectionSort(Order* orders, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < length; j++) {
			if (strCmp(orders[i].address,orders[minIndex].address)==-1) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(orders[i], orders[minIndex]);
		}
	}
}

int main() {
	Order orders[2] = { {"ac",5.25}, {"ab",10.25} };
	
	ofstream out(fileName, ios::binary);
	writeToFile(out,orders,n);
	out.close();
	
	Order ordersTwo[2];
	
	ifstream in(fileName, ios::binary);
	if (!in.is_open()) {
		return -1;
	}
	readFromFile(in, ordersTwo, n);
	
	cout << ordersTwo[0].address << " " << ordersTwo[0].price << endl;
	cout << ordersTwo[1].address << " " << ordersTwo[1].price << endl;
	
	in.close();

	selectionSort(ordersTwo, n);
	
	ofstream writeSorted(fileName, ios::binary | ios::trunc);
	writeToFile(out, ordersTwo, n);
	writeSorted.close();

	ifstream readSorted(fileName, ios::binary);


	readFromFile(in, ordersTwo, n);
	
	readSorted.close();

	cout << ordersTwo[0].address << " " << ordersTwo[0].price << endl;
	cout << ordersTwo[1].address << " " << ordersTwo[1].price << endl;
}