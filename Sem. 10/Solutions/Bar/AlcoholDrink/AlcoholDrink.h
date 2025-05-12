#pragma once
#include "Drink.h"

class AlcoholDrink : public Drink {
private:
	size_t alcPer;
public:
	AlcoholDrink();
	AlcoholDrink(const MyString& name, size_t ml, size_t alcPer);

	void setAlchoholPer(size_t alcPer);
	size_t getAlcPer() const;
};