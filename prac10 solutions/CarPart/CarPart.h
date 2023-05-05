#pragma once

#include <iostream>
#include "../MyString/MyString.h"

class CarPart {
static size_t _globalId;

private:
    size_t _id;
    MyString _manufacturerName;
    MyString _description;

public:
    CarPart() = delete;
    CarPart(const MyString &manufacturerName, const MyString &description);

    size_t getId() const;
    const MyString &getManufacturerName() const;
    const MyString &getDescription() const;

//    void setId();
    void setManufacturerName(const MyString &manufacturerName);
    void setDescription(const MyString &description);

    friend std::ostream &operator<<(std::ostream &out, const CarPart &carPart);

};
