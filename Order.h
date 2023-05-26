#pragma once
#include"MyString.h"
#include "VectorRestaurant.h"
struct Order
{
	MyString restaurant;
	VectorOfStrings products;
	size_t productsCount;
};

