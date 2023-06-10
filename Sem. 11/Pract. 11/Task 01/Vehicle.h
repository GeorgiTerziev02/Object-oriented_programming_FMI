#pragma once
#include "Tire.h"
#include "Engine.h"


class Vehicle
{
private:

	Tire* tires;
	size_t tiresAmount;
	Engine engine;
	size_t passengersAmount;
	double averageSpeed; // km/h

public:
	Vehicle(size_t tiresAmount, size_t passengersAmount, double averageSpeed);
	virtual ~Vehicle();

	void setEngine(const Engine& newEngine);
	void changeTire(size_t index, const Tire& newTire);
	double calculateMinutesForDistance(size_t distanceLength) const;
	virtual const MyString* getAllowedDrivingPlaces() const = 0;
};

