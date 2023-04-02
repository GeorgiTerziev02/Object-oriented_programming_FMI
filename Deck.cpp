#include "Deck.h"
#include <iostream>

void Deck::monsterCardsSwap(Monster& a, Monster& b) {
	Monster temp = a;
	a = b;
	b = temp;
}

void Deck::spellCardsSwap(Spell& a, Spell& b) {
	Spell temp = a;
	a = b;
	b = temp;
}

size_t Deck::getMonsterCardsCount()const {
	return monsterCardsCount;
}
size_t Deck::getSpellCardsCount()const {
	return spellCardsCount;
}
void Deck::addMonsterCard(const char* name, size_t attackPoints, size_t defensePoints) {
	monsterCards[monsterCardsCount]=Monster(name, attackPoints, defensePoints);
	monsterCardsCount++;
}
void Deck::addSpellCard(const char* name, const char* effect, const SpellType type) {
	spellCards[spellCardsCount] = Spell(name,effect,type);
	spellCardsCount++;
}
void Deck::changeMonsterCard(size_t index, const char* name, size_t attackPoints, size_t defensePoints) {
	monsterCards[index] = Monster(name,attackPoints,defensePoints);
}
void Deck::changeSpellCard(size_t index, const char* name, const char* effect, const SpellType type) {
	spellCards[index] = Spell(name, effect, type);
}
void Deck::removeMonsterCard(size_t index) {
	monsterCardsSwap(monsterCards[monsterCardsCount], monsterCards[index]);
	monsterCardsCount--;
}
void Deck::removeSpellCard(size_t index) {
	spellCardsSwap(spellCards[monsterCardsCount], spellCards[index]);
	spellCardsCount--;
}
