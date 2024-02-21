#include <iostream>
struct Point {
	int x = 0;
	int y = 0;
};

void readPoint(Point& p) {
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
	std::cout << p.x << " " << p.y;
}

double getDistance(const Point& p1, const Point& p2) {
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

struct Triangle {
	Point p1, p2, p3;
};
