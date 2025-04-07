#pragma once

namespace BitsetConstants {
	constexpr size_t BYTE_SIZE = 8;
}

// moved these functions to a namespace because they are not
// using anything from the bitset instance(not using this)
namespace BitsetHelpers {
	unsigned char getMask(unsigned int n);
	unsigned int getBucketIndex(unsigned int n);
}

class Bitset {
private:
	unsigned char* data;
	unsigned int maxNum;
	unsigned int bucketsCount;
public:
	Bitset(unsigned int max);
	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	~Bitset();

	void add(unsigned int n);
	void remove(unsigned int n);
	bool contains(unsigned int n) const;
	void print() const;

	friend Bitset unionOfSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset intersectionOfSets(const Bitset& lhs, const Bitset& rhs);

private:
	void copyFrom(const Bitset& other);
	void free();
};