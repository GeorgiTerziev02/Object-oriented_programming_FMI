#ifndef PRACT10_ENGINE_H
#define PRACT10_ENGINE_H
#include "CarPart.h"

class Engine : public CarPart{
private:
    unsigned horsePowers;
public:
    Engine() = delete;
    Engine(const MyString& manufacturerName,const MyString& description, unsigned horsePowers);
    Engine(MyString&& manufacturerName, MyString&& description, unsigned horsePowers);

    unsigned getHorsePowers()const;
    void setHorsePowers(unsigned horsePowers);
    friend std::ostream& operator<<(std::ostream& ofs, const Engine& engine);
};
std::ostream& operator<<(std::ostream& ofs, const Engine& engine);

#endif //PRACT10_ENGINE_H
