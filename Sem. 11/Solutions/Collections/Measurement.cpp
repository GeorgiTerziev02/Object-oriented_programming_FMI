
#include "NormalCollection.h"
#include "SortedCollection.h"

#include <iostream>
#include "Collection.h"
#include <chrono>

void testPerformance(Collection& collection) {
    std::srand(std::time(nullptr));

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 10000; ++i) {
        int randomNumber = std::rand() % 10000 + 1;
        collection.add(randomNumber);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = end - start;
    std::cout << "Time taken to add 10000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 5000; ++i) {
        int randomNumber = std::rand() % 10000 + 1;
        collection.remove(randomNumber);
    }
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to remove 5000 random elements: " << elapsedTime.count() << " seconds" << std::endl;

    int randomQueryNumber = std::rand() % 10000 + 1;
    start = std::chrono::steady_clock::now();
    unsigned count = collection.count(randomQueryNumber);
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to count occurrences of random element: " << elapsedTime.count() << " seconds" << std::endl;

    randomQueryNumber = std::rand() % 10000 + 1;
    start = std::chrono::steady_clock::now();
    bool contains = collection.contains(randomQueryNumber);
    end = std::chrono::steady_clock::now();
    elapsedTime = end - start;
    std::cout << "Time taken to check if random element is contained: " << elapsedTime.count() << " seconds" << std::endl;
}

int main() {
    NormalCollection normalCollection;
    SortedCollection sortedCollection;

    std::cout << "NormalCollection performance:" << std::endl;
    testPerformance(normalCollection);

    std::cout << std::endl;

    std::cout << "SortedCollection performance:" << std::endl;
    testPerformance(sortedCollection);

    return 0;
}