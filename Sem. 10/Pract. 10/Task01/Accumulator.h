//
// Created by Petar on 5.5.2023 г..
//

#ifndef PRACT10_ACCUMULATOR_H
#define PRACT10_ACCUMULATOR_H
#include "CarPart.h"

class Accumulator : public CarPart{
private:
    unsigned capacity;
    MyString batteryId;
public:
    Accumulator() = delete;
    Accumulator(const MyString& manufacturerName,const MyString& description, unsigned capacity, const MyString& batteryId);
    Accumulator(MyString&& manufacturerName, MyString&& description, unsigned capacity, const MyString& batteryId);

    unsigned getCapacity()const;
    const MyString& getBateryId()const;

    void setCapacity(unsigned capacity);
    void setBatteryId(const MyString& batteryId);
    friend std::ostream& operator<<(std::ostream& ofs, const Accumulator& accumulator);
};
std::ostream& operator<<(std::ostream& ofs, const Accumulator& accumulator);
#endif //PRACT10_ACCUMULATOR_H
