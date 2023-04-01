#pragma once
#include "Deck.h"

class Duelist
{
private:
	char* name;
	Deck deck;
	 
	void copy(const Duelist& other);
	void free();
public:
	Duelist(const char* name);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);

	size_t getMonsterCardsNumFromDeck()const;
	size_t getSpellCardsNumFromDeck()const;
	void addMonsterCardInDeck(const Monster& newMonster);
	void addSpellCardInDeck(const Spell& newSpell);
	void changeMonsterCardInDeck(size_t index, const Monster& newMonster);
	void changeSpellCardInDeck(size_t index, const Spell& newSpell);
	void removeMonsterCardInDeck(size_t index);
	void removeSpellCardInDeck(size_t index);

	~Duelist();
};

