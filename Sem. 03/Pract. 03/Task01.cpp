#include <iostream>
#include <fstream>

const char* UNSORTED_FILE_NAME = "unsortedDeliveries.bin";
const char* SORTED_FILE_NAME = "sortedDeliveries.bin";
const char* ERROR_MESSAGE = "Error";

const int ADDRESS_MAX_LENGTH = 25;

struct Delivery {
    double price;
    char address[ADDRESS_MAX_LENGTH];
};

int stringLength(const char* str) {
    int length = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        length++;
    }

    return length;
}

int minStringLength(const char* str1, const char* str2) {
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);

    return length1 < length2 ? length1 : length2;
}

bool isSecondStringLarger(const char* str1, const char* str2) {
    int minLength = minStringLength(str1, str2);
    int length2 = stringLength(str2);

    for (int i = 0; i < minLength; ++i) {
        if (str1[i] == str2[i]) {
            continue;
        }

        return str1[i] < str2[i];
    }

    if(length2 > minLength) {
        return true;
    }

    return false;
}

size_t getFileSize(std::ifstream& in) {

    size_t currentPosition = in.tellg();
    in.seekg(0, std::ios::end);
    size_t fileSize = in.tellg();
    in.seekg(currentPosition, std::ios::beg);

    return fileSize;
}

namespace deliveryFunctions {

    void assignAddress(Delivery& delivery, const char* address) {
        int length = stringLength(address) + 1;

        for (int i = 0; i < length; ++i) {
            delivery.address[i] = address[i];
        }
    }

    void swapDeliveries(Delivery& delivery1, Delivery& delivery2) {
        Delivery temp = delivery1;
        delivery1 = delivery2;
        delivery2 = temp;
    }

    void selectionSort(Delivery* deliveryArray, size_t arraySize) {
        for (int i = 0; i < arraySize - 1; ++i) {
            int minIndex = i;

            for (int j = i + 1; j < arraySize; ++j) {

                if (isSecondStringLarger(deliveryArray[j].address, deliveryArray[minIndex].address)) {
                    minIndex = j;
                }

            }

            if (minIndex != i) {
                swapDeliveries(deliveryArray[i], deliveryArray[minIndex]);
            }
        }
    }

    void initializeDelivery(Delivery& delivery, double price, const char* address) {
        delivery.price = price;
        assignAddress(delivery, address);
    }

    void writeDeliveryArrayToFile(std::ofstream& out, const Delivery* deliveryArray, size_t arraySize) {
        out.write((const char*)deliveryArray, sizeof(Delivery) * arraySize);
    }

    void readDeliveryArrayFromFile(std::ifstream& in, Delivery*& deliveryArray, size_t& arraySize) {
        arraySize = getFileSize(in) / sizeof(Delivery);
        deliveryArray = new Delivery[arraySize];
        in.read((char*)deliveryArray, sizeof(Delivery) * arraySize);
    }

    void printDeliveryArray(const Delivery* deliveryArray, size_t arraySize) {

        for (int i = 0; i < arraySize; ++i) {
            std::cout << deliveryArray[i].price << " " << deliveryArray[i].address << '\n';
        }
    }

}

int main() {
    size_t n = 0;
    double price = 0;
    char* address = new char[ADDRESS_MAX_LENGTH];

    Delivery* deliveryArrayFromUnsortedFile = nullptr;
    size_t unsortedArraySize = 0;
    Delivery* deliveryArrayFromSortedFile = nullptr;
    size_t sortedArraySize = 0;

    std::cin >> n;

    Delivery* deliveries = new Delivery[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> price;
        std::cin.ignore();
        std::cin.getline(address, ADDRESS_MAX_LENGTH);
        deliveryFunctions::initializeDelivery(deliveries[i], price, address);
    }

    using namespace deliveryFunctions;

    std::ofstream out1(UNSORTED_FILE_NAME, std::ios::binary);

    if (!out1.is_open()) {
        std::cerr << ERROR_MESSAGE;
        return 1;
    }

    writeDeliveryArrayToFile(out1, deliveries, n);

    out1.close();

    std::ofstream out2(SORTED_FILE_NAME, std::ios::binary);

    if (!out2.is_open()) {
        std::cerr << ERROR_MESSAGE;
        return 1;
    }

    selectionSort(deliveries, n);
    writeDeliveryArrayToFile(out2, deliveries, n);

    out2.close();

    std::ifstream in1(UNSORTED_FILE_NAME, std::ios::binary);

    if (!in1.is_open()) {
        std::cerr << ERROR_MESSAGE;
        return 1;
    }

    readDeliveryArrayFromFile(in1, deliveryArrayFromUnsortedFile, unsortedArraySize);

    in1.close();

    std::ifstream in2(SORTED_FILE_NAME, std::ios::binary);

    if (!in2.is_open()) {
        std::cerr << ERROR_MESSAGE;
        return 1;
    }

    readDeliveryArrayFromFile(in2, deliveryArrayFromSortedFile, sortedArraySize);

    in2.close();

    printDeliveryArray(deliveryArrayFromUnsortedFile, unsortedArraySize);
    printDeliveryArray(deliveryArrayFromSortedFile, sortedArraySize);

    delete[] deliveries;
    delete[] address;
    delete[] deliveryArrayFromUnsortedFile;
    delete[] deliveryArrayFromSortedFile;

    return 0;
}
