#include "ImmutableString/ImmutableString.h"

int main() {
	ImmutableString s1("abc");
	ImmutableString s2("abc");
	ImmutableString s3 = s1;

	std::cout << (s1 == s2 && s2 == s3);
}