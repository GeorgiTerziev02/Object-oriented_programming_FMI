#pragma once
class TimeInterval
{
public:
    TimeInterval();
    TimeInterval(int a, int b);

    unsigned length() const;
    bool isInInterval(int x) const;
    unsigned primeNumIn() const;
    unsigned palindromeNumIn() const;
    unsigned uniqueDigitsNumIn() const;

    bool isIntervalPowerTwo() const;
    bool isSubInterval(const TimeInterval& time) const;
    TimeInterval intersectionWith(const TimeInterval& time) const;


private:
    int a;
    int b;

    static bool isPrime(int num);
    static bool isPalindrome(int num);
    static bool isUniqueDigits(int num);
    static bool isPowerOfTwo(int num);
};
