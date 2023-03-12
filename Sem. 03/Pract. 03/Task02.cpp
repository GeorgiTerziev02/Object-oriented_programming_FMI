#include <iostream>
#include <fstream>
#include <sstream>

const size_t NAME_MAX_LENGTH = 25;
const size_t FILE_PATH_MAX_LENGTH = 100;
const size_t INPUT_BUFFER_SIZE = 255;

struct JobAd{
    char name[NAME_MAX_LENGTH];
    unsigned countOfDevs;
    unsigned holidayDays;
    long long sum;
};

void copyArrays(const char from[NAME_MAX_LENGTH], char to[NAME_MAX_LENGTH]){
    int index = 0;
    while(from[index] != '\0'){
        to[index] = from[index];
        index++;
    }
    to[index] = '\0';
}


void saveJobAdsToFile(const JobAd* jobAds, size_t count, std::ofstream& file){
    file.write((const char *)jobAds, count * sizeof(JobAd));
}

void initJobAd(JobAd& jobAd,const char* name, const unsigned countOfDevs,const unsigned holidayDays,const long long sum){
    copyArrays(name, jobAd.name);
    jobAd.countOfDevs = countOfDevs;
    jobAd.holidayDays = holidayDays;
    jobAd.sum = sum;
}

size_t getFileSize(std::ifstream& f){
    size_t current = f.tellg();
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(current);
    return size;
}

void readJobAdsFromFile(JobAd*& order, size_t& countOfAds, std::ifstream& f){ // here PizzaOrder*& is needed because the pointer should be overwritten
    size_t sizeOfFile = getFileSize(f);                                            // and used outside the function
    countOfAds = sizeOfFile  / sizeof(JobAd);
    order = new JobAd[countOfAds];
    f.read((char *)order, sizeOfFile);
}

void readQueries(int n, const char* filePath){
    std::ofstream f(filePath, std::ios::app | std::ios::binary);
    if(!f.is_open()){
        std::cerr << "Error while opening the file!";
        return;
    }
    JobAd* jobAds = new JobAd[n];
    char *name = new char[NAME_MAX_LENGTH];
    unsigned countOfDevs;
    unsigned  holidayDays;
    long long sum;
    for (int i = 0; i < n; ++i) {
        std::cin.ignore();
        std::cout << "Input job ad name: ";
        std::cin.getline(name, NAME_MAX_LENGTH);
        std::cout << "Input count of co-working developers: ";
        std::cin >> countOfDevs;
        std::cout << "Input count holiday days: ";
        std::cin >> holidayDays;
        std::cout << "Input salary for the project: ";
        std::cin >> sum;
        initJobAd(jobAds[i], name, countOfDevs, holidayDays, sum);
    }
    saveJobAdsToFile(jobAds, n, f);
    delete[] name;
    delete[] jobAds;
}

void printJobAdd(const JobAd& jobAd){
    std::cout << "Name: " << jobAd.name << " , colleagues: " << jobAd.countOfDevs << " Holidays: " << jobAd.holidayDays << " salary: "
              << jobAd.sum << std::endl;
}

bool jobAdFilterCondition(const JobAd& jobAd, long long minSalary){
    if(jobAd.sum >= minSalary){
        return true;
    }
    return false;
}

void filterOffers(const char* filePath, long long minSalary){
    std::ifstream in(filePath, std::ios::binary);
    if(!in.is_open()){
        std::cerr << "Error while opening the file!";
        return;
    }
    JobAd* jobAds;
    size_t countOfAds;
    readJobAdsFromFile(jobAds, countOfAds, in);
    std::cout << "Filtered job ads: " << std::endl;
    for (int i = 0; i < countOfAds; ++i) {
            if(jobAdFilterCondition(jobAds[i], minSalary)){
                printJobAdd(jobAds[i]);
            }
    }
    delete[] jobAds;
    in.close();
}

int getLengthOfStr(const char *arr){
    int length=0;
    while(arr[length] != '\0'){
        length++;
    }
    return length;
}

bool namesEqual(const char* currentName, const char* searchedName){
    int name1Length = getLengthOfStr(currentName);
    int name2Length = getLengthOfStr(searchedName);
    if(name1Length != name2Length){
        return false;
    }
    int index = 0;
    while (currentName[index] != '\0'){
        if(currentName[index] != searchedName[index]){
            return false;
        }
        index++;
    }
    return true;
}

bool existOffer(const char* filePath, const char* name){
    std::ifstream in(filePath, std::ios::binary);
    if(!in.is_open()){
        std::cerr << "Error while opening the file!";
        return false;
    }
    JobAd* jobAds;
    size_t countOfAds;
    readJobAdsFromFile(jobAds, countOfAds, in);
    for (int i = 0; i < countOfAds; ++i) {
        if(namesEqual(jobAds[i].name, name)){
            delete[] jobAds;
            return true;
        }
    }
    delete[] jobAds;
    in.close();
    return false;
}

bool perfectJobFilterCondition(const JobAd& jobAd, int maxCoworkers, int minVacancyDays, int minSalary){
    if(jobAd.countOfDevs <= maxCoworkers && jobAd.holidayDays>=minVacancyDays && jobAd.sum>= minSalary){
        return true;
    }
    return false;
}

void perfectOffers(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary){
    std::ifstream in(filePath, std::ios::binary);
    if(!in.is_open()){
        std::cerr << "Error while opening the file!";
        return;
    }
    JobAd* jobAds;
    size_t countOfAds;
    readJobAdsFromFile(jobAds, countOfAds, in);
    std::cout << "Perfect job ads: ";
    for (int i = 0; i < countOfAds; ++i) {
        if(perfectJobFilterCondition(jobAds[i], maxCoworkers, minVacancyDays, minSalary)){
            printJobAdd(jobAds[i]);
        }
    }
    delete[] jobAds;
    in.close();
}

void listOffers(const char* filePath){
    std::ifstream in(filePath, std::ios::binary);
    if(!in.is_open()){
        std::cerr << "Error while opening the file!";
        return;
    }
    JobAd* jobAds;
    size_t countOfAds;
    readJobAdsFromFile(jobAds, countOfAds, in);
    for (int i = 0; i < countOfAds; ++i) {
        printJobAdd(jobAds[i]);
    }
    delete[] jobAds;
    in.close();
}

void mainMenu(const char* filePath){
    char command;
    while(true){
        std:: cout << "> ";
        std::cin >> command;
        switch (command) {
            case 'a':
                readQueries(1, filePath);
                break;
            case 'i':
                listOffers(filePath);
                break;
            case 's':
                std::cin.ignore();
                char name[NAME_MAX_LENGTH];
                std::cin.getline(name, NAME_MAX_LENGTH);
                if(existOffer(filePath, name)){
                    std::cout<< name << " exists!" << std::endl;
                }
                else{
                    std::cout<< name << " does not exist!" << std::endl;
                }
                break;
            case 'f':
                long long minSalary;
                std::cin >> minSalary;
                filterOffers(filePath, minSalary);
                break;
            case 'p':
                int maxCoworkers;
                int minVacancies;
                std::cin >> maxCoworkers >> minVacancies >> minSalary;
                perfectOffers(filePath, maxCoworkers, minVacancies, minSalary);
                break;
            case 'q':
                std::cout << "Exit!";
                return;
            default: std::cout << "Wrong input";
        }
    }
}

int main(){
    char filePath[FILE_PATH_MAX_LENGTH] = "jobAds.dat";
    std::cout << "Input count of queries: ";
    int n;
    std::cin >> n;
    readQueries(n, filePath);

    JobAd* jobAds;
    size_t countOfJobAds;
    std::ifstream in(filePath, std::ios::binary);

    if (!in.is_open()) {
        std::cout << "Error while opening the file!" << std::endl;
        return -1;
    }
    readJobAdsFromFile(jobAds, countOfJobAds, in);
    for (int i = 0; i < countOfJobAds; i++) {
        printJobAdd(jobAds[i]);
    }
    delete[] jobAds;
    in.close();

    mainMenu(filePath);

}