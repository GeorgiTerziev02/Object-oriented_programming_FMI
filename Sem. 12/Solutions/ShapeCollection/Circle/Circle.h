#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle(int x, int y, double radius);

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
};