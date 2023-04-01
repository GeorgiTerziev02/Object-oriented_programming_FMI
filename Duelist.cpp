#include "Duelist.h"
#include <iostream>
#pragma warning(disable:4996)
void Duelist::copy(const Duelist& other) {
	strcpy(this->name, name);
	this->deck = deck;
}
void Duelist::free() {
	delete[] name;
}

Duelist::Duelist(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Duelist::Duelist(const Duelist& other) {
	copy(other);
}
Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

size_t Duelist::getMonsterCardsNumFromDeck()const {
	return deck.getMonsterCardsNum();
}
size_t Duelist::getSpellCardsNumFromDeck()const {
	return deck.getSpellCardsNum();
}
void Duelist::addMonsterCardInDeck(const Monster& newMonster) {
	deck.addMonsterCard(newMonster.getName(), newMonster.getAttackPoints(), newMonster.getDefensePoints());
}
void Duelist::addSpellCardInDeck(const Spell& newSpell) {
	deck.addSpellCard(newSpell.getName(), newSpell.getEffect(), newSpell.getSpellType());
}
void Duelist::changeMonsterCardInDeck(size_t index, const Monster& newMonster) {
	deck.changeMonsterCard(index, newMonster.getName(), newMonster.getAttackPoints(), newMonster.getDefensePoints());
}
void Duelist::changeSpellCardInDeck(size_t index, const Spell& newSpell) {
	deck.changeSpellCard(index, newSpell.getName(), newSpell.getEffect(), newSpell.getSpellType());
}
void Duelist::removeMonsterCardInDeck(size_t index) {
	deck.removeMonsterCard(index);
}
void Duelist::removeSpellCardInDeck(size_t index) {
	deck.removeSpellCard(index);
}

Duelist::~Duelist() {
	delete[] name;
}