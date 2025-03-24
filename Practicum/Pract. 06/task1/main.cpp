#pragma warning(disable:4996)

#include "BelotTournament.h"

int main() {
    BelotTournament tournament;

    int n;
    std::cout << "Enter number of teams: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        char buffer[256];
        char* name1, * position1, * name2, * position2;
        int salary1, salary2;

        std::cout << "Enter name for first engineer of team " << (i + 1) << ": ";
        std::cin.getline(buffer, 256);
        name1 = new char[strlen(buffer) + 1];
        std::strcpy(name1, buffer);

        std::cout << "Enter position for first engineer: ";
        std::cin.getline(buffer, 256);
        position1 = new char[strlen(buffer) + 1];
        std::strcpy(position1, buffer);

        std::cout << "Enter salary for first engineer: ";
        std::cin >> salary1;
        std::cin.ignore();

        std::cout << "Enter name for second engineer of team " << (i + 1) << ": ";
        std::cin.getline(buffer, 256);
        name2 = new char[strlen(buffer) + 1];
        std::strcpy(name2, buffer);

        std::cout << "Enter position for second engineer: ";
        std::cin.getline(buffer, 256);
        position2 = new char[strlen(buffer) + 1];
        std::strcpy(position2, buffer);

        std::cout << "Enter salary for second engineer: ";
        std::cin >> salary2;
        std::cin.ignore();

        SoftwareEngineer e1(name1, position1, salary1);
        SoftwareEngineer e2(name2, position2, salary2);
        Team t(e1, e2);
        tournament.addTeam(t);

        delete[] name1;
        delete[] position1;
        delete[] name2;
        delete[] position2;
    }

    tournament.startTournament();

    std::cout << "Total amount raised for charity: "
        << tournament.getTotalDonation() << std::endl;

    return 0;
}
