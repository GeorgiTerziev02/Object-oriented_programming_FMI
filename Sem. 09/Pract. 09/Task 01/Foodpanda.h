#pragma once
#include "Restaurant.h"
#include "Order.h"

class Foodpanda
{
	Restaurant* restaurants;
	size_t restaurantsCapacity;
	size_t restaurantsAmount;

public:
	Foodpanda();
	Foodpanda(size_t capacity);

	Foodpanda(const Foodpanda& other);
	Foodpanda& operator=(const Foodpanda& other);

	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(Foodpanda&& other) noexcept;

	~Foodpanda();

	void addRestaurant(const Restaurant& restaurant);
	void sendOrderToRestaurant(const Order& order) const;
	void manageOrders();

private:
	void free();
	void copyFrom(const Foodpanda& other);
	void moveFrom(Foodpanda&& other);
	void resize(size_t newCapacity);

	size_t findRestaurantIndexByName(const MyString& name) const;

};

