#include "AlcoholDrink.h"

AlcoholDrink::AlcoholDrink() : Drink() {}

AlcoholDrink::AlcoholDrink(const MyString& name, size_t ml, size_t alcPer)
	: Drink(name, ml), alcPer(alcPer) {}

void AlcoholDrink::setAlchoholPer(size_t alcPer) {
	this->alcPer = alcPer;
}

size_t AlcoholDrink::getAlcPer() const {
	return alcPer;
}