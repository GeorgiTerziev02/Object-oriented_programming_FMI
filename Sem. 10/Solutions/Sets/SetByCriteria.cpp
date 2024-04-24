#include "SetByCriteria.h"

void SetByCriteria::fillSet() {
	for (size_t i = 0; i < getMaxNumber(); i++) {
		if (criteria.includes(i) && !criteria.excludes(i)) {
			add(i);
		}
		else {
			remove(i);
		}
	}
}

SetByCriteria::SetByCriteria(unsigned maxNumber, bool(*includes)(unsigned n), bool(*excludes)(unsigned n))
	: Bitset(maxNumber), criteria({includes, excludes})
{
	fillSet();
}

void SetByCriteria::setIncludes(bool(*includes)(unsigned n)) {
	criteria.includes = includes;
	fillSet();
}

void SetByCriteria::setExcludes(bool(*excludes)(unsigned n)) {
	criteria.excludes = excludes;
	fillSet();
}

bool SetByCriteria::contains(unsigned int n) const {
	return Bitset::contains(n);
}

void SetByCriteria::print() const {
	Bitset::print();
}
