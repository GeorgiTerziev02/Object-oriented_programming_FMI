#include "Polygon.h"
#include <utility>
#include <stdexcept>

Polygon::Point::Point() : Point(0, 0) { }
Polygon::Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Polygon::Polygon(size_t pointsCount) : pointsCount(pointsCount) {
	points = new Point[pointsCount];
}

Polygon::Polygon(const Polygon& other) {
	copyFrom(other);
}

Polygon::Polygon(Polygon&& other) {
	move(std::move(other));
}

Polygon& Polygon::operator=(const Polygon& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Polygon& Polygon::operator=(Polygon&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

Polygon::~Polygon() {
	free();
}

const Polygon::Point& Polygon::getPoint(size_t index) const {
	if (index >= pointsCount) {
		throw std::out_of_range("Error");
	}

	return points[index];
}

void Polygon::setPoint(size_t index, int x, int y) {
	if (index >= pointsCount) {
		throw std::out_of_range("Error");
	}

	points[index].x = x;
	points[index].y = y;
}


void Polygon::free() {
	delete[] points;
	points = nullptr;
	pointsCount = 0;
}

void Polygon::copyFrom(const Polygon& other) {
	pointsCount = other.pointsCount;
	points = new Point[pointsCount];
	for (size_t i = 0; i < pointsCount; i++) {
		points[i] = other.points[i];
	}
}

void Polygon::move(Polygon&& other) {
	points = other.points;
	pointsCount = other.pointsCount;
	other.points = nullptr;
}

double getDistance(const Polygon::Point& p1, const Polygon::Point& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}