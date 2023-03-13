#include <iostream>
#include <fstream>

const size_t MAX_ADDRESS_LENGTH = 26;
const char* FILE_PATH = "orders.bin";

struct PizzaOrder
{
	double price;
	char address[MAX_ADDRESS_LENGTH];
};

size_t getFileSize(std::ifstream& in)
{
	size_t currentPos = in.tellg();
	in.seekg(0, std::ios::end);
	size_t fileSize = in.tellg();
	in.seekg(currentPos);
	return fileSize;
}

size_t strLength(const char* str)
{
	size_t length = 0;

	while (*str != 0)
	{
		str++;
		length++;
	}

	return length;
}

int strCompare(const char* str1, const char* str2)
{
	size_t str1Len = strLength(str1);
	size_t str2Len = strLength(str2);

	size_t lenToUse = str1Len >= str2Len ? str1Len : str2Len;

	for (size_t i = 0; i < lenToUse; i++)
	{
		if (str1[i] > str2[i])
			return -1;

		if (str1[i] < str2[i])
			return 1;
	}

	return 0;
}

void strCopy(char* direction, const char* toCopy)
{
	size_t toCopyLen = strLength(toCopy);

	for (size_t i = 0; i < toCopyLen; i++)
		direction[i] = toCopy[i];

	direction[toCopyLen] = '\0';
}

void swapOrders(PizzaOrder& order1, PizzaOrder& order2)
{
	PizzaOrder temp = order1;
	order1 = order2;
	order2 = temp;
}

void sortOrders(PizzaOrder* orders, const size_t ordersSize)
{
	for (size_t i = 0; i < ordersSize; i++)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < ordersSize; j++)
			if (strCompare(orders[minIndex].address, orders[j].address) == -1)
				minIndex = j;

		swapOrders(orders[minIndex], orders[i]);
	}
}

void getOrdersFromBinary(PizzaOrder*& orders, size_t& ordersSize)
{
	std::ifstream in(FILE_PATH, std::ios::binary);

	if (!in.is_open())
	{
		std::cerr << "File couldn't open";
		exit(0);
	}

	size_t fileSize = getFileSize(in);
	ordersSize = fileSize / sizeof(PizzaOrder);

	orders = new PizzaOrder[ordersSize + 1];

	in.read((char*)orders, fileSize);

	in.close();
}

void saveOrdersInBinary(PizzaOrder* orders, size_t& ordersSize, PizzaOrder& orderToSave)
{
	getOrdersFromBinary(orders, ordersSize);

	std::ofstream out(FILE_PATH, std::ios::trunc | std::ios::binary);

	if (!out.is_open())
	{
		std::cerr << "File couldn't open";
		exit(0);
	}

	orders[ordersSize].price = orderToSave.price;
	strCopy(orders[ordersSize].address, orderToSave.address);
	ordersSize++;

	sortOrders(orders, ordersSize);

	out.write((const char*)orders, ordersSize * sizeof(PizzaOrder));
}

void printOrders(PizzaOrder* orders, size_t& ordersSize)
{
	getOrdersFromBinary(orders, ordersSize);
	std::cout << "List:\n";
	for (size_t i = 0; i < ordersSize; i++)
		std::cout << " " << orders[i].price << " " << orders[i].address << std::endl;
}

int main()
{
	PizzaOrder* orders = nullptr;
	PizzaOrder currentOrder;
	size_t ordersSize = 0;

	int userChoice;

	while (true)
	{
		std::cout << "Press 0 to save\nPress 1 to print orders\nPress 2 to exit:\nButton: ";
		std::cin >> userChoice;

		switch (userChoice)
		{
		case 0:
			std::cout << "Price: ";
			std::cin >> currentOrder.price;
			std::cout << "Address: ";
			std::cin >> currentOrder.address;

			saveOrdersInBinary(orders, ordersSize, currentOrder);
			break;
		case 1:
			printOrders(orders, ordersSize);
			break;
		case 2:
			return 0;
		}
	}

	return 0;
}