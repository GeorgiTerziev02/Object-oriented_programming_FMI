#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tyres.h"
#include "AutomativeBattery.h"


class Car
{
private:
	FuelTank fuelTank;
	Engine engine;
	AutomativeBattery battery;
	Tyre* tyres;
	double kmDriven;
	double weight;
public:
	Car();
	~Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	Car(Car&& othere) noexcept;
	Car& operator=(Car&& other) noexcept;

	Car(const FuelTank& fuelTank, const Engine& engine, 
		Tyre* tyres, const AutomativeBattery& battery, 
		double km = 0, double weight = 0);

	const FuelTank& getFuelTank() const ;
	const Engine& getEngine() const;
	const AutomativeBattery& getBattery() const;
	const Tyre* getTyres() const;
	double getKmDriven() const;
	double getWeigth() const;
	void drive(double km);

	Car* dragRace(Car* car1, Car* car2);
private:
	void copyFrom(const Car& other);
	void free();
	void moveFrom(Car&& other);
};

