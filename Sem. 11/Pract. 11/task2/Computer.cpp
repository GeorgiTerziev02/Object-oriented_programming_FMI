#include "Computer.h"

void Computer::setGPU(const MyString& newModel) {
	GPUModel = newModel;
}
void Computer::setPowerSupply(size_t newPowerSupply) {
	powerSupply = newPowerSupply;
}
void Computer::setRAM(size_t newRAM) {
	RAM = newRAM;
}
void Computer::setPower(double newPower) {
	power = newPower;
}