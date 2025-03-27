#pragma once

#include "Team.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class BelotTournament {
private:
    Team* teams;
    int teamCount;
    int capacity;
    double totalDonation;

    void shuffleTeams();
    Team playMatch(Team& t1, Team& t2);

public:
    BelotTournament();
    ~BelotTournament();

    void addTeam(const Team& team);

    void startTournament();

    double getTotalDonation() const;
};
