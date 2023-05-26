#include "Tir.h"
Tir::Tir(EngineType engine) {
	setPassengersCount(2);
	setAverageSpeed(100);
	setTires(12);
	setEnginetype(engine);
}
MyString Tir::whereYouCanDriveTheVehicle()const  {
	return "Only on highways";
}