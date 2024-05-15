#pragma once

#include "../Shape/Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(int x1, int y1, int x3, int y3);

	Shape* clone() const override;
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;
	
	bool intersectsWith(const Shape* other) const override;

	bool intersectsWithTriangle(const Triangle* other) const override;
	bool intersectsWithRect(const Rectangle* other) const override;
	bool intersectsWithCircle(const Circle* other) const override;
};

