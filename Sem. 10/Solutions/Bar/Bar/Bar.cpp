#include "Bar.h"

void Bar::addDrink(const Drink& drink, size_t count) {
	if (drinksCount >= Bar::MAX_DRINKS_SIZE) {
		return;
	}

	drinks[drinksCount] = drink;
	drinksCounter[drinksCount++] = count;
}

void Bar::addAlcoholDrink(const AlcoholDrink& drink, size_t count) {
	if (alcDrinksCount >= Bar::MAX_DRINKS_SIZE) {
		return;
	}

	alcDrinks[alcDrinksCount] = drink;
	alcDrinksCounter[alcDrinksCount++] = count;
}

Drink Bar::getDrink() {
	if (drinksCount == 0) {
		throw std::exception("Drinks array is empty");
	}

	stats.mlSold += drinks[drinksCount - 1].getMl();
	stats.soldDrinks++;

	if (--drinksCounter[drinksCount - 1] == 0) {
		drinksCount--;
	}

	return drinks[drinksCount];
}

AlcoholDrink Bar::getAlcoholDrink() {
	if (alcDrinksCount == 0) {
		throw std::exception("Drinks array is empty");
	}

	stats.mlSold += alcDrinks[alcDrinksCount - 1].getMl();
	stats.soldAlcoholDrinks++;

	if (--alcDrinksCounter[alcDrinksCount - 1] == 0) {
		alcDrinksCount--;
	}

	return alcDrinks[alcDrinksCount];
}

const Bar::Statistics& Bar::getStats() const {
	return stats;
}