#include "Engine.h"

void Engine::setHorsePower(size_t horsePower) {
    _horsePower = horsePower;
}

Engine::Engine(const MyString &manufacturerName, const MyString &description, size_t horsePower) : CarPart(
        manufacturerName, description) {
    setHorsePower(horsePower);
}

size_t Engine::getHorsePower() const {
    return _horsePower;
}

std::ostream &operator<<(std::ostream &out, const Engine &engine) {
    out << (CarPart &) engine;
    return out << engine._horsePower << " hp";
}
