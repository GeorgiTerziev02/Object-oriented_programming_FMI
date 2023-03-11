#include <iostream>
#include <fstream>

const char* FILE_NAME = "jobOffers.bin";
const char* PERFECT_OFFERS_FILE_NAME = "perfectJobOffers.txt";
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

    void writeJobOfferToFile(size_t arraySize) {
        JobOffer jobOffer = {};

        std::ofstream out(FILE_NAME, std::ios::out | std::ios::app);

        if(!out.is_open()) {
            std::cerr << ERROR_MESSAGE;
            return;
        }

        for(int i = 0; i < arraySize; ++i) {
            std::cout << "Input job name (" << i + 1 << "):";
            std::cin.getline(jobOffer.name, MAX_NAME_LENGTH);

            std::cout << "Input job coworker count (" << i + 1 << "):";
            std::cin >> jobOffer.coworkerCount;

            std::cout << "Input job vacancy days (" << i + 1 << "):";
            std::cin >> jobOffer.vacancyDays;

            std::cout << "Input job salary (" << i + 1 << "):";
            std::cin >> jobOffer.salary;

            std::cin.ignore();

            out.write((const char*) &jobOffer, sizeof(JobOffer));
        }

        out.close();
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

            if(jobOffer.coworkerCount <= maxCoworkers && jobOffer.vacancyDays >= minVacancyDays && jobOffer.salary >= minSalary) {
                std::ofstream out(PERFECT_OFFERS_FILE_NAME);

                if(!out.is_open()) {
                    std::cerr << ERROR_MESSAGE;
                    return;
                }

                out << jobOffer.name << " is a perfect offer." << '\n';

                out.close();
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

    std::cout << "Input number of job offers:";
    std::cin >> n;

    std::cout << "Input preferred maximum number of coworkers:";
    std::cin >> maxCoworkers;

    std::cout << "Input preferred minimum vacancy days:";
    std::cin >> minVacancyDays;

    std::cout << "Input preferred minimum salary:";
    std::cin >> minSalary;

    std::cin.ignore();

    std::cout << "Input searched offer name:";
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
