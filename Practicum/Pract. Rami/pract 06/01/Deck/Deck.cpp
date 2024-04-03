#include "Deck.h"

#include <iostream>

size_t Deck::getMonsterCardsCount() const {
	for (size_t i = 0; i < MAX_MONSTER_CARDS; i++) {
		if (monsters[i].isEmpty()) {
			return i;
		}
	}

	return MAX_MONSTER_CARDS;
}

size_t Deck::getMagicCardsCount() const {
	for (size_t i = 0; i < MAX_MAGIC_CARDS; i++) {
		if (magics[i].isEmpty()) {
			return i;
		}
	}

	return MAX_MAGIC_CARDS;
}

void Deck::addMonsterCard(const char* name, unsigned attack, unsigned defence) {
	if (getMonsterCardsCount() >= MAX_MONSTER_CARDS) {
		std::cout << "Monsters Cards deck full!\n";
		return;
	}

	MonsterCard newMonster(name, attack, defence);
	monsters[getMonsterCardsCount()] = newMonster;
}

void Deck::addMagicCard(MagicType type, const char* name, const char* effect) {
	if (getMagicCardsCount() >= MAX_MAGIC_CARDS) {
		std::cout << "Magic Cards deck full!\n";
		return;
	}

	MagicCard newMagic(type, name, effect);
	magics[getMagicCardsCount()] = newMagic;
}

void Deck::changeMonsterCard(size_t index, const MonsterCard& newCard) {
	if (index >= getMonsterCardsCount()) {
		std::cout << "No card at this index";
		return;
	}

	monsters[index] = newCard;
}

void Deck::changeMagicCard(size_t index, const MagicCard& newCard) {
	if (index >= getMagicCardsCount()) {
		std::cout << "No card at this index";
		return;
	}

	magics[index] = newCard;
}

void Deck::removeMonsterCard(size_t index) {
	size_t monsterCardsCount = getMonsterCardsCount();

	for (int i = index; i < monsterCardsCount; i++) {
		monsters[i] = monsters[i + 1];
	}

	monsters[monsterCardsCount] = { nullptr, 0, 0 };
}

void Deck::removeMagicCard(size_t index) {
	size_t magicCardsCount = getMagicCardsCount();

	for (int i = index; i < magicCardsCount; i++) {
		magics[i] = magics[i + 1];
	}

	magics[magicCardsCount] = { MagicType::Unknown, "", "" };
}

void Deck::printDeck() const {
	size_t monsterCardsCount = getMonsterCardsCount();
	std::cout << "MONSTER CARDS:\n";

	for (int i = 0; i < monsterCardsCount; i++) {
		monsters[i].print();
	}

	size_t magicCardsCount = getMagicCardsCount();
	std::cout << "MAGIC CARDS:\n";

	for (int i = 0; i < magicCardsCount; i++) {
		magics[i].print();
	}
}
