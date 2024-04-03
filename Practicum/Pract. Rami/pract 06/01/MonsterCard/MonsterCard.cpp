#include "MonsterCard.h"

#include <iostream>
#pragma warning(disable: 4996);

void MonsterCard::copyName(const char* newName) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void MonsterCard::copyFrom(const MonsterCard& other) {
	defencePoints = other.defencePoints;
	attackPoints = other.attackPoints;

	if (other.name) {
		copyName(other.name);
	}
}

void MonsterCard::free() {
	delete[] name;
	name = nullptr;
	attackPoints = 0;
	defencePoints = 0;
}

MonsterCard::MonsterCard(const char* name, unsigned attack, unsigned defence) {
	setName(name);
	attackPoints = attack;
	defencePoints = defence;
}

MonsterCard::MonsterCard(const MonsterCard & other) {
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MonsterCard::~MonsterCard() {
	free();
}

void MonsterCard::setName(const char* newName) {
	if (!newName || newName == name) {
		return;
	}

	delete[] name;
	copyName(newName);
}

void MonsterCard::setAttack(unsigned attack) {
	this->attackPoints = attack;
}

void MonsterCard::setDefence(unsigned defence) {
	this->defencePoints = defence;
}

bool MonsterCard::isEmpty() const {
	if (name == nullptr && attackPoints == 0 && defencePoints == 0) {
		return true;
	}

	return false;
}

void MonsterCard::print() const {
	std::cout << name << ", AP: " << attackPoints << ", DP: " << defencePoints << std::endl;
}
