#pragma once
#include "Tire.h"
enum class EngineType {
	Gasoline,Diesel,Electrical,Hybrid
};
struct Point {
	int x;
	int y;
};
size_t getDistance(const Point& A,const Point& B) {
	int dx = A.x - B.x;
	int dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}
class Vehicle
{
	Tire* tires;
	size_t tiresCount;
	EngineType type;
	size_t passengersCount;
	size_t averageSpeed;
public:
	void setTires(size_t TiresCount);
	void setEnginetype(EngineType type);
	void setPassengersCount(size_t passengersCount);
	void setAverageSpeed(size_t averageSpeed);
	void engineReplace(EngineType newtype);
	size_t timeForGettingDistanceBetweenTwoPoints(const Point& A, const Point& B);
	virtual MyString whereYouCanDriveTheVehicle()const = 0;
	virtual ~Vehicle();
};

