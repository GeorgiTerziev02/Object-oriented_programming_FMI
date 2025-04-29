#pragma once
#include "String.h"
#include "Vector.h"


class Order
{
public:
	Order();
	Order(const char* name, size_t count);
	Order(const Order& other);
	Order( Order&& other) noexcept;
	Order& operator=(const Order& other);
	Order& operator=(Order&& other) noexcept;
	~Order() noexcept;


	void addProduct(const String& str);
	unsigned calculateTime();

	const String* getProduct(size_t index) const;
	const char* getName() const noexcept { return this->name.c_str(); }
	size_t getCount() const noexcept { return this->count; }
	size_t getCapacity() const noexcept { return this->capacity; }
	

private:
	void freeDynamic() noexcept;
	void copyDynamic(const Order& other);
	bool setProducts(size_t capacity);
	void resize(size_t capacity);
	void ensureCapacity();



private:
	String name;	
	size_t count;
	size_t capacity;
	String* products;

	static unsigned sum;
	static unsigned prevCount;

};

