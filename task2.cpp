#include<iostream>
using namespace std;
int count(int* arr, char symbol, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > (int)symbol) {
			count++;
		}
	}
	return count;
}
int main() {
	int n;
	cout << "N:";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "element on index" << i << ":";
		cin >> arr[i];
	}
	char symbol;
	cout << "Symbol:";
	cin >> symbol;
	cout << count(arr, symbol, n);
	return 0;
}