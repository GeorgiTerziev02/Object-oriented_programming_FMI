#include "Order.h"

void Order::free() {

	restaurantName = "";
	productsAmount = 0;
	delete[] productsList;
}

void Order::copyFrom(const Order& other) {

	this->restaurantName = other.restaurantName;
	this->productsAmount = other.productsAmount;
	this->productsList = new MyString[productsAmount];
	for (size_t i = 0; i < productsAmount; i++) {
		this->productsList[i] = other.productsList[i];
	}
}

void Order::moveFrom(Order&& other) {
	this->productsList = other.productsList;
	other.productsList = nullptr;
	this->productsAmount = other.productsAmount;
	this->restaurantName = other.restaurantName;
}

Order::Order(size_t amount): productsAmount(amount) {
	this->restaurantName = "";
	this->productsList = new MyString[amount];
}

Order::Order(): Order(0) {
	//this constructor won't be used for the purpose of this task, because the program isn't using an array of orders
	//otherwise a capacity variable and a resize method and an addProduct method might be needed
}

Order::Order(const Order& other) {
	copyFrom(other);
}

Order& Order::operator=(const Order& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Order::~Order() {
	free();
}

Order::Order(Order&& other) {
	moveFrom(std::move(other));
}

Order& Order::operator=(Order&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

const MyString& Order::getRestaurantName() const {
	return this->restaurantName;
}

void Order::setRestaurantName(const char* name) {
	this->restaurantName = name;
}

size_t Order::getProductsAmount() const {
	return this->productsAmount;
}

void Order::addProduct(const MyString& product) {
	//we can add a capacity variable in order to check if the limit is exceeded
	productsList[productsAmount++] = product;
}

const MyString& Order::operator[](size_t index) const {
	if (index >= productsAmount) {
		throw std::exception("Invalid index!");
	}
	return productsList[index];
}

MyString& Order::operator[](size_t index) {
	if (index >= productsAmount) {
		throw std::exception("Invalid index!");
	}
	return productsList[index];
}