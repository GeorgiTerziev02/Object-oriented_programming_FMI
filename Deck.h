#pragma once
#include "Monster.h"
#include "Spell.h"

const size_t MAX_CARDS = 20;

class Deck
{
private:
	Monster monsterCards[MAX_CARDS];
	Spell spellCards[MAX_CARDS];
	size_t monsterCardsCount = 0;
	size_t spellCardsCount = 0;

	void monsterCardsSwap(Monster& a, Monster& b);
	void spellCardsSwap(Spell& a, Spell& b);
public:
	Deck() = default;
	size_t getMonsterCardsCount()const;
	size_t getSpellCardsCount()const;
	void addMonsterCard(const char* name,size_t attackPoints,size_t defensePoints);
	void addSpellCard(const char* name, const char* effect, const SpellType type);
	void changeMonsterCard(size_t index,const char* name, size_t attackPoints, size_t defensePoints);
	void changeSpellCard(size_t index, const char* name, const char* effect, const SpellType type);
	void removeMonsterCard(size_t index);
	void removeSpellCard(size_t index);
};

