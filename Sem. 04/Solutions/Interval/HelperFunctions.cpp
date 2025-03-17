#include "HelperFunctions.h"

#include <cmath>

namespace {
    // anonymous namespace
    // you cant access this variables inside from another file
    constexpr int DIGITS_COUNT = 10;
}

bool HelperFunctions::isPrime(int number) {
    if (number == 2) {
        return true;
    }
    if (number < 2 || number % 2 == 0) {
        return false;
    }

    double sqrtN = sqrt(number);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int HelperFunctions::reverseNumber(int number) {
    int reversed = 0;
    while (number != 0) {
        (reversed *= 10) += number % 10;
        number /= 10;
    }

    return reversed;
}

bool HelperFunctions::isPalindrome(int number) {
    return number == reverseNumber(number);
}

bool HelperFunctions::isPowOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & n - 1) == 0;
}

bool HelperFunctions::containsOnlyDistinctDigits(int number) {
    bool digits[DIGITS_COUNT] = {};
    while (number != 0) {
        int lastDigit = number % 10;
        if (digits[lastDigit]) {
            return false;
        }
        digits[lastDigit] = true;
        number /= 10;
    }
    return true;
}