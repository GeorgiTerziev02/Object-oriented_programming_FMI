#include "Foodpanda.h"

void Foodpanda::free() {
	delete[] restaurants;
	restaurantsCapacity = 0;
	restaurantsAmount = 0;
}

void Foodpanda::copyFrom(const Foodpanda& other) {

	this->restaurantsCapacity = other.restaurantsCapacity;
	this->restaurantsAmount = other.restaurantsAmount;
	this->restaurants = new Restaurant[restaurantsCapacity];
	for (size_t i = 0; i < restaurantsAmount; i++) {
		this->restaurants[i] = other.restaurants[i];
	}
}

void Foodpanda::moveFrom(Foodpanda&& other) {

	this->restaurantsCapacity = other.restaurantsCapacity;
	this->restaurantsAmount = other.restaurantsAmount;
	this->restaurants = other.restaurants;
	other.restaurants = nullptr;
}

Foodpanda::Foodpanda(): restaurantsCapacity(0), restaurantsAmount(0) {
	restaurants = nullptr;
}

Foodpanda::Foodpanda(size_t capacity): restaurantsCapacity(capacity), restaurantsAmount(0) {
	restaurants = new Restaurant[capacity];
}

Foodpanda::Foodpanda(const Foodpanda& other) {
	copyFrom(other);
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Foodpanda::~Foodpanda() {
	free();
}

Foodpanda::Foodpanda(Foodpanda&& other) {
	moveFrom(std::move(other));
}

Foodpanda& Foodpanda::operator=(Foodpanda&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Foodpanda::addRestaurant(const Restaurant& restaurant) {

	if (restaurantsAmount == restaurantsCapacity) {
		resize(restaurantsCapacity * 2);
	}
	this->restaurants[restaurantsAmount++] = restaurant;
}

void Foodpanda::sendOrderToRestaurant(const Order& order) const {

	size_t restaurantIndex = findRestaurantIndexByName(order.getRestaurantName());
	if (restaurantIndex > restaurantsAmount) {
		throw std::exception("Invalid order! No such restaurant found!");
	}
	restaurants[restaurantIndex].receiveOrder(order);
}

size_t Foodpanda::findRestaurantIndexByName(const MyString& name) const {

	for (size_t i = 0; i < restaurantsAmount; i++) {
		if (restaurants[i].getName() == name.c_str()) {
			return i;
		}
	}
	return restaurantsAmount + 1;
}

void Foodpanda::manageOrders() {
	//Foodpanda and restaurant instances should be created in the source.cpp file
	//Only orders are created from the console
	while (true) {

		char input[1024];
		std::cin.getline(input, 200);
		
		if (strcmp(input, "addOrder") == 0) {

			char restaurantName[100];
			std::cin.getline(restaurantName, 100);

			size_t productsAmount;
			std::cin >> productsAmount;

			Order order(productsAmount);
			order.setRestaurantName(restaurantName);

			for (size_t i = 0; i < productsAmount; i++) {

				char productName[50];
				std::cin.getline(productName, 50);
				MyString product = productName;
				order.addProduct(product);

			}

			sendOrderToRestaurant(order);
		}
		else if (strcmp(input, "exit")) {
			break;
		}
		else {
			std::cout << "Invalid command!";
		}
	}
}