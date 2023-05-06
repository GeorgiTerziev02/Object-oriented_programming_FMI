//
// Created by Petar on 5.5.2023 г..
//

#include "Tyres.h"
#include "consts.h"

Tyres::Tyres(const MyString &manufacturerName, const MyString &description, unsigned int width, unsigned int profile,
               unsigned int diameter) : CarPart(manufacturerName, description) {
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

Tyres::Tyres(MyString &&manufacturerName, MyString &&description, unsigned int width, unsigned int profile,
               unsigned int diameter) : CarPart(std::move(manufacturerName), std::move(description)){
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

unsigned Tyres::getWidth() const {
    return width;
}

unsigned Tyres::getProfile() const {
    return profile;
}

unsigned Tyres::getDiameter() const {
    return diameter;
}

void Tyres::setWidth(unsigned int width) {
    if(!validateInterval(width, TyresConsts::WIDTH_MIN_VALUE, TyresConsts::WIDTH_MAX_VALUE))
        throw std::invalid_argument("Incorrect value for the width!");

    this->width = width;
}

void Tyres::setProfile(unsigned int profile) {
    if(!validateInterval(profile, TyresConsts::PROFILE_MIN_VALUE, TyresConsts::PROFILE_MAX_VALUE))
        throw std::invalid_argument("Incorrect value for the profile!");

    this->profile = profile;
}

void Tyres::setDiameter(unsigned int diameter) {
    if(!validateInterval(diameter, TyresConsts::DIAMETER_MIN_VALUE, TyresConsts::DIAMETER_MAX_VALUE))
        throw std::invalid_argument("Incorrect value for the diameter");

    this->diameter = diameter;
}

bool Tyres::validateInterval(unsigned upcomingValue, unsigned minValue, unsigned maxValue) const{
    return minValue <= upcomingValue && upcomingValue <= maxValue;
}

std::ostream &operator<<(std::ostream &ofs, const Tyres &tyres) {
    operator<<(ofs, (CarPart&) tyres);
    return ofs << tyres.width << "/" << tyres.profile << "R" << tyres.diameter << std::endl;
}

Tyres::Tyres() : CarPart("Default tyre manufacturer", "Default tyre"){
    this->width = this-> profile = this->diameter = 0;
}


