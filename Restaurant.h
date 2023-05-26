#pragma once
#include "MyString.h"
#include "VectorRestaurant.h"
#include "Order.h"
class Restaurant
{
	MyString name;
	VectorOfStrings products;
	Order order;
	bool isThereAnOrder = false;


public:
	Restaurant(size_t productsCount);
	void addProduct(const char* product);
	int receiveOrder(const Order& order);
	const MyString& getName()const;
};

