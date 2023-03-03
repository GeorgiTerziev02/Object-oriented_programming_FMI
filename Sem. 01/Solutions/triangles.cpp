#include <iostream>

struct Point  {
	double x, y;
};

void readPoint(Point& point) {
	std::cin >> point.x >> point.y;
}

void printPoint(const Point& point) {
	std::cout << point.x << " " << point.y;
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

void printTriangle(const Triangle& triangle) {
	printPoint(triangle.p1);
	std::cout << " ";
	printPoint(triangle.p2);
	std::cout << " ";
	printPoint(triangle.p3);
	std::cout << std::endl;
}

double getArea(const Triangle& triangle) {
	double sideA = getSide(triangle.p1, triangle.p2);
	double sideB = getSide(triangle.p2, triangle.p3);
	double sideC = getSide(triangle.p3, triangle.p1);

	double halfPerimeter = (sideA + sideB + sideC) / 2;

	// Math formula
	return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
}

void swap(double& d1, double& d2) {
	double temp = d1;
	d1 = d2;
	d2 = temp;
}

void swap(Triangle& t1, Triangle& t2) {
	Triangle temp = t1;
	t1 = t2;
	t2 = temp;
}

void sortTriangles(Triangle* triangles, double* areas, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minElementIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (areas[j] > areas[minElementIndex]) {
				minElementIndex = j;
			}
		}

		if (minElementIndex != i) {
			swap(areas[i], areas[minElementIndex]);
			swap(triangles[i], triangles[minElementIndex]);
		}
	}
}

int main() {
	int size;
	std::cin >> size;

	Triangle* triangles = new Triangle[size];
	double* areas = new double[size];

	// read triangles
	for (int i = 0; i < size; i++) {
		readTriangle(triangles[i]);
		areas[i] = getArea(triangles[i]);
	}

    // sort triangles
	sortTriangles(triangles, areas, size);
	
	// print triangles
	for (int i = 0; i < size; i++) {
		printTriangle(triangles[i]);
	}

	delete[] areas;
	delete[] triangles;
}
