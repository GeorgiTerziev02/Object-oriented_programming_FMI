#pragma once

enum class AnimalType {
	Dog = 0,
	Cat = 1
};

class Animal {
private:
	AnimalType type;

public:
	Animal(AnimalType type);
	virtual void roar() const = 0;
	virtual Animal* clone() const = 0;
	AnimalType getType() const;

	virtual ~Animal() = default;
};

