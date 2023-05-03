#pragma once
#include "MyString.h"

class Order
{
	MyString restaurantName;
	size_t productsAmount;
    MyString* productsList;

public:
	Order();
	Order(size_t productsAmount);

	Order(const Order& other);
	Order& operator=(const Order& other);

	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;

	const MyString& operator[](size_t index) const;
	MyString& operator[](size_t index);

	~Order();

	const MyString& getRestaurantName() const;
	void setRestaurantName(const char* name);
	size_t getProductsAmount() const;
	void addProduct(const MyString& product);

private:

	void free();
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);

};

