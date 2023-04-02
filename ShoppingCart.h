#pragma once
#include "Item.h"

class ShoppingCart
{
private:
	int capacity;
	int itemsCount;
	Item* items;

	void copyFrom(const ShoppingCart& other);
	void free();
	void resize(int newCapacity);
	int find(const char* nameToFind)const;
public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);

	bool addItem(const char* name, bool isAvailable, float price);
	bool removeItem(const char* name);
	void getItemsCount() const;
	bool isEmpty()const;
	void getPriceOf(const char* name)const;
	void getTotalPrice()const;
	void sortByName();
	bool saveToFile(const char* fileName);

	~ShoppingCart();
};

