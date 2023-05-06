#ifndef PRACT10_CARPART_H
#define PRACT10_CARPART_H
#include "MyString.h"

class CarPart{
    static unsigned countOfInstances;
private:
    unsigned id;
    MyString manufacturerName;
    MyString description;

public:
    CarPart() = delete;
    CarPart(const MyString& manufacturerName, const MyString& description);
    CarPart(MyString&& manufacturerName, MyString&& description);

    unsigned getId() const;
    const MyString& getManufacturerName() const;
    const MyString& getDescription() const;

    void setManufacturerName(const MyString& newName);
    void setDescription(const MyString& newDescription);
    friend std::ostream& operator<<(std::ostream& ofs, const CarPart& part);
};
std::ostream& operator<<(std::ostream& ofs, const CarPart& part);
#endif //PRACT10_CARPART_H
