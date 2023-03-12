#include <iostream>
#include <fstream>
#include <cstring>

const size_t MAX_ADDRESS_LENGTH = 25;
const size_t MAX_ARRAY_SIZE = 100;

struct PizzaOrder{
    double price;
    char address[MAX_ADDRESS_LENGTH];
};

void copyArrays(const char from[MAX_ADDRESS_LENGTH], char to[MAX_ADDRESS_LENGTH]){
    int index = 0;
    while(from[index] != '\0'){
        to[index] = from[index];
        index++;
    }
    to[index] = '\0';
}

void initPizzaOrder(PizzaOrder& pizzaOrder, const double price, const char* address){
    pizzaOrder.price = price;
    copyArrays(address, pizzaOrder.address);
}

size_t getFileSize(std::ifstream& f){
    size_t current = f.tellg();
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(current);
    return size;
}

void saveOrdersToFile(const PizzaOrder* orders, size_t countOfOrders, std::ofstream& file){
    file.write((const char*) orders, countOfOrders * sizeof(PizzaOrder));
}

void readOrdersFromFile(PizzaOrder*& order, size_t& countOfOrders, std::ifstream& f){ // here PizzaOrder*& is needed because the pointer should be overwritten
    size_t sizeOfFile = getFileSize(f);                                            // and used outside the function
    countOfOrders = sizeOfFile  / sizeof(PizzaOrder);
    order = new PizzaOrder[countOfOrders];
    f.read((char *)order, sizeOfFile);
}

void swap(PizzaOrder* order1, PizzaOrder* order2){
    PizzaOrder tmp = *order1;
    *order1 = *order2;
    *order2 = tmp;
}

int getLengthOfStr(const char *arr){
    int length=0;
    while(arr[length] != '\0'){
        length++;
    }
    return length;
}

int min(int a, int b){
    return a <=b ? a : b;
}

int myStrComp(char *str1, char* str2){
    int str1Length = getLengthOfStr(str1);
    int str2Length = getLengthOfStr(str2);
    int shorter = min(str1Length, str2Length);
    for (int i = 0; i < shorter; ++i) {
        if(str1[i] > str2[i]){
            return 1;
        } else if(str1[i] < str2[i]){
            return -1;
        }
    }
    if(str1Length == str2Length){
        return 0;
    }
    if(str1Length == shorter){
        return -1;
    }
    if(str2Length == shorter){
        return 1;
    }
}

void sortOrders(PizzaOrder* orders, size_t countOfOrders){
    int min_Idx;
    for (int i = 0; i < countOfOrders - 1; ++i) {
        min_Idx = i;
        for (int j = i+1; j < countOfOrders; ++j) {
            int result = myStrComp(orders[j].address, orders[min_Idx].address);
            if(result < 0){
                min_Idx = j;
            }
        }
        if(min_Idx!= i){
            swap(&orders[min_Idx],&orders[i]);
        }
    }
}

int main() {
    {
        size_t countOfOrders;
        std::cin >> countOfOrders;
        double price = 0;
        char address[MAX_ADDRESS_LENGTH];

        PizzaOrder *orders = new PizzaOrder[countOfOrders];
        for (int i = 0; i < countOfOrders; ++i) {
            std::cin.ignore(); // needed for clearing buffer of cin
            std::cin.getline(address, MAX_ADDRESS_LENGTH);
            std::cin >> price;
            initPizzaOrder(orders[i], price, address);
        }

        std::ofstream f("pizzaOrderResult.dat", std::ios::binary);
        if (!f.is_open()) {
            std::cout << "Error while opening the file!" << std::endl;
            delete[] orders; //!
            return -1;
        }
        saveOrdersToFile(orders, countOfOrders, f);
        delete[] orders;
        f.close();
    }
    {
        PizzaOrder *extractedOrders;
        size_t count;
        std::ifstream file("pizzaOrderResult.dat", std::ios::binary);

        if (!file.is_open()) {
            std::cout << "Error while opening the file!" << std::endl;
            return -1;
        }
        readOrdersFromFile(extractedOrders, count, file);
        for (int i = 0; i < count; i++) {
            std::cout << "Price: " << extractedOrders[i].price << ", address: " << extractedOrders[i].address
                      << std::endl;
        }
        file.close();

        sortOrders(extractedOrders, count);
        std::ofstream sortedOutFile("pizzaOrderSorted.dat", std::ios::binary);
        if (!sortedOutFile.is_open()) {
            std::cout << "Error while opening the file!" << std::endl;
            delete[] extractedOrders;
            return -1;
        }
        saveOrdersToFile(extractedOrders, count, sortedOutFile);
        sortedOutFile.close();
        delete[] extractedOrders;
    }
    {
        PizzaOrder* sortedOrders;
        size_t countOfSorted;
        std::ifstream sortedInFile("pizzaOrderSorted.dat", std::ios::binary);

        if (!sortedInFile.is_open()) {
            std::cout << "Error while opening the file!" << std::endl;
            return -1;
        }
        readOrdersFromFile(sortedOrders, countOfSorted, sortedInFile);
        for (int i = 0; i < countOfSorted; i++) {
            std::cout << "Price: " << sortedOrders[i].price << ", address: " << sortedOrders[i].address
                      << std::endl;
        }
        delete[] sortedOrders;
    }
}
