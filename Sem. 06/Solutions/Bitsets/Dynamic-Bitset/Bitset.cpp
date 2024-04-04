#include "Bitset.h"
#include <iostream>

namespace {
	constexpr size_t BUCKET_SIZE = 8;

	unsigned char getMask(unsigned int n) {
		unsigned int shiftIndex = (n % BUCKET_SIZE);

		unsigned char mask = 1;
		mask <<= (BUCKET_SIZE - 1 - shiftIndex);
		return mask;
	}

	unsigned int getBucketIndex(unsigned int n) {
		return n / BUCKET_SIZE;
	}
}

void Bitset::copyFrom(const Bitset& other) {
	maxNum = other.maxNum;
	bucketsCount = other.bucketsCount;
	data = new unsigned char[bucketsCount];
	for (size_t i = 0; i < bucketsCount; i++) {
		data[i] = other.data[i];
	}
}

void Bitset::free() {
	delete[] data;
	data = nullptr;
	maxNum = bucketsCount = 0;
}

Bitset::Bitset(unsigned int max) {
	maxNum = max;
	bucketsCount = max / BUCKET_SIZE + 1;
	data = new unsigned char[bucketsCount]{};
}

Bitset::Bitset(const Bitset& other) {
	copyFrom(other);
}

Bitset& Bitset::operator=(const Bitset& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Bitset::~Bitset() {
	free();
}

void Bitset::add(unsigned int n) {
	if (n > maxNum) {
		return;
	}

	unsigned char mask = getMask(n);
	unsigned int bucket = getBucketIndex(n);

	data[bucket] |= mask;
}

void Bitset::remove(unsigned int n) {
	if (n > maxNum) {
		return;
	}

	unsigned char mask = getMask(n);
	unsigned int bucket = getBucketIndex(n);

	data[bucket] &= ~mask;
}

bool Bitset::contains(unsigned int n) const {
	if (n > maxNum) {
		return false;
	}

	unsigned char mask = getMask(n);
	unsigned int bucket = getBucketIndex(n);

	return (data[bucket] & mask);
}

void Bitset::print() const {
	for (size_t i = 0; i <= maxNum; i++) {
		if (contains(i)) {
			std::cout << i << ' ';
		}
	}

	std::cout << std::endl;
}

Bitset unionOfSets(const Bitset& lhs, const Bitset& rhs) {
	Bitset result(std::max(lhs.maxNum, rhs.maxNum));
	unsigned int commonBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (size_t i = 0; i < commonBucketsCount; i++) {
		result.data[i] = lhs.data[i] | rhs.data[i];
	}

	const Bitset& largerSet = lhs.maxNum > rhs.maxNum ? lhs : rhs;
	unsigned int largerSetBuckets = largerSet.bucketsCount;
	for (size_t i = commonBucketsCount; i < largerSetBuckets; i++) {
		result.data[i] = largerSet.data[i];
	}

	return result;

}

Bitset intersectionOfSets(const Bitset& lhs, const Bitset& rhs) {
	Bitset result(std::min(lhs.maxNum, rhs.maxNum));
	unsigned int commonBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (size_t i = 0; i < commonBucketsCount; i++) {
		result.data[i] = lhs.data[i] & rhs.data[i];
	}

	return result;
}
