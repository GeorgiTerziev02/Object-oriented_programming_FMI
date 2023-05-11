#pragma once

class Test {

};

// NOTE!: most of the functions are not needed in the class
// or do not work as in the original std::vector
// They were created for testing purposes
class Vector {
private:
	Test* data = nullptr;
	size_t size = 0;
	size_t capacity;
	// the resize function of the actual std::vector
	// just lowers the size, the function that changes capacity is called reserve there
	void resize(size_t newCapacity);

	// Not needed functions - created in class to reuse code
	void assertIndex(size_t index) const;
	void upsizeIfNeeded();
	void downsizeIfNeeded();
public:
	Vector();
	Vector(size_t capacity);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;

	// push/pop at do not exist in actual std::vector
	void pushBack(const Test& element);
	void pushAt(const Test& element, size_t index);
	Test popBack();
	Test popAt(size_t index);

	bool empty() const;
	void clear();
	void shrinkToFit();

	Test& operator[](size_t index);
	const Test& operator[](size_t index) const;

private:
	void copyFrom(const Vector& other);
	void free();
};
