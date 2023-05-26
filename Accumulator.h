#pragma once
#include "CarPart.h"
class Accumulator: public CarPart
{
	double amperHours;
	MyString batteryId;
public:
	Accumulator() = default;
	Accumulator(const MyString& name, const MyString& description,double amperHours,const MyString& batterId);
	void setAmperHours(double amperHours);
	void setBatterId(const MyString& batteryId);

	friend void operator<<(std::ostream& out, const Accumulator& currAccumulator);
	double getAmperHours()const;
	const MyString& getBatterId()const;
};
void operator<<(std::ostream& out, const Accumulator& currEngine);
