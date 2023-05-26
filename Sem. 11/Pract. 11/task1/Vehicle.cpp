#include "Vehicle.h"
void Vehicle::setTires(size_t tiresCount) {
	tires = new Tire[tiresCount];
	this->tiresCount = tiresCount;
}
void Vehicle::setEnginetype(EngineType type) {
	this->type = type;
}
void Vehicle::setPassengersCount(size_t passengersCount) {
	this->passengersCount = passengersCount;
}
void Vehicle::setAverageSpeed(size_t averageSpeed) {
	this->averageSpeed = averageSpeed;
}
void Vehicle::engineReplace(EngineType newtype) {
	this->type = newtype;
}
size_t Vehicle::timeForGettingDistanceBetweenTwoPoints(const Point& A, const Point& B) {
	size_t distance = getDistance(A, B);
	return distance / averageSpeed;
}
Vehicle::~Vehicle() {
	delete[] tires;
}