#pragma once
#include "../CarPart/CarPart.h"

class Engine : CarPart {
private:
    size_t _horsePower;

    void setHorsePower(size_t horsePower);

public:
    Engine() = delete;
    Engine(const MyString &manufacturerName, const MyString &description, size_t horsePower);

    size_t getHorsePower() const;

    friend std::ostream &operator<<(std::ostream &out, const Engine &engine);

};