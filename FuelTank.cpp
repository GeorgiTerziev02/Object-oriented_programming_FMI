#include "FuelTank.h"


FuelTank::FuelTank(double initialCapacity) {
	fullness = initialCapacity;
	capacity = initialCapacity;
}
void FuelTank::use(double toUse) {
	if (fullness - toUse < 0.000000000001 ) {
		throw insufficient_fuel_error("no fuel");
	}
	fullness -= toUse;

}
void FuelTank::fill(double toFill) {
	fullness += toFill;
	if (fullness >= capacity) {
		fullness = capacity;
	}

}