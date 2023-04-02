#include "Monster.h"
#include <iostream>
#pragma warning(disable:4996)
void Monster::copy(const Monster& other) {
	strcpy(this->name, other.name);
	this->attackPoints = other.attackPoints;
	this->defensePoints = other.defensePoints;
}

void Monster::free() {
	delete[] name;
	attackPoints = defensePoints = 0;
}

Monster::Monster(const char* name, size_t attackPoints, size_t defensePoints) {
	setName(name);
	setAttackPoints(attackPoints);
	setDefensePoints(defensePoints);
}

Monster::Monster(const Monster& other) {
	copy(other);
}

void Monster::setName(const char* name) {
	strcpy(this->name, name);
}
void Monster::setAttackPoints(size_t attackPoints) {
	this->attackPoints = attackPoints;
}
void Monster::setDefensePoints(size_t defensePoints) {
	this->defensePoints = defensePoints;
}

char* Monster::getName() const {
	return name;
}

size_t Monster::getAttackPoints() const {
	return attackPoints;
}

size_t Monster::getDefensePoints() const {
	return defensePoints;
}

Monster& Monster::operator=(const Monster& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Monster::~Monster() {
	free();
}