#pragma once

namespace {
	constexpr size_t BUCKET_SIZE = 8;
}

class Bitset
{
	unsigned char* data;
	unsigned int maxNum;

	void copyFrom(const Bitset& other);
	void free();

	unsigned int getBucketIndex(unsigned int n) const;
	unsigned int getBucketsCount() const;
	unsigned char getMask(unsigned int n) const;
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
};