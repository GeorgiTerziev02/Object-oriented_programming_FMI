#pragma once
#include "Monster.h"
#include "Spell.h"

const size_t MAX_CARDS = 20;

class Deck
{
private:
	Monster monsterCards[MAX_CARDS];
	Spell spellCards[MAX_CARDS];
	size_t monsterCardsNum = 0;
	size_t spellCardsNum = 0;

public:
	Deck() = default;
	size_t getMonsterCardsNum()const;
	size_t getSpellCardsNum()const;
	void addMonsterCard(const char* name,size_t attackPoints,size_t defensePoints);
	void addSpellCard(const char* name, const char* effect, const SpellType& type);
	void changeMonsterCard(size_t index,const char* name, size_t attackPoints, size_t defensePoints);
	void changeSpellCard(size_t index, const char* name, const char* effect, const SpellType& type);
	void removeMonsterCard(size_t index);
	void removeSpellCard(size_t index);
	Deck& operator=(const Deck& other);
};

