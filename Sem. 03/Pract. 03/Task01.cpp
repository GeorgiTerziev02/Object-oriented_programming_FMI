#include <iostream>
#include <fstream>

const char* OUTPUT_FILE_NAME = "sorted.bin";
const char* FILE_NAME = "orders.txt";

const int MAX_SIZE = 25;

struct Order {
    char address[MAX_SIZE];
    double price;
};

void saveOrder(std::ofstream& file, const Order& order) {
    file.write((const char*) order.address, MAX_SIZE);
    file.write((const char*) &order.price, sizeof(double));
}

void saveOrdersToFile(std::ofstream& file, const Order* orders, const int ordersCount) {
    file.write((const char*) &ordersCount, sizeof(int));

    for (int i = 0; i < ordersCount; ++i) {
        saveOrder(file, orders[i]);
    }
}

void saveOrderToCSV(std::ofstream& file, const Order& order) {
    file << order.address << ", " << order.price << std::endl;
}

void saveOrdersToTxtCSV(std::ofstream& file, const Order* orders, const int ordersCount) {
    file << "address, price" << std::endl;

    for (int i = 0; i < ordersCount; ++i) {
        saveOrderToCSV(file, orders[i]);
    }
}

void readOrder(std::ifstream& file, Order& order) {
    file.read((char*) order.address, MAX_SIZE);
    file.read((char*) &order.price, sizeof(double));
}

void readOrdersFromFile(std::ifstream& file, Order* orders, int& ordersCount) {
    file.read((char*) &ordersCount, sizeof(int));

    for (int i = 0; i < ordersCount; ++i) {
        readOrder(file, orders[i]);
    }
}

void printOrders(const Order* orders, const int ordersCount) {
    for (int i = 0; i < ordersCount; ++i) {
        std::cout << orders[i].address << ", " << orders[i].price << std::endl;
    }
}

void swap(Order& order1, Order& order2) {
    Order temp = order1;
    order1 = order2;
    order2 = temp;
}

char getLowerCase(const char ch) {
    int chIntValue = (int) ch;
    if (65 <= chIntValue && chIntValue <= 90)
        chIntValue += 32;

    return (char) chIntValue;
}

bool compareLexicographically(const char* str1, const char* str2) {
    for (int i = 0; str1[i] != '\0'; ++i) {
        if (str2[i] == '\0')
            return false;

        char ch1 = getLowerCase(str1[i]);
        char ch2 = getLowerCase(str2[i]);

        if ((int) ch1 == (int) ch2)
            continue;

        return (int) ch1 < (int) ch2;
    }

    return true;
}

void sortOrders(Order* orders, const int ordersCount) {
    for (int i = 0; i < ordersCount; ++i) {
        int minimalIndex = i;

        for (int y = i + 1; y < ordersCount; ++y) {
            if (!compareLexicographically(orders[minimalIndex].address, orders[y].address)) {
                minimalIndex = y;
            }
        }

        if (minimalIndex != i) {
            swap(orders[i], orders[minimalIndex]);
        }
    }
}

void addOrder(Order* orders, int& orderCount) {
    Order newOrder{};

    std::cout << "Address: " << std::endl;
    std::cin.ignore();
    std::cin.getline(newOrder.address, MAX_SIZE, '\n');
    std::cout << std::endl;

    std::cout << "Price: " << std::endl;
    std::cin >> newOrder.price;
    std::cout << std::endl;

    orders[orderCount++] = newOrder;
}

char getCommand() {
    char command;
    std::cout << "Add order- a" << std::endl;
    std::cout << "Save to file- s" << std::endl;
    std::cout << "Print orders- p" << std::endl;
    std::cout << "Exit- q" << std::endl;
    std::cout << "Pick command:";

    std::cin >> command;

    return command;
}

int runProgram() {
    int ordersCount;
    Order orders[1024] = {};

    {
        std::ifstream in(OUTPUT_FILE_NAME, std::ios::binary);

        if (!in.is_open()) {
            return -1;
        }

        readOrdersFromFile(in, orders, ordersCount);

        in.close();
    }

    std::ofstream ordersFile(FILE_NAME);
    if (!ordersFile.is_open())
        return -1;

    char command;
    while (true) {
        command = getCommand();

        if (command == 'a') {
            addOrder(orders, ordersCount);
        }
        else if (command == 's') {
            sortOrders(orders, ordersCount);
            saveOrdersToTxtCSV(ordersFile, orders, ordersCount);
            std::cout << "Orders saved at: " << FILE_NAME << std::endl;
        }
        else if (command == 'p') {
            printOrders(orders, ordersCount);
        }
        else if (command == 'q') {
            break;
        }
        else std::cout << "Enter a valid command!" << std::endl;

        std::cout << std::endl;
    }

    ordersFile.close();

    {
        std::ofstream out(OUTPUT_FILE_NAME, std::ios::binary);

        if (!out.is_open()) {
            return -1;
        }

        sortOrders(orders, ordersCount);
        saveOrdersToFile(out, orders, ordersCount);

        out.close();
    }

    return 0;
}

int main() {

    return runProgram();
}