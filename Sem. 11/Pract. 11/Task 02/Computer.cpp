#include "Computer.h"

Computer::Computer(double processorPower, const MyString& videoCardModel, unsigned int powerSupply, unsigned int ram) {

	this->processorPower = processorPower;
	this->videoCardModel = videoCardModel;
	this->powerSupply = powerSupply;
	this->ram = ram;
}

Computer::~Computer() {}

void Computer::setProcessorPower(double newProcessorPower) {
	processorPower = newProcessorPower;
}
void Computer::setVideoCardModel(const MyString& newVideoCardModel) {
	videoCardModel = newVideoCardModel;
}

void Computer::setPowerSupply(unsigned int newPowerSupply) {
	powerSupply = newPowerSupply;
}

void Computer::setRam(unsigned int newRam) {
	ram = newRam;
}
