#include "CharWrapper.h"

CharWrapper::CharWrapper(char value) : value(value) {}

char CharWrapper::getValue() const {
    return value;
}

CharWrapper::operator IntWrapper() const {
    return IntWrapper(value);
}