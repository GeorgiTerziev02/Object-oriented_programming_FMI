#pragma once
#include "Shape.h"

class ShapeCollection {
private:
	Shape** shapes = nullptr;
	size_t size;
	size_t capacity;

	void resize();
	void addShape(Shape*);
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection(ShapeCollection&& other) noexcept;
	ShapeCollection& operator=(const ShapeCollection& other);
	ShapeCollection& operator=(ShapeCollection&& other) noexcept;
	~ShapeCollection();

	void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
	void addRectangle(int x1, int y1, int x3, int y3);
	void addCircle(int x, int y, double radius);

	double getPerOfFigureByIndex(size_t index) const;
	double getAreaOfFigureByIndex(size_t index) const;
	bool getIfPointInShapeByIndex(size_t index, int x, int y) const;
private:
	void move(ShapeCollection&& other);
	void copyFrom(const ShapeCollection& other);
	void free();
};

