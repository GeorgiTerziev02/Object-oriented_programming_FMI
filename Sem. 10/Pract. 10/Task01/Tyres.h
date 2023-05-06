//
// Created by Petar on 5.5.2023 г..
//

#ifndef PRACT10_TYRES_H
#define PRACT10_TYRES_H
#include "CarPart.h"
class Tyres : public CarPart{
private:
    unsigned width;
    unsigned profile;
    unsigned diameter;

public:
    Tyres();
    Tyres(const MyString& manufacturerName,const MyString& description, unsigned width, unsigned profile, unsigned diameter);
    Tyres(MyString&& manufacturerName, MyString&& description, unsigned width, unsigned profile, unsigned diameter);

    unsigned getWidth() const;
    unsigned getProfile() const;
    unsigned getDiameter() const;

    friend std::ostream& operator<<(std::ostream& ofs, const Tyres& tyres);
private:
    void setWidth(unsigned width);
    void setProfile(unsigned profile);
    void setDiameter(unsigned diameter);

    bool validateInterval(unsigned upcomingValue, unsigned minValue, unsigned maxValue) const;
};

std::ostream& operator<<(std::ostream& ofs, const Tyres& tyres);
#endif //PRACT10_TYRES_H
