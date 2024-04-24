#pragma once

class Bitset {
private:
	unsigned char* data;
	unsigned int maxNum;
	unsigned int bucketsCount;
public:
	Bitset(unsigned int max);
	Bitset(const Bitset& other);
	Bitset(Bitset&& other) noexcept;
	Bitset& operator=(const Bitset& other);
	Bitset& operator=(Bitset&& other) noexcept;
	~Bitset() noexcept;

	void add(unsigned int n);
	void remove(unsigned int n);
	bool contains(unsigned int n) const;
	void reset();
	void print() const;

	unsigned getMaxNumber() const;

	friend Bitset unionOfSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset intersectionOfSets(const Bitset& lhs, const Bitset& rhs);

private:
	void moveFrom(Bitset&& other) noexcept;
	void copyFrom(const Bitset& other);
	void free();
};