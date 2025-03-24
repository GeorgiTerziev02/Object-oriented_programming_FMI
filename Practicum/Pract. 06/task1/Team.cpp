#include "Team.h"

Team::Team() {
    setRoundPoints(2);
    setRoundWins(1);
}

Team::Team(const SoftwareEngineer& e1, const SoftwareEngineer& e2) {
    engineers[0] = e1;
    engineers[1] = e2;
    roundWins = 0;
    roundPoints = 0;
}

SoftwareEngineer* Team::getEngineers() {
    return engineers;
}

int Team::getRoundWins() const {
    return roundWins;
}

void Team::setRoundWins(int wins) {
    roundWins = wins;
}

int Team::getRoundPoints() const {
    return roundPoints;
}

void Team::setRoundPoints(int points) {
    roundPoints = points;
}
