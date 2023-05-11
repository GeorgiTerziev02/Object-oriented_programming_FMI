#pragma once
#include "AlcoholDrink.h"
#include "Drink.h"

class Bar {
private:
	const static short MAX_DRINKS_SIZE = 100;

	struct Statistics
	{
		size_t soldDrinks;
		size_t soldAlcoholDrinks;
		size_t mlSold;
	} stats;

    // the next two will be used as stacks
	AlcoholDrink alcDrinks[MAX_DRINKS_SIZE];
	Drink drinks[MAX_DRINKS_SIZE];
	size_t alcDrinksCount = 0;
	size_t drinksCount = 0;

	size_t alcDrinksCounter[MAX_DRINKS_SIZE] = {};
	size_t drinksCounter[MAX_DRINKS_SIZE] = {};

public:
	Bar() = default;

	void addDrink(const Drink& drink, size_t count = 1);
	void addAlcoholDrink(const AlcoholDrink& drink, size_t count = 1);

	Drink getDrink(); // popBack;
	AlcoholDrink getAlcoholDrink(); // popBack

	const Statistics& getStats() const;
};