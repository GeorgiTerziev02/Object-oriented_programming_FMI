#pragma once

class Collection {
public:
	virtual void add(int) = 0;
	virtual void remove(int) = 0;
	virtual size_t count(int) const = 0;
	virtual bool contains(int) const = 0;
	virtual ~Collection() = default;
};
