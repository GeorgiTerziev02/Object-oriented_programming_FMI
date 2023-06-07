#pragma once

class Base {
public:
	virtual Base* clone() const = 0; // create an exact copy
	virtual ~Base() = default;
};

class Der1 : public Base {
public:
	Base* clone() const override {
		return new Der1(*this);
	}
};

class Der2 : public Base {
public:
	Base* clone() const override {
		return new Der2(*this);
	}
};

