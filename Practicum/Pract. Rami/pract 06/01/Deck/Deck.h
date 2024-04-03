#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"

constexpr size_t MAX_MONSTER_CARDS = 20;
constexpr size_t MAX_MAGIC_CARDS = 20;

class Deck {
	MonsterCard monsters[MAX_MONSTER_CARDS] = {};
	MagicCard magics[MAX_MAGIC_CARDS] = {};

public:
	Deck() = default;
	
	size_t getMonsterCardsCount() const;
	size_t getMagicCardsCount() const;

	void addMonsterCard(const char* name, unsigned attack, unsigned defence);
	void addMagicCard(MagicType type, const char* name, const char* effect);

	void changeMonsterCard(size_t index, const MonsterCard& newCard);
	void changeMagicCard(size_t index, const MagicCard& newCard);

	void removeMonsterCard(size_t index);
	void removeMagicCard(size_t index);

	void printDeck() const;
};
