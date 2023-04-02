#include <iostream>
#include "Duelist.h"
int main() {
	//40 cards = 20 MonsterCards/20 MagicCards
	Deck d;

	// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
	//ATK: 3000 DEF: 2500
	d.changeMonsterCard(4, "Blue-eyes white dragon", 3000, 2500);

	// 5-th card in the Magic deck is added/changed to "Monster reborn"
	d.changeSpellCard(5, "Monster reborn", "revive", SpellType::spell);

	//Returns the amount of MagicCards in the deck
	d.getSpellCardsCount(); //1

	//Returns the amount of MonsterCards in the deck
	d.getMonsterCardsCount(); //13

	Duelist player1("Seto Kaiba");

	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	Monster DarkMagician("Dark Magician", 2500, 2100);
	player1.changeMonsterCardInDeck(2, DarkMagician);

	Duelist player2("Yugi Muto");

	//Changes the 2-nd magic card in the Magic deck to “Reflection”
	Spell Reflection("Reflection", "Reflects the last played spell", SpellType::trap);
		player2.changeSpellCardInDeck(2, Reflection);
}