#pragma once
#include "../Shape/Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle(int x, int y, double radius);

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
	
	bool intersectsWith(const Shape* other) const override;

	bool intersectsWithTriangle(const Triangle* other) const override;
	bool intersectsWithRect(const Rectangle* other) const override;
	bool intersectsWithCircle(const Circle* other) const override;
};