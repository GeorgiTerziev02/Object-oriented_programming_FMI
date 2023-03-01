#include <iostream>

void newLineError() {
	int a;
	std::cin >> a; // 5abc vs 5 abc

	char arr[10];
	//std::cin >> arr;
	std::cin.ignore();
	std::cin.getline(arr, 10);

	std::cout << a << " " << arr;
}

void infiniteLoop() {
	char c;
	std::cin.putback('a');
	while (std::cin >> c) {
		std::cout << c;
		std::cin.putback(c);
	}
}

void getExample() {
	char c;
	std::cin.putback('a');
	std::cin.get(c);
	std::cout << c;
}

void readExample() {
	char c;
	std::cin.putback('a').putback('b');
	char info[3] = { '\0' };
	std::cin.read(info, 2);
	std::cout << info;
}