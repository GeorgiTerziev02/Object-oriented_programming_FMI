#include <iostream>
#include <assert.h>

struct Rational {
	int numerator;
	int denominator;
};

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

bool isValid(const Rational& r) {
	return r.denominator != 0;
}

void rationalize(Rational& r) {
	assert(isValid(lhs) && isValid(rhs));
	int gcdValue = gcd(r.numerator, r.denominator);

	r.numerator /= gcdValue;
	r.denominator /= gcdValue;
}

// lhs += rhs
// assignment operators return ref to the left side
Rational& plusEqualsRational(
	Rational& lhs,
	const Rational& rhs
) {
	assert(isValid(lhs) && isValid(rhs));
	lhs.denominator *= rhs.denominator;
	lhs.numerator *= rhs.denominator;
	lhs.numerator += (lhs.denominator * rhs.numerator);

	rationalize(lhs);

	return lhs;
}

// + operator can be easily implemented using += operator
// the same is valid for other operators
// lhs + rhs
// returns a new Rational number as a result
Rational plusRational(
	const Rational& lhs,
	const Rational& rhs
) {
	assert(isValid(lhs) && isValid(rhs));
	Rational copyLhs = lhs;
	// Also possible copyLhs{lhs.numerator, lhs.denominator}
	plusEqualsRational(copyLhs, rhs);

	return copyLhs;
}

void printRational(const Rational& r) {
	std::cout << r.numerator << "/" << r.denominator;
}

int main() {
	Rational r1{ 1, 2 };
	Rational r2{ 6, 3 };
	Rational result = plusRational(r1, r2);

	printRational(result);
}
