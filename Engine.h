#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
	size_t horsePower;
public:
	Engine() = default;
	Engine(const MyString& name, const MyString& description, size_t horsePower);
	void setHorsePower(size_t horsePower);
	size_t getHorsePower()const;
	friend void operator<<(std::ostream& out, const Engine& currEngine);
};

void operator<<(std::ostream& out, const Engine& currEngine);
