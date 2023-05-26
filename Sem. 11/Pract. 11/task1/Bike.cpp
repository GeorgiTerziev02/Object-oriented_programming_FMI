#include "Bike.h"
Bike::Bike(){
	setTires(2);
	setAverageSpeed(20);
	setPassengersCount(1);
}
MyString Bike::whereYouCanDriveTheVehicle() const {
	return "Only in the city";
}