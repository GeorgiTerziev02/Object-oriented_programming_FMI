#include "Shape.h"
#include <cmath>
#include <utility>
#include <stdexcept>

Shape::Point::Point() : x(0), y(0) {}
Shape::Point::Point(int x, int y) : x(x), y(y) {}

double getDistance(const Shape::Point& p1, const Shape::Point& p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount) {
	this->points = new Point[pointsCount];
}

Shape::Shape(const Shape& other) {
	copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept {
	move(std::move(other));
}

Shape& Shape::operator=(const Shape& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

Shape::~Shape() {
	free();
}

const Shape::Point& Shape::getPoint(size_t index) const {
	if (index >= pointsCount) {
		throw std::out_of_range("Out of range");
	}

	return points[index];
}

void Shape::setPoint(size_t index, int x, int y) {
	if (index >= pointsCount) {
		throw std::out_of_range("Out of range");
	}

	points[index].x = x;
	points[index].y = y;
}

void Shape::move(Shape&& other) {
	pointsCount = other.pointsCount;
	points = other.points;
	other.points = nullptr;
	other.pointsCount = 0;
}

void Shape::copyFrom(const Shape& other) {
	pointsCount = other.pointsCount;
	points = new Point[pointsCount];
	for (size_t i = 0; i < pointsCount; i++) {
		points[i] = other.points[i];
	}
}

void Shape::free() {
	delete[] points;
	points = nullptr;
	pointsCount = 0;
}