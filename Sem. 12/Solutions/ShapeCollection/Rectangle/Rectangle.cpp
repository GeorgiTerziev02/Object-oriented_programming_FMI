#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4) {
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y1);
	setPoint(3, x3, y3);
}

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

double Rectangle::getArea() const {
	const Shape::Point& p0 = getPoint(0);
	const Shape::Point& p1 = getPoint(1);
	const Shape::Point& p3 = getPoint(3);

	return getDistance(p0, p1) * getDistance(p1, p3);
}

double Rectangle::getPer() const {
	const Shape::Point& p0 = getPoint(0);
	const Shape::Point& p1 = getPoint(1);
	const Shape::Point& p3 = getPoint(3);

	return 2 * (getDistance(p0, p1) + getDistance(p1, p3));
}

bool Rectangle::isPointIn(int x, int y) const {
	return x >= getPoint(0).x && y >= getPoint(1).x &&
		y <= getPoint(0).y && y >= getPoint(2).y;
}

bool Rectangle::intersectsWith(const Shape* other) const {
	return other->intersectsWithRect(this);
}

bool Rectangle::intersectsWithTriangle(const Triangle* other) const {
	std::cout << "Formula for rect with triangle" << std::endl;
	return true;
}
bool Rectangle::intersectsWithRect(const Rectangle* other) const {
	std::cout << "Formula for rect with rect" << std::endl;
	return true;
}
bool Rectangle::intersectsWithCircle(const Circle* other) const {
	std::cout << "Formula for rect with circle" << std::endl;
	return true;
}