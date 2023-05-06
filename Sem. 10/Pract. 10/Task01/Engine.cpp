//
// Created by Petar on 3.5.2023 г..
//

#include "Engine.h"

unsigned Engine::getHorsePowers() const {
    return this->horsePowers;
}

void Engine::setHorsePowers(unsigned int horsePowers) {
    this->horsePowers = horsePowers;
}

Engine::Engine(const MyString &manufacturerName, const MyString &description, unsigned int horsePowers)
: CarPart(manufacturerName, description){
    setHorsePowers(horsePowers);
}

Engine::Engine(MyString &&manufacturerName, MyString &&description, unsigned int horsePowers) :
        CarPart(std::move(manufacturerName), std::move(description)){
    setHorsePowers(horsePowers);
}

std::ostream& operator<<(std::ostream &ofs, const Engine &engine) {
    operator<<(ofs, (CarPart&) engine);
    return ofs << " - " << engine.horsePowers << "hp" << std::endl;
}
