#include "../MyString/MyString.h"
#include "../Tyre/Tyre.h"

//бензинов, дизелов, електрически и т.н.

enum class EngineType {
    gasoline,
    diesel,
    electric
};

struct Point {
    int x;
    int y;
};

class Vehicle {
private:
    Tyre *_tyres;
    size_t _tyreCount;
    EngineType _engineType;
    size_t _passengersCount;
    double _averageSpeed;

    void copyFrom(const Vehicle &other);
    void moveFrom(Vehicle &&other);
    void free();

public:
    // Big 6
    Vehicle() = default;
    Vehicle(const Vehicle &other);
    Vehicle(Vehicle &&other) noexcept ;
    Vehicle &operator=(const Vehicle &other);
    Vehicle &operator=(Vehicle &&other) noexcept ;
    virtual ~Vehicle();

    Vehicle(const Tyre *tyres, size_t tyreCount, EngineType engineType, size_t passengersCount, double averageSpeed);

    void changeEngineType(EngineType _newEngineType);
    double calculateTimeToGetFromAToB(const Point &a, const Point &b) const;
    void changeTyre(const Tyre &newTyre, size_t index);
    virtual const MyString &getRoadType() const = 0;

};
