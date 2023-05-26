#pragma once
#include "Restaurant.h"
class Foodpanda
{
	Restaurant** restaurants;
	size_t count = 0;
	size_t capacity;

	void resize(size_t capacity);
	void free();
	void move(Foodpanda&& other);
	void copyFrom(const Foodpanda& other);
private:
	Foodpanda(size_t initialCapacity);
	Foodpanda(const Foodpanda& other);
	Foodpanda(Foodpanda&& other);
	Foodpanda& operator=(const Foodpanda& other);
	Foodpanda& operator=(Foodpanda&& other);
	~Foodpanda();

	void runFoodpanda();
	void readOrder();
	void addProductToRestaurant(size_t index,const char* data);
	void addRestaurant(const Restaurant& newRestaurant);

};

