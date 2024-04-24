#pragma once
#include "Bitset.h"

class SetByCriteria : private Bitset {
private:
	struct Criteria {
		bool(*includes)(unsigned n);
		bool(*excludes)(unsigned n);
	} criteria;
	
	void fillSet();
public:
	SetByCriteria(unsigned maxNumber, bool(*includes)(unsigned n), bool(*excludes)(unsigned n));

	void setIncludes(bool(*includes)(unsigned n));
	void setExcludes(bool(*excludes)(unsigned n));

	bool contains(unsigned int n) const;
	void print() const;
};

