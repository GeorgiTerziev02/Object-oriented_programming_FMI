#pragma once
#include "../Collection.h"
#include "PureNumbersCollection.h"

enum CollectionType {
	NORMAL_COLLECTION,
	SORTED_COLLECTION
};

/// <summary>
/// Collection of unique elements only
/// They might be sorted/unsorted
/// </summary>
class Set : public Collection {
private:
	// We don't want a set of interval collection (because this will be a bitset, think about it)
	// so we create PureNumbersCollection base class
	// that will be inherited only by the collection we want to be in the set
	PureNumbersCollection* collection;

public:
	Set(CollectionType);

	// for now deleted because we don't know how to create copy of collection
	// we don't know what there is behind
	Set(const Set&) = delete;
	Set& operator=(const Set&) = delete;

	void add(int) override;
	void remove(int) override;
	size_t count(int) const override;
	bool contains(int) const override;

	~Set();
};