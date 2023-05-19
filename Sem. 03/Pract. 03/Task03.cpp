#include <iostream>
#include <fstream>

struct PizzaDelivery {
    char customerName[50];
    char address[100];
    char phone[20];
    char pizzaType[20];
    char pizzaSize[20];
    int numberOfPizzas;
    double price;
};

void inputPizzaDelivery(PizzaDelivery &pizza) {
    std::cout << "Enter customer name: ";
    std::cin.getline(pizza.customerName, 50);

    std::cout << "Enter address: ";
    std::cin.getline(pizza.address, 100);

    std::cout << "Enter phone number: ";
    std::cin.getline(pizza.phone, 20);

    std::cout << "Enter pizza type: ";
    std::cin.getline(pizza.pizzaType, 20);

    std::cout << "Enter pizza size: ";
    std::cin.getline(pizza.pizzaSize, 20);

    std::cout << "Enter number of pizzas: ";
    std::cin >> pizza.numberOfPizzas;

    std::cout << "Enter price: ";
    std::cin >> pizza.price;
}

void outputPizzaDelivery(PizzaDelivery &pizza) {
    std::cout << "Customer name: " << pizza.customerName << std::endl;
    std::cout << "Address: " << pizza.address << std::endl;
    std::cout << "Phone number: " << pizza.phone << std::endl;
    std::cout << "Pizza type: " << pizza.pizzaType << std::endl;
    std::cout << "Pizza size: " << pizza.pizzaSize << std::endl;
    std::cout << "Number of pizzas: " << pizza.numberOfPizzas << std::endl;
    std::cout << "Price: " << pizza.price << std::endl;
    std::cout << std::endl;
}

int mystrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}


void writeDeliveryToFile(const PizzaDelivery &delivery, const char *fileName) {
    std::ofstream file(fileName, std::ios::binary | std::ios::app);
    if (!file) {
        std::cout << "Error: Failed to open file \"" << fileName << "\" for writing." << std::endl;
        return;
    }

    file.write((char *) &delivery, sizeof(PizzaDelivery));

    file.close();
}

void readDeliveryFromFile(PizzaDelivery &delivery, const char *filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cout << "Error: could not open file '" << filename << "' for reading." << std::endl;
        return;
    }

    inFile.read((char *) &delivery, sizeof(PizzaDelivery));

    inFile.close();ale
}

void outputPizzaDeliveriesFromFile(const char *filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) {
        std::cout << "Error: could not open file '" << filename << "' for reading." << std::endl;
        return;
    }

    PizzaDelivery pizza;
    while (inFile.read((char *) &pizza, sizeof(pizza))) {
        outputPizzaDelivery(pizza);
    }

    inFile.close();
}

PizzaDelivery* readPizzaDeliveriesFromFile(const char* filename, int& count) {
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile) {
        std::cout << "Error: could not open file '" << filename << "' for reading." << std::endl;
    }

    // Determine the number of structs in the file
    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    count = fileSize / sizeof(PizzaDelivery);

    // Allocate memory for the structs
    PizzaDelivery* deliveries = new PizzaDelivery[count];

    // Read the structs from the file
    inputFile.seekg(0, std::ios::beg);
    inputFile.read((char *)deliveries, count * sizeof(PizzaDelivery));

    inputFile.close();

    return deliveries;
}

void sortPizzaDeliveriesByAddress(PizzaDelivery* deliveries, int count) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < count - 1; ++i) {
            if (mystrcmp(deliveries[i].address, deliveries[i + 1].address) > 0) {
                PizzaDelivery temp = deliveries[i];
                deliveries[i] = deliveries[i + 1];
                deliveries[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void readSortAndStorePizzaDeliveries(const char* sourceFileName, const char* sortedFileName) {
    int count = 0;
    PizzaDelivery* pizzaDeliveries = readPizzaDeliveriesFromFile(sourceFileName, count);
    sortPizzaDeliveriesByAddress(pizzaDeliveries, count);
    for (int i = 0; i < count; i++) {
        writeDeliveryToFile(pizzaDeliveries[i], sortedFileName);
    }

    delete[] pizzaDeliveries;
}

int main() {
    PizzaDelivery currentPizzaDelivery;
    int choice = -1;
    while (choice != 0) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Input Pizza Delivery" << std::endl;
        std::cout << "2. List Pizza Deliveries" << std::endl;
        std::cout << "3. Sort Pizza Deliveries" << std::endl;
        std::cout << "4. Sort Pizza Deliveries" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                inputPizzaDelivery(currentPizzaDelivery);
                writeDeliveryToFile(currentPizzaDelivery, "delivery.bin");
                break;
            case 2:
                outputPizzaDeliveriesFromFile("delivery.bin");
                break;
            case 3:
                readSortAndStorePizzaDeliveries("delivery.bin", "sortedDelivery.bin");
                break;
            case 4:
                outputPizzaDeliveriesFromFile("sortedDelivery.bin");
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }

    return 0;
}