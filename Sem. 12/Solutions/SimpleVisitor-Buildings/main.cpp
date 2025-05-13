#include <iostream>

class House;
class Factory;
class Bank;

// Visitor
class Person {
public:
    void visit(const House* house) {
        std::cout << "sleep";
    }
    void visit(const Factory* factory) {
        std::cout << "work";
    }
    void visit(const Bank* bank) {
        std::cout << "withdraw";
    }
};

// Accepts the visitor
class Building {
public:
    virtual void accept(Person* person) = 0;
    virtual ~Building() = default;
};

class House : public Building {
public:
    void accept(Person* person) override {
        person->visit(this);
    }
};

class Factory : public Building {
public:
    void accept(Person* person) override {
        person->visit(this);
    }
};

class Bank : public Building {
public:
    void accept(Person* person) override {
        person->visit(this);
    }
};

int main() {
    Person person;
    House house;
    Factory factory;
    Bank bank;

    Building* buildings[] = {&house, &factory, &bank};

    for (size_t i = 0; i < 3; i++) {
        buildings[i]->accept(&person);
        std::cout << std::endl;
    }
}