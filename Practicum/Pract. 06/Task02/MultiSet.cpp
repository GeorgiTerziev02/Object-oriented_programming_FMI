#include "MultiSet.h"

void MultiSet::freeData()
{
	delete[] _data;
	_data = nullptr;
}

void MultiSet::copyFrom(const MultiSet& other)
{
	_dataSize = other._dataSize;
	_maxNumsCount = other._maxNumsCount;
	_data = new byte[_dataSize];
	for (size_t i = 0; i < _dataSize; ++i) {
		_data[i] = other._data[i];
	}
}

bool MultiSet::setOccurrences(size_t num, size_t count)
{
	if (num >= _maxNumsCount || count > 3) {
		return false;
	}
	size_t bucketInd = num / 4;
	size_t posInBucket = num % 4;

	byte mask = ~getMask(posInBucket);
	_data[bucketInd] &= mask;

	count <<= sizeof(byte) * 8 - 2 * posInBucket - 2;

	_data[bucketInd] |= count;
	return true;
}

MultiSet::MultiSet() : MultiSet(min_nums_max){}

MultiSet::MultiSet(size_t n)
{
	_maxNumsCount = std::max(n, min_nums_max);
	_dataSize = _maxNumsCount / 4 + 1;
	_data = new byte[_dataSize]{0};
}

MultiSet::MultiSet(const MultiSet& other)
{
	copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this != &other) {
		freeData();
		copyFrom(other);
	}
	return *this;
}

MultiSet::~MultiSet()
{
	freeData();
	_dataSize = 0;
	_maxNumsCount = 0;
}

bool MultiSet::addNum(size_t num)
{
	return setOccurrences(num, nOccurrences(num) + 1);
}

bool MultiSet::removeNum(size_t num)
{
	size_t count = nOccurrences(num);
	return count > 0 && setOccurrences(num, count - 1);

}

size_t MultiSet::nOccurrences(size_t num) const
{
	if (num >= _maxNumsCount) {
		return 0;
	}
	size_t bucketInd = num / 4;
	size_t posInBucket = num % 4;
	byte mask = getMask(posInBucket);
	size_t res = _data[bucketInd] & mask;
	res >>= sizeof(byte) * 8 - posInBucket * 2 - 2;
	return res;
}

void MultiSet::print(std::ostream& os) const
{
	for (size_t i = 0; i < _maxNumsCount; ++i) {
		os << i << ": " << nOccurrences(i) << " times" << std::endl;
	}
}

byte getMask(size_t posInBucket)
{
	if (posInBucket >= sizeof(byte) * 4) {
		return 0;
	}
	byte mask = 0b11;
	mask <<= sizeof(byte) * 8 - 2 * posInBucket - 2;
	return mask;
}

MultiSet getUnion(const MultiSet& set1, const MultiSet& set2)
{
	MultiSet res(std::max(set1._maxNumsCount, set2._maxNumsCount));
	for (size_t i = 0; i < res._maxNumsCount; ++i) {
		res.setOccurrences(i, std::max(set1.nOccurrences(i), set2.nOccurrences(i)));
	}
	return res;
}

MultiSet getIntersection(const MultiSet& set1, const MultiSet& set2)
{
	MultiSet res(std::min(set1._maxNumsCount, set2._maxNumsCount));
	for (size_t i = 0; i < res._maxNumsCount; ++i) {
		res.setOccurrences(i, std::min(set1.nOccurrences(i), set2.nOccurrences(i)));
	}
	return res;
}
