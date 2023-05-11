#include "Tyre.h"
//    широчина в мм – между 155 и 365;
//    профил – между 30 и 80;
//    диаметър в инчове – между 13 и 21.

namespace {
    const short MIN_WIDTH = 155;
    const short MAX_WIDTH = 365;
    const short MIN_PROFILE = 30;
    const short MAX_PROFILE = 80;
    const short MIN_DIAMETER = 13;
    const short MAX_DIAMETER = 21;
}

void Tyre::setWidth(size_t width) {
    if (width < MIN_WIDTH || width > MAX_WIDTH) {
        throw std::invalid_argument("Width should be between 155 and 365!");
    }

    _width = width;
}

void Tyre::setProfile(size_t profile) {
    if (profile < MIN_PROFILE || profile > MAX_PROFILE) {
        throw std::invalid_argument("Profile should be between 30 and 80!");
    }

    _profile = profile;
}

void Tyre::setDiameter(size_t diameter) {
    if (diameter < MIN_DIAMETER || diameter > MAX_DIAMETER) {
        throw std::invalid_argument("Diameter should be between 13 and 21!");
    }

    _diameter = diameter;
}

Tyre::Tyre() : CarPart("DefTyreManu1", "DefTyreDesc1") {
    setWidth(MIN_WIDTH);
    setProfile(MIN_PROFILE);
    setDiameter(MIN_DIAMETER);
}

Tyre::Tyre(const MyString &manufacturerName, const MyString &description, size_t width, size_t profile, size_t diameter)
        : CarPart(manufacturerName, description) {
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

size_t Tyre::getWidth() const {
    return _width;
}

size_t Tyre::getProfile() const {
    return _profile;
}

size_t Tyre::getDiameter() const {
    return _diameter;
}

std::ostream &operator<<(std::ostream &out, const Tyre &tyre) {
//    tyre.printPartInfo(out);
    out << (CarPart &) tyre;
    return out << tyre._width << "/" << tyre._profile << "R" << tyre._diameter;
}
