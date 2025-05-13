#pragma once
#include "Animal.h"

class Farm {
private:
	Animal** animals;
	size_t count;
	size_t capacity;

	void resize();
public:
	Farm();
	Farm(const Farm& other);
	Farm(Farm&& other) noexcept;
	Farm& operator=(const Farm& other);
	Farm& operator=(Farm&& other) noexcept;
	~Farm();

	void addAnimal(AnimalType type);
	AnimalType getAnimalTypeAtIndex(size_t index) const;
	void roarAll() const;

private:
	void free();
	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
};

