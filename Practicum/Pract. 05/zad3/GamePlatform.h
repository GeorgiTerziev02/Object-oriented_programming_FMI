#pragma once
#include "Game.h"

const unsigned LIBRARY_SIZE = 5;


class GamePlatform
{
public:
	GamePlatform();

	unsigned getCount() const;

	const Game* getGame(unsigned index) const;

	bool AddGame(const char* gameName, double price, bool isAvailable);
	bool RemoveGame(const char* gameName);


	void showCheapest() const;
	void showMostExpensive() const;
	void showFreeGames() const;

	
	bool saveGamesToFile() const;
	bool loadGamesFromFile();


	void printAllGames() const; 



private:

	unsigned count;
	Game library[LIBRARY_SIZE];

};

