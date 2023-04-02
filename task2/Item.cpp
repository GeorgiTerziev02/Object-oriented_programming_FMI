#include "Item.h"
#include<iostream>
#pragma warning (disable:4996)

void Item::copyFrom(const Item& other) {
	setName(other.name);
	setAvailability(other.availability);
	setPrice(other.price);
}
void Item::free() {
	delete[]name;
	availability = false;
	price = 0;
}

Item::Item() {
	setAvailability(false);
	setPrice(0.0);
	setName("");
}
Item::Item(const Item& other) {
	copyFrom(other);
}

Item::Item(const char* name, bool availability, float price) {
	setName(name);
	setAvailability(availability);
	setPrice(price);
}

Item& Item::operator=(const Item& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void Item::itemCountIterator() {
	itemAmount++;
}

size_t Item::getItemCount()const {
	return itemAmount;
}

void Item::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Item::setAvailability(bool availabilty) {
	this->availability = availabilty;
}

void Item::setPrice(float price) {
	this->price = price;
}

char* Item::getName()const {
	return name;
}

bool Item::getAvailability()const {
	return availability;
}

float Item::getPrice()const {
	return price;
}

Item::~Item() {
	free();
}