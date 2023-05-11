#include "../Vehicle/Vehicle.h"

class Bike : public Vehicle {
private:
    static const MyString _roadType;

public:
    const MyString &getRoadType() const override;

};
