#pragma once
#include "../CarPart/CarPart.h"

class Tyre : CarPart {
private:
    size_t _width;
    size_t _profile;
    size_t _diameter;

    void setWidth(size_t width);
    void setProfile(size_t profile);
    void setDiameter(size_t diameter);

public:
    Tyre() = delete;
    Tyre(const MyString &manufacturerName, const MyString &description, size_t width, size_t profile, size_t diameter);

public:
    size_t getWidth() const;
    size_t getProfile() const;
    size_t getDiameter() const;

    friend std::ostream &operator<<(std::ostream &out, const Tyre &tyre);

};