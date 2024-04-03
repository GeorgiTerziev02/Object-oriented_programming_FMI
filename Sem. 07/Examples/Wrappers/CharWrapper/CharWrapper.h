#pragma once
#include "../IntWrapper/IntWrapper.h"

class CharWrapper {
private:
    char value;
public:
    CharWrapper(char value);
    char getValue() const;
    
    // Conversion operator
    // If we add explicit here you won't be able to call this implicitly
    operator IntWrapper() const;
};