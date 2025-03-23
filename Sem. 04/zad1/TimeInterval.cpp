#include "TimeInterval.h"
#include <cmath>
#include <algorithm>

TimeInterval::TimeInterval() : a(0), b(0) {}

TimeInterval::TimeInterval(int a, int b)
{
    this->a = (a <= b) ? a : b;
    this->b = (a <= b) ? b : a;
}

unsigned TimeInterval::length() const
{
    return (b - a);
}

bool TimeInterval::isInInterval(int x) const
{
    return (a <= x && x <= b);
}

bool TimeInterval::isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    int sqrtOfNum = static_cast<int>(sqrt(num));
    for (int i = 3; i <= sqrtOfNum; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

unsigned TimeInterval::primeNumIn() const
{
    unsigned countPrime = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            ++countPrime;
    }
    return countPrime;
}

bool TimeInterval::isPalindrome(int num)
{
    if (num < 0)
        return false;
    if (num / 10 == 0)
        return true;

    int original = num;
    int reversed = 0;
    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

unsigned TimeInterval::palindromeNumIn() const
{
    unsigned countPalindromes = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPalindrome(i))
            ++countPalindromes;
    }
    return countPalindromes;
}

bool TimeInterval::isUniqueDigits(int num)
{
    if (num < 0)
        num = -num;

    if (num < 10)
        return true;

    unsigned short digitFlags = 0;

    while (num != 0)
    {
        int digit = num % 10;
        unsigned short mask = 1 << digit;
        if (digitFlags & mask)
            return false;
        digitFlags |= mask;
        num /= 10;
    }
    return true;
}

unsigned TimeInterval::uniqueDigitsNumIn() const
{
    unsigned countUnique = 0;
    for (int i = a; i <= b; i++)
    {
        if (isUniqueDigits(i))
            ++countUnique;
    }
    return countUnique;
}

bool TimeInterval::isPowerOfTwo(int num)
{
    if (num <= 0)
        return false;
    return (num & (num - 1)) == 0;
}

bool TimeInterval::isIntervalPowerTwo() const
{
    return isPowerOfTwo(a) && isPowerOfTwo(b);
}

bool TimeInterval::isSubInterval(const TimeInterval& time) const
{
    return (a <= time.a && time.b <= b);
}

TimeInterval TimeInterval::intersectionWith(const TimeInterval& time) const
{
    if (time.b < a || time.a > b)
        return { 0, 0 };
    return { std::max(a, time.a), std::min(b, time.b) };
}
