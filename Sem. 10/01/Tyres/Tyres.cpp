#include "Tyres.h"

Tyre::Tyre() : Tyre(0, "" , "", 0, 0, 0, 0.0) {}

Tyre::Tyre(unsigned id, const MyString& manufacturer, const MyString& description,
    unsigned widht, unsigned profile, unsigned dm, double coefficientOfFriction)
    : CarPart(id, manufacturer, description), coefficientOfFriction(coefficientOfFriction)
{
    setWidth(widht);
    setProfile(profile);
    setDm(dm);
}

unsigned Tyre::getWidth() const
{
    return width;
}

unsigned Tyre::getProfile() const
{
    return profile;
}

unsigned Tyre::getDm() const
{
    return dm;
}

double Tyre::getTraction() const
{
    return coefficientOfFriction;
}

void Tyre::setWidth(unsigned width)
{
    if (width < 155 || width > 365)
    {
        throw std::out_of_range("The tyres width should be in range of 155 to 365");
    }
    this->width = width;
}

void Tyre::setProfile(unsigned profile)
{
    if (profile < 30 || profile > 80)
    {
        throw std::out_of_range("The tyres profile should be in range of 30 to 80");
    }
    this->profile = profile;
}

void Tyre::setDm(unsigned dm)
{
    if (dm < 13 || dm > 21)
    {
        throw std::out_of_range("The tyres decimeter should be in range of 13 to 21");
    }
    this->dm = dm;
}

void Tyre::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << width << "mm" << " - " << profile << "profile - " << dm << "dm";
}
