#pragma once

#include <iostream>

#include "../BooleanInterpretation/BooleanInterpretation.h"
#include "../constants.h"

class BooleanExpression {
public:
    bool _variables[VARIABLES_COUNT] = { false };
    size_t _variablesCount = 0;

    virtual BooleanExpression *clone() const = 0;

    virtual ~BooleanExpression() = default;

    virtual bool evaluate(const BooleanInterpretation &interpretation) const = 0;

};
