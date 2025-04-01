#pragma once

class Car {
private:
	// and many more members here
	size_t someValue;
public:
	Car();
	Car(size_t value);
	size_t getValue() const;
	void setValue(size_t value);
};
