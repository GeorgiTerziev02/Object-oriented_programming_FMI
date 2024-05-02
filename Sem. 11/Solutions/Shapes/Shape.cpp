#include "Shape.h"

Shape::Point::Point() { }

Shape::Point::Point(int x, int y): x(x), y(y) { }

double Shape::Point::getDistance(const Point& other) const
{
	int dx = x - other.x;
	int dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
	{
		throw std::out_of_range("Invalid point index");
	}

	return points[index];
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];

	for (int i = 0; i < other.pointsCount; i++)
		points[i] = other.points[i];

	pointsCount = other.pointsCount;
}

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	pointsCount = other.pointsCount;
	other.points = nullptr;
	other.pointsCount = 0;
}

void Shape::free()
{
	delete[] points;
}

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount)
{
	points = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape::Shape(Shape&& other)
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape& Shape::operator=(Shape&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount) {
		throw std::out_of_range("Invalid point index");
	}

	points[pointIndex].x = x;
	points[pointIndex].y = y;
}