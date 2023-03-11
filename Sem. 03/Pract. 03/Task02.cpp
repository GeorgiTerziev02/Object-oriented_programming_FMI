#include <iostream>
#include <fstream>

const char FILE_NAME[] = "output.bin";
const char PERFECT_FILE_NAME[] = "perfectOffers.bin";
const int MAX_NAME_SIZE = 25;

struct Offer {
    char companyName[MAX_NAME_SIZE];
    int coworkersCount;
    int paidVacationDays;
    long long salary;
}; // 48 bytes

void printOffer(const Offer& offer) {
    std::cout << "Company name: " <<  offer.companyName
              << ", Coworkers: " << offer.coworkersCount
              << ", Vacation days: " << offer.paidVacationDays
              << ", Salary: " << offer.salary
              << std::endl;
}

void printOffers(Offer* offers, const int offersCount) {
    std::cout << "Companies: " << std::endl;

    for (int i = 0; i < offersCount; ++i) {
        printOffer(offers[i]);
    }
}

void saveOfferToFile(std::ofstream& file, const Offer& offer) {
    file.write((const char*) offer.companyName, MAX_NAME_SIZE);
    file.write((const char*) &offer.coworkersCount, sizeof(int));
    file.write((const char*) &offer.paidVacationDays, sizeof(int));
    file.write((const char*) &offer.salary, sizeof(long long));
}

void saveOffersToFile(std::ofstream& file, const Offer* offers, const int offersCount) {
    for (int i = 0; i < offersCount; ++i) {
        saveOfferToFile(file, offers[i]);
    }
}

void readOffer(Offer& offer) {
    std::cout << "Company name: " << std::endl;
    std::cin.ignore();
    std::cin.getline(offer.companyName, MAX_NAME_SIZE);

    std::cout << "Coworkers: " << std::endl;
    std::cin >> offer.coworkersCount;

    std::cout << "Paid vacation days: " << std::endl;
    std::cin >> offer.paidVacationDays;

    std::cout << "Salary: " << std::endl;
    std::cin >> offer.salary;
}

/*
int getOutputFileSize(std::ofstream& file) {
    int curPosition = file.tellp();
    file.seekp(0, std::ios::end);
    int size = file.tellp();
    file.seekp(curPosition, std::ios::beg);

    return size;
}
*/

int getInputFileSize(std::ifstream& file) {
    int curPosition = file.tellg();
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.seekg(curPosition, std::ios::beg);

    return size;
}

void readOfferFromFile(std::ifstream& file, Offer& offer) {
    file.read((char*) offer.companyName, MAX_NAME_SIZE);
    file.read((char*) &offer.coworkersCount, sizeof(int));
    file.read((char*) &offer.paidVacationDays, sizeof(int));
    file.read((char*) &offer.salary, sizeof(long long));
}

Offer* readOffersFromFile(std::ifstream& file, int& offersCount) {
    int fileSize = getInputFileSize(file);
    offersCount = fileSize / sizeof(Offer);
    if (fileSize != 0)
        offersCount++;

    Offer* offers = new Offer[offersCount];

    for (int i = 0; i < offersCount; ++i) {
        readOfferFromFile(file, offers[i]);
    }

    return offers;
}

Offer* readAndSaveOffers(int& n) {
    std::ifstream in(FILE_NAME, std::ios::binary);
    if (!in.is_open())
        return nullptr;

    Offer* offers = readOffersFromFile(in, n);

    in.close();

    int newOffersCount = 0;
    std::cout << "Enter offers count to add: " << std::endl;
    std::cin >> newOffersCount;

    if (newOffersCount == 0)
        return offers;

    for (int i = n; i < n + newOffersCount; ++i) {
        Offer newOffer{};
        readOffer(newOffer);
        offers[i] = newOffer;
    }

    {
        std::ofstream out(FILE_NAME, std::ios::ate | std::ios::binary);

        n += newOffersCount;

        if (!out.is_open()) {
            return nullptr;
        }

        saveOffersToFile(out, offers, n);

        out.close();
    }

    return offers;
}

void filterOffers(const char* filePath, long long minSalary) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in.is_open())
        return;

    int offersCount = 0;
    Offer* offers = readOffersFromFile(in, offersCount);

    for (int i = 0; i < offersCount; ++i) {
        Offer& offer = offers[i];

        if (offer.salary < minSalary)
            continue;

        printOffer(offer);
    }

    in.close();
    delete[] offers;
}

int getStrLen(const char* str) {
    int ctr = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        ctr++;
    return ctr;
}

bool areStrEqual(const char* str1, const char* str2) {
    if (getStrLen(str1) != getStrLen(str2))
        return false;

    for (int i = 0; str1[i] != '\0'; ++i)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int existOffer(const char* filePath, const char* name) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in.is_open())
        return -1;

    int offersCount = 0;
    Offer* offers = readOffersFromFile(in, offersCount);

    in.close();

    bool doesExist = false;
    for (int i = 0; i < offersCount; ++i) {
        if (areStrEqual(offers[i].companyName, name)) {
            doesExist = true;
            break;
        }
    }

    delete[] offers;

    return doesExist;
}

void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
    std::ifstream in(filePath, std::ios::binary);

    if (!in.is_open())
        return;

    int offersCount = 0;
    Offer* offers = readOffersFromFile(in, offersCount);

    in.close();

    std::ofstream out(PERFECT_FILE_NAME, std::ios::binary);

    if(!out.is_open())
        return;

    for (int i = 0; i < offersCount; ++i) {
        Offer& offer = offers[i];

        if (offer.coworkersCount > maxCoworkers || offer.paidVacationDays < minVacancyDays || offer.salary < minSalary)
            continue;

        saveOfferToFile(out, offer);
    }

    out.close();
    delete[] offers;
}

char getCommand() {
    char command;
    std::cout << "Add offer- a" << std::endl;
    std::cout << "Show all offers- i" << std::endl;
    std::cout << "Search company- s" << std::endl;
    std::cout << "Minimal salary- f" << std::endl;
    std::cout << "Exit- q" << std::endl;
    std::cout << "Pick command:";

    std::cin >> command;

    return command;
}

int runProgram() {

    int offersCount;
    Offer* offers = readAndSaveOffers(offersCount);

    if (offers == nullptr)
        return -1;

    char command;
    while (true) {
        command = getCommand();

        if (command == 'a') {
            Offer newOffer{};
            readOffer(newOffer);
            offers[offersCount++] = newOffer;
        }
        else if (command == 'i') {
            printOffers(offers, offersCount);
        }
        else if (command == 's') {
            char searchName[MAX_NAME_SIZE];
            std::cout << "Enter name to search: " << std::endl;
            std::cin.ignore();
            std::cin.getline(searchName, MAX_NAME_SIZE);

            bool doesExist = existOffer(FILE_NAME, searchName);

            if (doesExist) std::cout << "Yes, there is an offer from ";
            else std::cout << "No, there isn't offer from ";
            std::cout << searchName << std::endl;
        }
        else if (command == 'f') {
            long long neededSalary;
            std::cout << "Enter salary: " << std::endl;
            std::cin >> neededSalary;

            filterOffers(FILE_NAME, neededSalary);
        }
        else if (command == 'q') break;

        std::cout << std::endl;
    }

    std::ofstream out(FILE_NAME,  std::ios::binary);

    if (!out.is_open()) {
        return -1;
    }

    saveOffersToFile(out, offers, offersCount);

    out.close();

    return 0;
}

int main() {

    return runProgram();
}