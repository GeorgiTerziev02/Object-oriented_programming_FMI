#include "Autobus.h"
Autobus::Autobus(EngineType engine) {
	setTires(4);
	setPassengersCount(50);
	setAverageSpeed(60);
	setEnginetype(engine);
}
MyString Autobus::whereYouCanDriveTheVehicle()const {
	return "Everywhere except offroad";
}