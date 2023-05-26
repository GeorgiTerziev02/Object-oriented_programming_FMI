#include "Engine.h"

Engine::Engine(const MyString& name, const MyString& description, size_t horsePower): CarPart(name,description) {
	setHorsePower(horsePower);
}
void Engine::setHorsePower(size_t horsePower) {
	this->horsePower = horsePower;
}
size_t Engine::getHorsePower()const {
	return horsePower;
}
void operator<<(std::ostream& out, const Engine& currEngine) {
	out << (CarPart)currEngine;
	out << currEngine.horsePower << " hp"<<std::endl;
}