#pragma once
#include "Restaurant.h"

class Foodpanda
{
public:
	Foodpanda(size_t capacity);
	Foodpanda(const Foodpanda& other);
	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(const Foodpanda& other);
	Foodpanda& operator=( Foodpanda&& other) noexcept;
	~Foodpanda() noexcept;

	size_t getCount() const noexcept { return this->count; }
	size_t getCapacity() const noexcept { return this->capacity; }

	void ensureCapactiy();
	void addProductToRestaurant(const String& str);
	void addNewRestaurant(const Restaurant& rest);
	void addOrder(const Order& order, const Restaurant& rest); // searches by name 




private:
	void copyDynamic(const Foodpanda& other);
	void freeDynamic() noexcept;
	bool setRestaurants(size_t capacity);
	void resize(size_t capacity);
	int findRestaurant(const String& name);


private:
	Restaurant* restaurants;
	size_t count;
	size_t capacity;

};

