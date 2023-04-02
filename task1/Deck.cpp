#include "Deck.h"
#include <iostream>

size_t Deck::getMonsterCardsNum()const {
	return monsterCardsNum;
}
size_t Deck::getSpellCardsNum()const {
	return spellCardsNum;
}
void Deck::addMonsterCard(const char* name, size_t attackPoints, size_t defensePoints) {
	monsterCards[monsterCardsNum]=Monster(name, attackPoints, defensePoints);
	monsterCardsNum++;
}
void Deck::addSpellCard(const char* name, const char* effect, const SpellType& type) {
	spellCards[spellCardsNum] = Spell(name,effect,type);
	spellCardsNum++;
}
void Deck::changeMonsterCard(size_t index, const char* name, size_t attackPoints, size_t defensePoints) {
	monsterCards[index] = Monster(name,attackPoints,defensePoints);
}
void Deck::changeSpellCard(size_t index, const char* name, const char* effect, const SpellType& type) {
	spellCards[index] = Spell(name, effect, type);
}
void Deck::removeMonsterCard(size_t index) {
	monsterCards[monsterCardsNum] = monsterCards[index];
	monsterCardsNum--;
}
void Deck::removeSpellCard(size_t index) {
	spellCards[spellCardsNum] = spellCards[index];
	spellCardsNum--;
}
Deck& Deck::operator=(const Deck& other) {
	for (size_t i = 0; i < monsterCardsNum; i++) {
		monsterCards[i] = other.monsterCards[i];
	}
	for (size_t i = 0; i < spellCardsNum; i++) {
		spellCards[i] = other.spellCards[i];
	}
	return *this;
}