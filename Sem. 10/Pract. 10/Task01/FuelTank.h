//
// Created by Petar on 6.5.2023 г..
//

#ifndef PRACT10_FUELTANK_H
#define PRACT10_FUELTANK_H
class FuelTank{
private:
    double tankCapacity;
    double tankFull;
public:
    FuelTank() = delete;
    explicit FuelTank(double tankCapacity);
    void use(double toUse);
    void fill(double toFill);

    double getTankCapacity()const;
    double getTankFull()const;

private:
    void setTankCapacity(double tankCapacity);
    void setTankFull(double tankFull);
};
#endif //PRACT10_FUELTANK_H
