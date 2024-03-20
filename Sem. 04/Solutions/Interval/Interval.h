#pragma once

class Interval {
private:
    int start, end;

    unsigned getNumbersMeetingConditionCound(bool(*predicate)(int)) const;
public:
    Interval();
    Interval(int start, int end);

    int getStart() const;
    int getEnd() const;

    void setStart(int newValue);
    void setEnd(int newValue);

    unsigned getLength() const;
    bool isInInterval(int value) const;

    void print() const;

    unsigned getPrimeNumbersCount() const;
    unsigned getPalindromeNumbersCount() const;
    unsigned getOnlyUniqueDigitsNumbersCount() const;

    bool areStartAndEndPowOfTwo() const;
    Interval intersect(const Interval& other) const;

    bool isSubinterval(const Interval& other) const;
};