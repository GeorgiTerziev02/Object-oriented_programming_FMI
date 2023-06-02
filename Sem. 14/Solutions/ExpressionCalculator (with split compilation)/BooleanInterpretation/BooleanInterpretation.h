#pragma once

#include "../constants.h"

class BooleanInterpretation {
private:
    bool _variables[VARIABLES_COUNT] = { false };

public:
    bool getVar(char ch) const;
    void setVar(char ch, bool newVal);

    static bool isCharValid(char ch);
    static BooleanInterpretation createFromNumber(size_t number, const bool variables[VARIABLES_COUNT]);

};
