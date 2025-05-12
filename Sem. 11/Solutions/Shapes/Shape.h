#pragma once
#include <iostream>

class Shape
{
protected:
	struct Point
	{
		int x = 0;
		int y = 0;

		Point();
		Point(int x, int y);

		double getDistance(const Point& other) const;
	};

	const Point& getPointAtIndex(size_t index) const;

private:
	Point* points;
	size_t pointsCount;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();

public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape(Shape&& other);
	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other);
	virtual ~Shape();

	void setPoint(size_t pointIndex, int x, int y);
	
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual bool isPointIn(int x, int y) const = 0;
};