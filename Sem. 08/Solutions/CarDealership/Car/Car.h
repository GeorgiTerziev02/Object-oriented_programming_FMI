#pragma once

class Car {
private:
	size_t number;
    
public:
	Car(size_t number);
	size_t getNumber() const;
	void setNumber(size_t number);
};