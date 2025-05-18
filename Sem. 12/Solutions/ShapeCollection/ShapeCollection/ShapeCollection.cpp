#include "ShapeCollection.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <utility>
#include <exception>

ShapeCollection::ShapeCollection() : size(0), capacity(4) {
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other) {
	copyFrom(other);
}

ShapeCollection::ShapeCollection(ShapeCollection&& other) noexcept {
	move(std::move(other));
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

ShapeCollection::~ShapeCollection() {
	free();
}

void ShapeCollection::resize() {
	Shape** temp = new Shape * [capacity *= 2];
	for (size_t i = 0; i < size; i++) {
		temp[i] = shapes[i];
	}
	delete[] shapes;
	shapes = temp;
}


void ShapeCollection::addShape(Shape* newShape) {
	if (size == capacity) {
		resize();
	}

	shapes[size++] = newShape;
}

void ShapeCollection::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	addShape(new Triangle(x1, y1, x2, y2, x3, y3));
}

void ShapeCollection::addRectangle(int x1, int y1, int x3, int y3) {
	addShape(new Rectangle(x1, y1, x3, y3));
}

void ShapeCollection::addCircle(int x, int y, double radius) {
	addShape(new Circle(x, y, radius));
}

double ShapeCollection::getPerOfFigureByIndex(size_t index) const {
	if (index >= size) {
		throw std::exception("Error");
	}

	return shapes[index]->getPer();
}

double ShapeCollection::getAreaOfFigureByIndex(size_t index) const {
	if (index >= size) {
		throw std::exception("Error");
	}

	return shapes[index]->getArea();
}

bool ShapeCollection::getIfPointInShapeByIndex(size_t index, int x, int y) const {
	if (index >= size) {
		throw std::exception("Error");
	}

	return shapes[index]->isPointIn(x, y);
}

void ShapeCollection::move(ShapeCollection&& other) {
	shapes = other.shapes;
	size = other.size;
	capacity = other.capacity;
	other.shapes = nullptr;
	other.size = 0;
	other.capacity = 0;
}

// not exception safe
void ShapeCollection::copyFrom(const ShapeCollection& other) {
	size = other.size;
	capacity = other.capacity;

	shapes = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		shapes[i] = other.shapes[i]->clone();
	}
}

//Shape** ShapeCollection::exceptionSafeCopyData(const ShapeCollection& other) {
//	size_t copiedUntil = 0;
//	Shape** tempData;
//	try {
//		
//		tempData = new Shape * [other.capacity];
//		for (size_t i = 0; i < other.size; i++) {
//			tempData[i] = other.data[i]->clone();
//			copiedUntil++;
//		}
//	}
//	catch (const std::exception& e)
//	{
//		for (size_t i = 0; i < copiedUntil; i++) {
//			delete tempData[i];
//		}
//		delete[] tempData;
//		throw e;
//	}
//
//	return tempData;
//}

// exception safe op=
// ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
//	if (this != &other) {
//		Shape** temp = exceptionSafeCopyData(other);
//		freeDynamic();
//		data = temp;
//		size = other.size;
//		capacity = other.capacity;
//	}
//
//	return *this;
//}

void ShapeCollection::free() {
	for (size_t i = 0; i < size; i++) {
		delete shapes[i];
	}

	delete[] shapes;
	shapes = nullptr;
}
