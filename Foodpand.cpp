#include "Foodpand.h"

void Foodpanda::resize(size_t capacity) {
	capacity *= 2;
	Restaurant** temp = new Restaurant * [capacity];
	for (size_t i = 0; i < count; i++) {
		temp[i] = restaurants[i];
	}
	delete[] restaurants;
	restaurants = temp;
}
void Foodpanda::free() {
	for (size_t i = 0; i < count; i++) {
		delete restaurants[i];
	}
	delete[] restaurants;
	count = capacity = 0;
}
void Foodpanda::copyFrom(const Foodpanda& other) {
	capacity = other.capacity;
	count = other.count;
	restaurants = new Restaurant * [capacity];

	for (size_t i = 0; i < count; i++) {
		restaurants[i] = new Restaurant(*(other.restaurants[i]));
	}
}
Foodpanda::Foodpanda(size_t initialCapacity) {
	count = 0;
	capacity = initialCapacity;
	restaurants = new Restaurant * [capacity];
}
Foodpanda::Foodpanda(const Foodpanda& other) {
	copyFrom(other);
}
Foodpanda::Foodpanda(Foodpanda&& other) {
	move(std::move(other));
}
void Foodpanda::move(Foodpanda&& other) {
	count = other.count;
	capacity = other.capacity;
	restaurants = other.restaurants;
	other.restaurants = nullptr;
}
Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Foodpanda& Foodpanda::operator=(Foodpanda&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}
	return *this;
}
Foodpanda::~Foodpanda() {
	free();
}

void Foodpanda::runFoodpanda() {
	
}
void Foodpanda::readOrder() {
	while (true) {
		std::cout << ">";
		MyString restaurant;
		std::cin >> restaurant;
		for (int i = 0; i < count; i++) {
			if (restaurants[i]->getName() == restaurant) {
				std::cout << "The order has been sent";
			}
		}
	}
}
void Foodpanda::addProductToRestaurant(size_t index,const char* data) {
	restaurants[index]->addProduct(data);
}
void Foodpanda::addRestaurant(const Restaurant& newRestaurant) {
	if (count = capacity)
		resize(capacity*2);
	restaurants[count++] = new Restaurant(newRestaurant);
}