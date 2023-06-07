#pragma once

class Base {
public:
	virtual ~Base() = default;
};

class Der1 : public Base {};
class Der2 : public Base {};

class Factory {
public:
	virtual Base* create() const = 0;
	virtual ~Factory() = default;
};

class Der1Factory : public Factory {
	virtual Base* create() const override {
		return new Der1();
	}
};

class Der2Factory : public Factory {
public:
	virtual Base* create() const override {
		return new Der2();
	}
};

