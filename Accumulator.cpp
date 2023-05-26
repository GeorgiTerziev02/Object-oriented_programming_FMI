#include "Accumulator.h"

Accumulator::Accumulator(const MyString& name, const MyString& description, double amperHours, const MyString& batterId): CarPart(name,description) {
	
}
void Accumulator::setAmperHours(double amperHours) {
	this->amperHours = amperHours;
}
void Accumulator::setBatterId(const MyString& batteryId) {
	this->batteryId = batteryId;
}

double Accumulator::getAmperHours()const {
	return amperHours;
}
const MyString& Accumulator::getBatterId()const {
	return batteryId;
}

void operator<<(std::ostream& out, const Accumulator& currAccumulator) {
	out << (CarPart)currAccumulator;
	out << currAccumulator.amperHours << " Ah" << std::endl;
}