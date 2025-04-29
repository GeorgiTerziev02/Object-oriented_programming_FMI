#pragma once
#include "Order.h"

const unsigned NAME_MAX_LENGTH = 25;

class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* name);
	Restaurant(const Restaurant& other);
	Restaurant( Restaurant&& other) noexcept;
	Restaurant& operator=(const Restaurant& other);
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant() noexcept;
	

	const char* getName() const noexcept { return this->name; }
	size_t getCount() const  noexcept { return this->count; }
	size_t getCapacity() const noexcept { return this->capacity; }


	void ensureCapacity();
	void addProduct(const String& product); 
	void receiveOrder(const Order& order); // throws




private:
	void copyDynamic(const Restaurant& other);
	void freeDynamic() noexcept	;
	bool setProducts(size_t capacity);
	bool setName(const char* name);
	void resize(size_t newCapacity);


private:
	char name[NAME_MAX_LENGTH + 1]; // can we make it with String in some way??
	String* products;
	size_t count;
	size_t capacity;
};

