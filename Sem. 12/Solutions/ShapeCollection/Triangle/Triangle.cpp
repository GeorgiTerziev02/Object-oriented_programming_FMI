#include "Triangle.h"
#include <cmath>
#include <limits>
#include <iostream>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3) {
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

Shape* Triangle::clone() const {
	return new Triangle(*this);
}

double Triangle::getArea() const {
	const Shape::Point& p1 = getPoint(0);
	const Shape::Point& p2 = getPoint(1);
	const Shape::Point& p3 = getPoint(2);

	return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2.00; //formula with the determinant
}

double Triangle::getPer() const {
	const Shape::Point& p1 = getPoint(0);
	const Shape::Point& p2 = getPoint(1);
	const Shape::Point& p3 = getPoint(2);

	return getDistance(p1, p2) + getDistance(p2, p3) + getDistance(p3, p1);
}

bool Triangle::isPointIn(int x, int y) const {
	Shape::Point p(x, y);
	Triangle t1(getPoint(0).x, getPoint(0).y, getPoint(1).x, getPoint(1).y, p.x, p.y);
	Triangle t2(getPoint(2).x, getPoint(2).y, getPoint(1).x, getPoint(1).y, p.x, p.y);
	Triangle t3(getPoint(2).x, getPoint(2).y, getPoint(0).x, getPoint(0).y, p.x, p.y);

	return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();
}

bool Triangle::intersectsWith(const Shape* other) const {
	return other->intersectsWithTriangle(this);
}

bool Triangle::intersectsWithTriangle(const Triangle* other) const {
	std::cout << "Formula for triangle with triangle" << std::endl;
	return true;
}
bool Triangle::intersectsWithRect(const Rectangle* other) const {
	std::cout << "Formula for triangle with rect" << std::endl;
	return true;
}
bool Triangle::intersectsWithCircle(const Circle* other) const {
	std::cout << "Formula for triangle with circle" << std::endl;
	return true;
}