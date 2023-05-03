#include "Restaurant.h"

void Restaurant::copyProductsData(size_t capacity, MyString* products) {
	products = new MyString[capacity];
	for (size_t i = 0; i < productsAmount; i++) {
		this->products[i] = products[i];
	}
}

void Restaurant::free() {

	productsCapacity = productsAmount = 0;
	this->name = "";
	delete[] products;
}

void Restaurant::copyFrom(const Restaurant& other) {

	this->name = other.name;
	this->productsAmount = other.productsAmount;
	setCapacity(other.productsCapacity);
	copyProductsData(other.productsCapacity, other.products);
}

void Restaurant::setCapacity(size_t capacity) {
	if (capacity <= 0) {
		throw std::exception("Invalid capacity!");
	}
	this->productsCapacity = capacity;
}

void Restaurant::resize(size_t newCapacity) {
	
	MyString* temp = products;
	products = new MyString[newCapacity];

	for (size_t i = 0; i < productsAmount; i++) {
		products[i] = temp[i];
	}
	setCapacity(newCapacity);
	delete[] temp;
}

void Restaurant::moveFrom(Restaurant&& other) {
	this->name = other.name;
	this->productsAmount = other.productsAmount;
	this->products = other.products;
	other.products = nullptr;
	setCapacity(other.productsCapacity);
}

Restaurant::Restaurant(size_t capacity, const char* name) {
	setCapacity(capacity);
	this->productsAmount = 0;
	this->products = new MyString[capacity];
	setName(name);
}

Restaurant::Restaurant(): productsCapacity(0), productsAmount(0) {
	this->products = nullptr;
	this->name = "";
}

Restaurant::Restaurant(const Restaurant& other) {
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::Restaurant(Restaurant&& other) {
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Restaurant::~Restaurant() {
	free();
}

const MyString& Restaurant::getName() const {
	return this->name;
}

void Restaurant::setName(const char* name) {
	if (strlen(name) > MAX_NAME_LENGTH) {
		throw std::exception("Restaurant name is above the length limit!");
	}
	this->name = name;
}

void Restaurant::addProduct(const MyString& product) {

	if (productsAmount == productsCapacity) {
		resize(productsCapacity * 2);
	}
	products[productsAmount++] = product;
}

bool Restaurant::containsProduct(const MyString& product) const {

	for (size_t i = 0; i < productsAmount; i++) {
		if (products[i] == product) {
			return true;
		}
	}
	return false;
}

void Restaurant::receiveOrder(const Order& order) const {

	const size_t orderProductsAmount = order.getProductsAmount();

	for (size_t i = 0; i < orderProductsAmount; i++) {
		if (!containsProduct(order[i])) {
			throw std::exception("Restaurant doesn't contain a product specified in the order!");
		}
	}

	std::cout << "Order successfully received! Expect the delivery in " 
		<< order.getProductsAmount() * 5 << " minutes." 
		<< std::endl;
}