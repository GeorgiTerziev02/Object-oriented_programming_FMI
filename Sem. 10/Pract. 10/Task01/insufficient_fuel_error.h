//
// Created by Petar on 5.5.2023 г..
//

#ifndef PRACT10_INSUFFICIENT_FUEL_ERROR_H
#define PRACT10_INSUFFICIENT_FUEL_ERROR_H
#include "iostream"
#include "MyString.h"

class insufficient_fuel_error : public std::logic_error{
private:
    MyString errorMessage;
public:
    insufficient_fuel_error();
    explicit insufficient_fuel_error(const MyString& message);
    const MyString& getErrorMessage()const;
};

#endif //PRACT10_INSUFFICIENT_FUEL_ERROR_H
