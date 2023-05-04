#include "Car.h"

static const short MAX_TYRES_COUNT = 4;

Car::Car():
	fuelTank(),
	engine(),
	battery(),
	tyres(),
	kmDriven(0.0),
	weight(0.0)
{
}

Car::~Car()
{
	free();
}

Car::Car(const Car& other)
{
	copyFrom(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Car::Car(Car&& other) noexcept
{
	moveFrom(std::move(other));
}

Car& Car::operator=(Car&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Car::Car(const FuelTank& fuelTank, const Engine& engine, 
	Tyre* tyres, const AutomativeBattery& battery, 
	double km, double weight)
	: fuelTank(fuelTank), engine(engine), tyres(tyres), battery(battery),
	kmDriven(km), weight(weight) {}

const FuelTank& Car::getFuelTank() const 
{
	return fuelTank;
}

const Engine& Car::getEngine() const 
{
	return engine;
}

const AutomativeBattery& Car::getBattery() const 
{
	return battery;
}

const Tyre* Car::getTyres() const 
{
	return tyres;
}

double Car::getKmDriven() const
{
	return kmDriven;
}

double Car::getWeigth() const 
{
	return weight;
}


void Car::drive(double km)
{
	double fuelConsumed = engine.getFuelConsumation() * km;
	if (fuelTank.getAmount() < fuelConsumed)
	{
		throw std::runtime_error("Not enough fuel to drive that distance!");
	}
	fuelTank.use(fuelConsumed);
	kmDriven += km;
}

Car* Car::dragRace(Car* car1, Car* car2)
{
	double car1Speed = 0, car2Speed = 0;

	if (car1->fuelTank.getAmount() >= car1->engine.getFuelConsumation())
	{
		car1Speed = car1->engine.getHp() * car1->tyres[0].getTraction();
	}

	if (car2->fuelTank.getAmount() >= car2->engine.getFuelConsumation())
	{
		car2Speed = car2->engine.getHp() * car2->tyres[0].getTraction();
	}

	if (car1Speed == 0 && car2Speed == 0)
	{
		return nullptr;
	}
	else if (car1Speed == 0)
	{
		return car2;
	}
	else if (car2Speed == 0)
	{
		return car1;
	}
	else if (car1Speed > car2Speed)
	{
		return car1;
	}
	else if (car2Speed > car1Speed)
	{
		return car2;
	}
	else if (car1Speed == car2Speed)
	{
		if (car1->engine.getHp() > car2->engine.getHp())
		{
			return car1;
		}
		else if (car2->engine.getHp() > car1->engine.getHp())
		{
			return car2;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}


void Car::copyFrom(const Car& other)
{
	fuelTank = other.fuelTank;
	engine = other.engine;
	battery = other.battery;
	kmDriven = other.kmDriven;
	weight = other.weight;
	tyres = other.tyres;
}

void Car::free()
{
	delete[] tyres;
	tyres = nullptr;
	kmDriven = 0;
	weight = 0;
}

void Car::moveFrom(Car&& other)
{
	fuelTank = std::move(other.fuelTank);
	engine = std::move(other.engine);
	battery = std::move(other.battery);
	kmDriven = other.kmDriven;
	weight = other.weight;
	tyres = other.tyres;
	other.tyres = nullptr;
}