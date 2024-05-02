#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y3);
	setPoint(3, x3, y1);
}
double Rectangle::getArea() const
{
	const Shape::Point& p0 = getPointAtIndex(0);
	const Shape::Point& p1 = getPointAtIndex(1);
	const Shape::Point& p2 = getPointAtIndex(2);

	return p0.getDistance(p1) * p1.getDistance(p2);

}
double Rectangle::getPerimeter() const
{
	const Shape::Point& p0 = getPointAtIndex(0);
	const Shape::Point& p1 = getPointAtIndex(1);
	const Shape::Point& p2 = getPointAtIndex(2);

	return 2 * (p0.getDistance(p1) + p1.getDistance(p2));
}

bool Rectangle::isPointIn(int x, int y) const
{
	Shape::Point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.x <= getPointAtIndex(2).x &&
		p.y >= getPointAtIndex(0).y && p.y <= getPointAtIndex(2).y;
}