#include <iostream>
#include "polymorphic_ptr.hpp"
#include "polymorphic_container.hpp"

class Base {
public:
	virtual void print() const = 0;
	virtual Base* clone() const = 0;
	virtual ~Base() = default;
};

class Der1 : public Base {
public:
	void print() const override {
		std::cout << "Der1" << std::endl;
	}
	Base* clone() const override {
		return new Der1(*this);
	}
};

class Der2 : public Base {
public:
	void print() const override {
		std::cout << "Der2" << std::endl;
	}
	Base* clone() const override {
		return new Der2(*this);
	}
};

int main() {
	polymorphic_container<Base> pc;

	pc.add(new Der1());
	pc.add(new Der2());
	pc.execute(0, [](const Base* p) { p->print(); });
	pc.execute(1, [](const Base* p) { p->print(); });
}