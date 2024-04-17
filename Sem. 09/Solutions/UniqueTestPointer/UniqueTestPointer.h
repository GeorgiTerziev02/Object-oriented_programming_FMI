#pragma once

#include <iostream>

struct Test {
	int a;
	~Test() {
		std::cout << "~";
	}
};

class UniqueTestPointer {
private:
	Test* resource;

public:
	UniqueTestPointer(Test* resource);
	UniqueTestPointer(const UniqueTestPointer&) = delete;
	UniqueTestPointer(UniqueTestPointer&&) noexcept;
	UniqueTestPointer& operator=(const UniqueTestPointer&) = delete;
	UniqueTestPointer& operator=(UniqueTestPointer&&) noexcept;
	~UniqueTestPointer();

	Test* get() const; // Returns the pointer
	void reset(Test* newResource); // Deletes the current pointer and assigns a new one
	Test* release(); // Releases the ownership of the pointer and returns it
	void swap(UniqueTestPointer& other); // Swaps the resources the pointers

	Test* operator->();
	const Test* operator->() const;

	Test& operator*();
	const Test& operator*() const;

	operator bool() const;
private:
	void free();
	void moveFrom(UniqueTestPointer&& other) noexcept;
};

