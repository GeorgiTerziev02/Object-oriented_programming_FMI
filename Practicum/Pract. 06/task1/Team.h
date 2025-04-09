#pragma once

#include "SoftwareEngineer.h"

class Team {
private:
    SoftwareEngineer engineers[2];
    int roundWins;
    int roundPoints;

public:
    Team();
    Team(const SoftwareEngineer& e1, const SoftwareEngineer& e2);

    SoftwareEngineer* getEngineers();

    int getRoundWins() const;
    void setRoundWins(int wins);

    int getRoundPoints() const;
    void setRoundPoints(int points);
};
