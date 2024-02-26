#include <iostream>

namespace Points {
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
}

namespace Figures {
	using namespace Points;
	struct Triangle {
		Point p1, p2, p3;
	};

	void readTriangle(Triangle& t) {
		readPoint(t.p1);
		readPoint(t.p2);
		readPoint(t.p3);
	}

	double getArea(const Triangle& triangle) {
		double sideA = getDistance(triangle.p1, triangle.p2);
		double sideB = getDistance(triangle.p2, triangle.p3);
		double sideC = getDistance(triangle.p3, triangle.p1);

		double halfPerimeter = (sideA + sideB + sideC) / 2;

		// Math formula
		return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
	}

	void sortTriangles(Triangle* triangles, size_t length) {
		double* areas = new double[length];
		for (size_t i = 0; i < length; i++) {
			areas[i] = getArea(triangles[i]);
		}

		for (size_t i = 0; i < length - 1; i++) {
			size_t minIndex = i;

			for (size_t j = i + 1; j < length; j++) {
				if (areas[minIndex] > areas[j]) {
					minIndex = j;
				}
			}

			if (minIndex != i) {
				// better write your own functions
				std::swap(triangles[i], triangles[minIndex]);
				std::swap(areas[i], areas[minIndex]);
			}
		}

		delete[] areas;
	}

	void printTriangle(const Triangle& t) {
		printPoint(t.p1);
		printPoint(t.p2);
		printPoint(t.p3);
	}
}

int main() {
	size_t length;
	std::cin >> length;

	Figures::Triangle* triangles = new Figures::Triangle[length];
	for (size_t i = 0; i < length; i++) {
		Figures::readTriangle(triangles[i]);
	}

	Figures::sortTriangles(triangles, length);

	for (size_t i = 0; i < length; i++) {
		Figures::printTriangle(triangles[i]);
	}

	delete[] triangles;
}