#include <iostream>

bool isPrime(int n)
{
    double temp = sqrt(n);
    for (size_t i = 2; i <= temp; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPalindorme(int n)
{
    int reversed = 0;

    while (n != 0)
    {
        int lastDigit = n % 10;
        (reversed *= 10) += lastDigit;
        n /= 10;
    }
    return n == reversed;
}

bool containsOnlyDistinctNumbers(int n)
{
    bool digits[10];
    for (size_t i = 0; i < 10; i++)
        digits[i] = false;

    while (n != 0)
    {
        int lastDigit = n % 10;
        if (digits[lastDigit])
            return false;
        digits[n % 10] = true;
        n /= 10;
    }
    return true;
}

class Interval {
private:
    int a, b;

    unsigned countNumbersMeetingCondition(bool(*pred)(int)) const;
public:
    Interval();
    Interval(int a, int b);

    int getA() const;
    int getB() const;

    void setA(int);
    void setB(int);

    unsigned getLength() const;
    bool isInInterval(int) const;

    // primenumbers
    unsigned countPrimeNumbers() const;
    // palindorms
    unsigned countPalidroms() const;
    // uniquedigits 
    unsigned countUniqueDigits() const;
     
    // startendpowof2
    bool areStartAndEndPowOf2() const;
    // intersec
    Interval intersec(const Interval& other) const;
    // subinterval
    bool subInterval(const Interval& other) const;
};

Interval::Interval() : Interval(0, 0) { }

Interval::Interval(int a, int b) {
    if (a > b) {
        a = b = 0;
    }

    this->a = a;
    this->b = b;
}

int Interval::getA() const {
    return a;
}

int Interval::getB() const {
    return b;
}

void Interval::setA(int a) {
    if (a > b) {
        return;
    }

    this->a = a;
}

void Interval::setB(int b) {
    if (b < a) {
        return;
    }

    this->b = b;
}

unsigned Interval::countNumbersMeetingCondition(bool(*pred)(int)) const {
    unsigned counter = 0;
    for (int i = a; i <= b; i++) {
        if (pred(i)) {
            counter++;
        }
    }

    return counter;
}

unsigned Interval::getLength() const {
    return b - a + 1;
}

bool Interval::isInInterval(int x) const {
    return a <= x && x <= b;
}

bool isPow2(int a) {
    if (a <= 0) {
        return false;
    }

    return (a & a - 1) == 0;
}

bool Interval::areStartAndEndPowOf2() const {
    return isPow2(a) && isPow2(b);
}

Interval Interval::intersec(const Interval& other) const {
    if (b < other.getA() || a > other.getB()) {
        return Interval(0, 0);
    }

    int newA = std::max(a, other.getA());
    int newB = std::min(b, other.getB());

    return Interval(newA, newB);
}

bool Interval::subInterval(const Interval& other) const {
    return isInInterval(other.a) && isInInterval(other.b);
}

unsigned Interval::countPrimeNumbers() const {
    return countNumbersMeetingCondition(isPrime);
}

unsigned Interval::countPalidroms() const {
    return countNumbersMeetingCondition(isPalindorme);
}

// uniquedigits 
unsigned Interval::countUniqueDigits() const {
    return countNumbersMeetingCondition(containsOnlyDistinctNumbers);
}

int main() {
    bool (*isPrimePtr)(int) = isPrime;
    
    bool b = isPrimePtr(5);
}
