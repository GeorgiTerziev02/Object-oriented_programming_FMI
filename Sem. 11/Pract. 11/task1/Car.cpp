#include "Car.h"

Car::Car(EngineType engine) {
	setTires(4);
	setPassengersCount(5);
	setAverageSpeed(80);
	setEnginetype(engine);
}
MyString Car::whereYouCanDriveTheVehicle() const {
	return "Everywhere";
}