#include "Time.h"

void stableSortTimes(Time* arr, size_t arrSize) {
    // insertion sort
    // https://visualgo.net/en/sorting
    for (int i = 1; i < arrSize; i++) {
        Time temp = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j].compare(temp) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    constexpr size_t ARR_SIZE = 10;
    Time times[ARR_SIZE] = { Time(11, 30, 0), Time(12, 44, 29), Time(), Time(17, 15, 23), Time(23, 60, 0), Time(3, 14, 15), Time(2, 71, 82), Time(21, 22, 3), Time(17, 15, 23), Time(7, 31, 43) };
    stableSortTimes(times, ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++) {
        times[i].print();
    }
}