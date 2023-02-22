#include <iostream>

struct Point  {
	double x, y;
};

void readPoint(Point& point) {
	std::cin >> point.x >> point.y;
}

double getSide(const Point& p1, const Point& p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return sqrt(dx * dx + dy * dy);
}

struct Triangle {
	Point p1, p2, p3;
};

void readTriangle(Triangle& triangle) {
	readPoint(triangle.p1);
	readPoint(triangle.p2);
	readPoint(triangle.p3);
}

double getArea(const Triangle& triangle) {
	double sideA = getSide(triangle.p1, triangle.p2);
	double sideB = getSide(triangle.p2, triangle.p3);
	double sideC = getSide(triangle.p3, triangle.p1);

	double halfPerimeter = (sideA + sideB + sideC) / 2;

	// Math formula
	return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
}

double* calculateAreas(const Triangle* triangles, int n) {
	double* areas = new double[n];

	for (int i = 0; i < n; i++) {
		areas[i] = getArea(triangles[i]);
	}

	return areas;
}

int main() {
	int n;
	std::cin >> n;

	Triangle* triangles = new Triangle[n];

	// read triangles
	for (int i = 0; i < n; i++) {
		readTriangle(triangles[i]);
	}

	double* areas = calculateAreas(triangles, n);;

    // TODO: sort
    // TODO: print

	delete[] areas;
	delete[] triangles;
}
