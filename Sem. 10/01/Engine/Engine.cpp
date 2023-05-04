#include "Engine.h"

Engine::Engine() :Engine(0, "", "", 0, 0.0) {}

Engine::Engine(unsigned id, const MyString& manufacturer, const MyString& description, unsigned hP, double fuelConsumation)
	: CarPart(id, manufacturer, description), hP(hP), fuelConsumation(fuelConsumation) {}

unsigned Engine::getHp() const
{
	return hP;
}

double Engine::getFuelConsumation() const
{
	return fuelConsumation;
}

void Engine::print(std::ostream& os) const
{
	CarPart::print(os);
	os << " - " << hP << "hp";
}
