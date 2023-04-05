#pragma once

class Interval {
private:
    int a, b;

    unsigned countNumbersMeetingCondition(bool(*pred)(int)) const;

public:
    Interval();
    Interval(int a, int b);

    int getA() const;
    int getB() const;

    void setA(int a);
    void setB(int b);

    unsigned getLength() const;
    bool isInInterval(int x) const;

    unsigned countPrimeNumbers() const;
    unsigned countPalidroms() const;
    unsigned countUniqueDigits() const;
    bool areStartAndEndPowOf2() const;
    Interval intersect(const Interval& other) const;
    bool subInterval(const Interval& other) const;
};