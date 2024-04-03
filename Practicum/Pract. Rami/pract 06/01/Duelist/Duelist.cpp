#include "Duelist.h"

#include <iostream>
#pragma warning(disable: 4996);

void Duelist::copyName(const char* newName) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Duelist::copyFrom(const Duelist& other) {
	deck = other.deck;
	copyName(other.name);
}

void Duelist::free() {
	delete[] name;
	name = nullptr;
	deck = {};
}

Duelist::Duelist(const char* name) : deck() {
	setName(name);
}

Duelist::Duelist(const char* name, const Deck& deck) {
	setName(name);
	this->deck = deck;
}

Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Duelist::~Duelist() {
	free();
}

void Duelist::setName(const char* newName) {
	if (!newName || name == newName) {
		return;
	}

	delete[] name;
	copyName(newName);
}

void Duelist::addMonsterCardToDeck(const char* name, unsigned attack, unsigned defence) {
	deck.addMonsterCard(name, attack, defence);
}

void Duelist::addMagicCardToDeck(MagicType type, const char* name, const char* effect) {
	deck.addMagicCard(type, name, effect);
}

void Duelist::changeMonsterCardInDeck(size_t index, const MonsterCard& newCard) {
	deck.changeMonsterCard(index, newCard);
}

void Duelist::changeMagicCardInDeck(size_t index, const MagicCard& newCard) {
	deck.changeMagicCard(index, newCard);
}

void Duelist::removeMonsterCardFromDeck(size_t index) {
	deck.removeMonsterCard(index);
}

void Duelist::removeMagicCardFromDeck(size_t index) {
	deck.removeMagicCard(index);

}

void Duelist::print() const {
	std::cout << "duelist: " << name << std::endl;
	deck.printDeck();
}
