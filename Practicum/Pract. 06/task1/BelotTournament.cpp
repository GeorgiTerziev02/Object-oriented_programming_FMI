#include "BelotTournament.h"

BelotTournament::BelotTournament() {
    capacity = 100;
    teams = new Team[capacity];
    teamCount = 0;
    totalDonation = 0.0;
}

BelotTournament::~BelotTournament() {
    delete[] teams;
}

void BelotTournament::addTeam(const Team& team) {
    if (teamCount < capacity) {
        teams[teamCount] = team;
        teamCount++;
    }
    else {
        std::cout << "Not enough space for more teams.\n";
    }
}

void BelotTournament::shuffleTeams() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < teamCount; i++) {
        int r = rand() % teamCount;
        Team temp = teams[i];
        teams[i] = teams[r];
        teams[r] = temp;
    }
}

Team BelotTournament::playMatch(Team& t1, Team& t2) {
    t1.setRoundWins(0);
    t2.setRoundWins(0);

    for (int round = 0; round < 3; round++) {
        if (t1.getRoundWins() == 2 || t2.getRoundWins() == 2) {
            break;
        }
        t1.setRoundPoints(0);
        t2.setRoundPoints(0);

        while (true) {
            int p1, p2;
            std::cout << "Enter points for team 1 and team 2:";
            std::cin >> p1 >> p2;

            int newT1Points = t1.getRoundPoints() + p1;
            int newT2Points = t2.getRoundPoints() + p2;

            bool firstTo151 = false;
            t1.setRoundPoints(newT1Points);
            if (t1.getRoundPoints() >= 151) {
                t1.setRoundWins(t1.getRoundWins() + 1);
                firstTo151 = true;
            }

            if (!firstTo151) {
                t2.setRoundPoints(newT2Points);
                if (t2.getRoundPoints() >= 151) {
                    t2.setRoundWins(t2.getRoundWins() + 1);
                }
            }

            if (t1.getRoundPoints() >= 151 || t2.getRoundPoints() >= 151) {
                break;
            }
        }
    }

    Team* winner = &t1;
    Team* loser = &t2;
    if (t2.getRoundWins() > t1.getRoundWins()) {
        winner = &t2;
        loser = &t1;
    }

    for (int i = 0; i < 2; i++) {
        double loserDonation = loser->getEngineers()[i].getSalary() * 0.02;
        totalDonation += loserDonation;

        double winnerDonation = winner->getEngineers()[i].getSalary() * 0.01;
        totalDonation += winnerDonation;
    }

    return *winner;
}

void BelotTournament::startTournament() {
    if (teamCount % 2 != 0) {
        teamCount--;
        std::cout << "Odd number of teams! The last added team has been removed.\n";
    }

    if (teamCount < 4) {
        std::cout << "Not enough teams to start the tournament.\n";
        return;
    }   

    shuffleTeams();

    int currentCount = teamCount;
    while (currentCount > 1) {
        int newSize = currentCount / 2;
        Team* nextRound = new Team[newSize];

        int id = 0;
        for (int i = 0; i < currentCount; i += 2) {
            Team winner = playMatch(teams[i], teams[i + 1]);
            nextRound[id] = winner;
            id++;
        }

        delete[] teams;
        teams = nextRound;
        currentCount = newSize;
    }

    std::cout << "The tournament is over! We have a winner.\n";
}

double BelotTournament::getTotalDonation() const {
    return totalDonation;
}