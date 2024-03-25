#include "Bitset.h"
#include <iostream>

Bitset Bitset::unionOfSets(const Bitset& other)
{
    Bitset result;
    for (unsigned i = 0; i < BUCKETS_COUNT; i++)
        result.data[i] = (data[i] | other.data[i]);

    return result;
}

Bitset Bitset::intersectionOfSets(const Bitset& other)
{
    Bitset result;
    for (unsigned i = 0; i < BUCKETS_COUNT; i++)
        result.data[i] = (data[i] & other.data[i]);

    return result;
}

unsigned Bitset::getBucketIndex(unsigned number) const
{
    return number / BYTE_SIZE;
}

unsigned char Bitset::getMask(unsigned number) const
{
    unsigned indexInBucket = number % BYTE_SIZE;

    char mask = 1;

    mask = mask << (BYTE_SIZE - indexInBucket - 1);
    return mask;
}

bool Bitset::contains(unsigned number) const
{
    unsigned buckedIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    return (mask & data[buckedIndex]);
}

bool Bitset::addNumber(unsigned number)
{
    if (number >= MAX_SIZE || contains(number))
        return false;

    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    data[bucketIndex] |= mask;

    return true;
}

bool Bitset::removeNumber(unsigned number)
{
    if (number >= MAX_SIZE || !contains(number))
        return false;

    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);

    data[bucketIndex] ^= mask;

    return true;
}

void Bitset::print() const
{
    std::cout << "{ ";
    unsigned current = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (contains(i))
        {
            std::cout << i << ' ';
        }
    }
    std::cout << "} " << std::endl;
}