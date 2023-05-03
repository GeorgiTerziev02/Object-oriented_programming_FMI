#pragma once

class Polygon {
private:
	struct Point {
		int x, y;
		Point();
		Point(int x, int y);
	};

	Point* points = nullptr;
	size_t pointsCount = 0;

	friend double getDistance(const Point& p1, const Point& p2);
public:
	Polygon(size_t pointsCount);
	Polygon(const Polygon& other);
	Polygon(Polygon&& other);
	Polygon& operator=(const Polygon& other);
	Polygon& operator=(Polygon&& other);
	~Polygon();

	const Point& getPoint(size_t index) const;
	void setPoint(size_t index, int x, int y);

private:
	void free();
	void copyFrom(const Polygon& other);
	void move(Polygon&& other);
};