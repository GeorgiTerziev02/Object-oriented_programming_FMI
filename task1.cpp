#include<iostream>
#include<fstream>
using namespace std;
struct Order {
	char address[25];
	double price;
};
size_t getFileSize(ifstream& f) {
	size_t currentPos = f.tellg();
	f.seekg(0, ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;
}
void writeOneItemTofile(ofstream& out,Order* order) {
	out.write((const char*)&order->address, sizeof(order->address));
	out.write((const char*)&order->price, sizeof(order->price));
}
void writeToFile(ofstream& out,Order* order,int num) {
	for (int i = 0; i < num; i++) {
		writeOneItemTofile(out, &order[i]);
	}
}
void readOneItemFromFile(ifstream& in, Order* order) {
	in.read((char*)&order->address, sizeof(order->address));
	in.read((char*)&order->price, sizeof(order->price));
}
void readFromFile(ifstream& in,Order* order,int num) {
	for (int i = 0; i < num; i++) {
		readOneItemFromFile(in, &order[i]);
	}
}
void swap(Order& a, Order& b) {
	Order temp = a;
	a = b;
	b = temp;
}
void selectionSort(Order* order, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < length; j++) {
			if (order[minIndex].address < order[j].address) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(order[i], order[minIndex]);
		}
	}
}
int main() {
	int n = 2;
	Order orders[2] = { {"ac",5.25}, {"ab",10.25} };
	
	ofstream out("order.dat", ios::binary);
	writeToFile(out,orders,n);
	out.close();
	
	Order ordersTwo[2];
	
	ifstream in("order.dat", ios::binary);
	if (!in.is_open()) {
		return -1;
	}
	readFromFile(in, ordersTwo, n);
	
	cout << ordersTwo[0].address << " " << ordersTwo[0].price << endl;
	cout << ordersTwo[1].address << " " << ordersTwo[1].price << endl;
	
	in.close();

	selectionSort(ordersTwo, 2);
	
	ofstream writeSorted("order.dat", ios::binary);
	writeToFile(out, ordersTwo, n);
	writeSorted.close();

	ifstream readSorted("order.dat", ios::binary);


	readFromFile(in, ordersTwo, n);

	cout << ordersTwo[0].address << " " << ordersTwo[0].price << endl;
	cout << ordersTwo[1].address << " " << ordersTwo[1].price << endl;
	readSorted.close();
}