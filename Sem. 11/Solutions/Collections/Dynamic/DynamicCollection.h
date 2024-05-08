#pragma once
#include "../Collection.h"

class DynamicCollection : public Collection {
protected:
	int* data = nullptr;
	size_t size = 0;
	size_t capacity = 8;
	void resize(size_t);

public:
	DynamicCollection();

	DynamicCollection(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other) noexcept;

	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection& operator=(DynamicCollection&& other) noexcept;

	~DynamicCollection();

private:
	void free();
	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&&);
};

