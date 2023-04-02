#include "ShoppingCart.h"
#include <iostream>
#include<fstream>
#pragma warning(disable:4996)

void swap(Item& a, Item& b) {
	Item temp = a;
	a = b;
	b = temp;
}


void ShoppingCart::copyFrom(const ShoppingCart& other) {
	this->itemsCount = other.itemsCount;
	for (int i = 0; i < other.itemsCount; i++) {
		this->items[i] = other.items[i];
	}
}
void ShoppingCart::free() {
	delete[] items;
}
void ShoppingCart::resize(int newCapacity) {

	Item* newItems = new Item[newCapacity];
	for (int i = 0; i < itemsCount; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
	capacity = newCapacity;
}
int ShoppingCart::find(const char* nameToFind)const {
	for (int i = 0; i < itemsCount; i++) {
		if (strcmp(items[i].getName(), nameToFind) == 0) {
			return i;
		}
	}
	return -1;
}

ShoppingCart::ShoppingCart() {
	capacity = 2;
	items = new Item[capacity];
	itemsCount = 0;
}

ShoppingCart::ShoppingCart(const ShoppingCart & other) {
	copyFrom(other);
}
ShoppingCart& ShoppingCart::operator=(const ShoppingCart & other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

bool ShoppingCart::addItem(const char* name,bool isAvailable,float price) {
	int newItemIndex = find(name);
	if (newItemIndex != -1) {
		std::cout << "This item already exists." << std::endl;
		return false;
	}
	if (itemsCount == capacity)
		resize(capacity * 2);
	items[itemsCount]=Item(name,isAvailable,price);
	items[itemsCount++].itemCountIterator();
	std::cout << "This item has been added successfully." << std::endl;
	return true;
}
bool ShoppingCart::removeItem(const char* name) {
	int itemForRemovalIndex = find(name);
	if (itemForRemovalIndex != -1){
		items[itemsCount] = items[itemForRemovalIndex];
		itemsCount--;
		std::cout << "This item has been removed successfully." << std::endl;
		return true;
	}
	std::cout << "This item does not exist." << std::endl;
	return false;
}
void ShoppingCart::getItemsCount() const {
	std::cout << "There are " << itemsCount << " items at the moment in the cart." << std::endl;
}
bool ShoppingCart::isEmpty()const {
	if (itemsCount == 0) {
		std::cout << "The cart is empty." << std::endl;
		return true;
	}
	std::cout << "The cart is not empty." << std::endl;
	return false;
}
void ShoppingCart::getPriceOf(const char* name)const {
	int index = find(name);
	if (index == -1) {
		std::cout << "This item does not exist." << std::endl;
	}
	std::cout << name << " price is" << items[index].getPrice() << std::endl;
}
void ShoppingCart::getTotalPrice()const {
	float sum = 0;
	for (int i = 0; i < itemsCount; i++) {
		sum += items[i].getPrice();
	}
	std::cout << "The total price of all items in the cart is " << sum << std::endl;
}
void ShoppingCart::sortByName() {
	for (int i = 0; i < itemsCount - 1; i++) {
		bool hasSwaps = false;
		for (int j = 0; j < itemsCount - i - 1; j++) {
			if (strcmp(items[j].getName(),items[j+1].getName())>0) {
				swap(items[j], items[j + 1]);
				hasSwaps = true;
			}
		}

		if (!hasSwaps) {
			break;
		}
	}
}
bool ShoppingCart::saveToFile(const char* fileName) {
	std::ofstream myFile(fileName);
	for (int i = 0; i < itemsCount; i++) {
		myFile << items[i].getName() << " , " << items[i].getItemCount() << " , " << items[i].getPrice() << std::endl;
	}
	std::cout << "The shopping cart has been save successfully in" << fileName;
	return true;
}

ShoppingCart::~ShoppingCart() {
	free();
}