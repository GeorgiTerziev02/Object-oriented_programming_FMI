#include <iostream>
#include <fstream>

const char* FILE_NAME = "jobOffers.bin";
const char* ERROR_MESSAGE = "Error";

const int MAX_NAME_LENGTH = 25;

struct JobOffer {
    char name[MAX_NAME_LENGTH];
    int coworkerCount;
    int vacancyDays;
    long long salary;
};

int stringLength(const char* string) {
    int length = 0;

    for (int i = 0; string[i] != '\0'; ++i) {
        length++;
    }

    return length;
}

bool areStringsEqual(const char* str1, const char* str2) {
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);

    if(length1 != length2) {
        return false;
    }

    for(int i = 0; i < length1; ++i) {

        if(str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

size_t getFileSize(std::ifstream& in) {

    size_t currentPosition = in.tellg();
    in.seekg(0, std::ios::end);
    size_t fileSize = in.tellg();
    in.seekg(currentPosition, std::ios::beg);

    return fileSize;
}

namespace jobOfferFunctions {

    void assignName(JobOffer& jobOffer, const char* name) {
        int length = stringLength(name) + 1;

        for (int i = 0; i < length; ++i) {
            jobOffer.name[i] = name[i];
        }
    }

    void initializeJobOffer(JobOffer& jobOffer, const char* name, const int programmerCount, const int days, const long long salary) {
        assignName(jobOffer, name);
        jobOffer.coworkerCount = programmerCount;
        jobOffer.vacancyDays = days;
        jobOffer.salary = salary;
    }

    void writeJobOfferToFile(const size_t arraySize) {
        JobOffer jobOffer = {};
        char* name = new char[MAX_NAME_LENGTH];
        int programmerCount = 0;
        int days = 0;
        long long salary = 0;

        std::ofstream out(FILE_NAME, std::ios::out | std::ios::app);

        if(!out.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        for(int i = 0; i < arraySize; ++i) {
            std::cin.getline(name, MAX_NAME_LENGTH);
            std::cin >> programmerCount;
            std::cin >> days;
            std::cin >> salary;
            std::cin.ignore();

            initializeJobOffer(jobOffer, name, programmerCount, days, salary);

            out.write((const char*) &jobOffer, sizeof(JobOffer));
        }

        out.close();

        delete[] name;
    }

    void filterOffers(const char* filePath, long long minSalary) {
        JobOffer jobOffer = {};

        std::ifstream in(filePath);

        if(!in.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        size_t fileSize = getFileSize(in);
        size_t numberOfJobOffers = fileSize / sizeof(JobOffer);

        for(int i = 0; i < numberOfJobOffers; ++i) {
            in.read((char*) &jobOffer, sizeof(JobOffer));

            if(jobOffer.salary >= minSalary) {
                std::cout << jobOffer.name << " meets the salary criterion." << std::endl;
            }
        }

        in.close();
    }

    bool existOffer(const char* filePath, const char* name) {
        JobOffer jobOffer = {};

        std::ifstream in(filePath);

        if(!in.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return false;
        }

        size_t fileSize = getFileSize(in);
        size_t numberOfJobOffers = fileSize / sizeof(JobOffer);

        for(int i = 0; i < numberOfJobOffers; ++i) {
            in.read((char*) &jobOffer, sizeof(JobOffer));

            if(areStringsEqual(jobOffer.name, name)) {
                in.close();
                return true;
            }
        }

        in.close();
        return false;
    }

    void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, long long minSalary) {
        JobOffer jobOffer = {};

        std::ifstream in(filePath);

        if(!in.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        size_t fileSize = getFileSize(in);
        size_t numberOfJobOffers = fileSize / sizeof(JobOffer);

        for(int i = 0; i < numberOfJobOffers; ++i) {
            in.read((char*) &jobOffer, sizeof(JobOffer));

            if(jobOffer.coworkerCount <= maxCoworkers) {
                if(jobOffer.vacancyDays >= minVacancyDays && jobOffer.salary >= minSalary) {
                    std::cout << jobOffer.name << " is a perfect offer." << std::endl;
                }
            }
        }

        in.close();
    }

    void deleteFileContent(const char* filePath) {
        std::ofstream out(filePath, std::ios::out | std::ios::trunc);

        out.close();
    }

}

int main(){
    size_t n = 0;
    int maxCoworkers = 0;
    int minVacancyDays = 0;
    long long minSalary = 0;
    char* searchedOffer = new char[MAX_NAME_LENGTH];

    std::cin >> n;
    std::cin >> maxCoworkers;
    std::cin >> minVacancyDays;
    std::cin >> minSalary;
    std::cin.ignore();
    std::cin.getline(searchedOffer, MAX_NAME_LENGTH);

    using namespace jobOfferFunctions;

    writeJobOfferToFile(n);

    filterOffers(FILE_NAME, minSalary);

    perfectOffer(FILE_NAME, maxCoworkers, minVacancyDays, minSalary);

    if(existOffer(FILE_NAME, searchedOffer)) {
        std::cout << searchedOffer << " is in offers.";
    } else {
        std::cout << searchedOffer << " isn't in offers.";
    }

    delete[] searchedOffer;

    return 0;
}
