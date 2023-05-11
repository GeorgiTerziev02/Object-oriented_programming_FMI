#include "../Vehicle/Vehicle.h"

class Car : public Vehicle {
private:
    static const MyString _roadType;

public:
    const MyString &getRoadType() const override;

};