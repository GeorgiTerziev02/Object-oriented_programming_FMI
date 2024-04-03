#pragma once
#include "Deck.h"

class Duelist {
	char* name = nullptr;
	Deck deck = {};

	void copyName(const char* newName);
	void copyFrom(const Duelist& other);
	void free();

public:
	Duelist() = default;
	Duelist(const char* name);
	Duelist(const char* name, const Deck& deck);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	void setName(const char* newName);

	void addMonsterCardToDeck(const char* name, unsigned attack, unsigned defence);
	void addMagicCardToDeck(MagicType type, const char* name, const char* effect);

	void changeMonsterCardInDeck(size_t index, const MonsterCard& newCard);
	void changeMagicCardInDeck(size_t index, const MagicCard& newCard);

	void removeMonsterCardFromDeck(size_t index);
	void removeMagicCardFromDeck(size_t index);

	void print() const;
};
