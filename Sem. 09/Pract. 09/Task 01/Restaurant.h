#pragma once
#include "MyString.h"
#include "Order.h"

const unsigned short MAX_NAME_LENGTH = 25;

class Restaurant
{
	MyString name;
	MyString* products;
	size_t productsCapacity;
	size_t productsAmount;

public:
	Restaurant();
	Restaurant(size_t capacity, const char* name);

	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);

	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;

	~Restaurant();

	const MyString& getName() const;
	void setName(const char* name);

	void addProduct(const MyString& product);
	void receiveOrder(const Order& order) const;

private:

	void free();
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void resize(size_t newCapacity);
	void copyProductsData(size_t capacity, MyString* products);
	void setCapacity(size_t capacity);
	bool containsProduct(const MyString& product) const;
	
};

