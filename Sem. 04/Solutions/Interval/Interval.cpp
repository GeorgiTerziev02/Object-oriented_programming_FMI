#include "Interval.h"

#include <iostream>
#include "HelperFunctions.h"

unsigned Interval::getNumbersMeetingConditionCound(bool(*predicate)(int)) const {
    unsigned counter = 0;
    for (int i = start; i <= end; i++) {
        if (predicate(i)) {
            counter++;
        }
    }

    return counter;
}
    
Interval::Interval() : Interval(0, 0) { }

Interval::Interval(int start, int end) : start(start), end(end) {
    if (start > end) {
        this->start = this->end = 0;
    }
}

int Interval::getStart() const {
    return start;
}

int Interval::getEnd() const {
    return end;
}

void Interval::setStart(int newValue) {
    if (newValue > end) {
        return;
    }
    start = newValue;
}

void Interval::setEnd(int newValue) {
    if (newValue < start) {
        return;
    }
    end = newValue;
}

unsigned Interval::getLength() const {
    return end - start + 1;
}

bool Interval::isInInterval(int value) const {
    return start <= value && value <= end;
}

void Interval::print() const {
    std::cout << start << " - " << end << std::endl;
}

unsigned Interval::getPrimeNumbersCount() const {
    return getNumbersMeetingConditionCound(HelperFunctions::isPrime);
}

unsigned Interval::getPalindromeNumbersCount() const {
    return getNumbersMeetingConditionCound(HelperFunctions::isPalindrome);
}

unsigned Interval::getOnlyUniqueDigitsNumbersCount() const {
    return getNumbersMeetingConditionCound(HelperFunctions::containsOnlyDistinctDigits);
}

bool Interval::areStartAndEndPowOfTwo() const {
    return HelperFunctions::isPowOfTwo(start) && HelperFunctions::isPowOfTwo(end);
}

Interval Interval::intersect(const Interval& other) const {
    int maxStart = std::max(start, other.start);
    int minEnd = std::min(end, other.end);
    
    return Interval(maxStart, minEnd);
}

bool Interval::isSubinterval(const Interval& other) const {
    return start <= other.getStart() && other.getEnd() <= end;
}