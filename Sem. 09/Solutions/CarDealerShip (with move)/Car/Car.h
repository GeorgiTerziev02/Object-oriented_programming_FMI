#pragma once

class Car {
private:
	// and many more members here
	// and imagine there is a dynamic memory
	// that is allocated in the constructor
	// (in order the move stuff to be usefull)
	size_t someValue;
public:
	Car();
	Car(size_t value);
	Car(const Car& other) = default;
	Car& operator=(const Car& other) = default;
	Car(Car&& other) noexcept = default;
	Car& operator=(Car&& other) noexcept = default;
	~Car() = default;
	
	size_t getValue() const;
	void setValue(size_t value);
};
