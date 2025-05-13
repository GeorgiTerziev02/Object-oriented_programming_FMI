#include "Circle.h"
#include <iostream>

namespace {
	const double PI = 3.1415;
}

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius) {
	setPoint(0, x, y);
}

Shape* Circle::clone() const {
	return new Circle(*this);
}

double Circle::getArea() const {
	return PI * radius * radius;
}

double Circle::getPer() const {
	return 2 * PI * radius;
}

bool Circle::isPointIn(int x, int y) const {
	Shape::Point point(x, y);
	return getDistance(point, getPoint(0)) <= radius;
}
#include "Circle.h"

const double PI = 3.1415;
Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
	setPoint(0, x, y);
}

bool Circle::intersectsWith(const Shape* other) const {
	return other->intersectsWithCircle(this);
}
bool Circle::intersectsWithTriangle(const Triangle* other) const {
	std::cout << "Formula for circle with triangle" << std::endl;
	return true;
}
bool Circle::intersectsWithRect(const Rectangle* other) const {
	std::cout << "Formula for circle with rect" << std::endl;
	return true;
}
bool Circle::intersectsWithCircle(const Circle* other) const {
	std::cout << "Formula for circle with circle" << std::endl;
	return true;
}