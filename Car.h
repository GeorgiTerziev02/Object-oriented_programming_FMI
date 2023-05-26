#pragma once
#include"Accumulator.h"
#include"FuelTank.h"
#include"Tire.h"
#include"Engine.h"
class Car
{
	FuelTank fuelTank;
	Engine engine;
	Tire tires[4];
	Accumulator accumulator;
	double mileage;
	double weight;
public:
	Car(const FuelTank& fuelTank, const Engine& engine, Tire* tires,
		const Accumulator& accumulator, size_t mileage, size_t weight);
	const FuelTank& getFuelTank()const;
	const Engine& getEngine()const;
	void drive(double km);
};

Car* dragRace(Car* car1, Car* car2);
	
