//
// Created by Petar on 5.5.2023 г..
//

#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error() : insufficient_fuel_error("Error!") {
}

insufficient_fuel_error::insufficient_fuel_error(const MyString &message) : std::logic_error(message.c_str()){
}

const MyString &insufficient_fuel_error::getErrorMessage() const {
    return this->errorMessage;
}
