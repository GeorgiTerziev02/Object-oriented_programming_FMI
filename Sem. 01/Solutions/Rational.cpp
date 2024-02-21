#include <iostream>
#include <assert.h>

// TODO: refactor
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
	// TODO: validate
	assert(isValid(lhs) && isValid(rhs));
	int gcdValue = gcd(r.numerator, r.denominator);

	r.numerator /= gcdValue;
	r.denominator /= gcdValue;
}

Rational plusRational(
	const Rational& lhs,
	const Rational& rhs
) {
	// TODO: validate
	assert(isValid(lhs) && isValid(rhs));
	Rational copyLhs{lhs.numerator, lhs.denominator};

	copyLhs.denominator *= rhs.denominator;
	copyLhs.numerator *= rhs.denominator;
	copyLhs.numerator += (lhs.denominator * rhs.numerator);

	rationalize(copyLhs);

	return copyLhs;
}

void printRational(const Rational& r) {
	std::cout << r.numerator << " " << r.denominator;
}

int main() {
	Rational r1{ 1, 2 };
	Rational r2{ 6, 3 };
	Rational result = plusRational(r1, r2);

	printRational(result);
}