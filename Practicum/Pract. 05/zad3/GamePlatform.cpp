#include "GamePlatform.h"
#include <cstring>
#include <iostream>

constexpr char GAME_PLATFORM_FILE[] = "GamePlatform.txt";

GamePlatform::GamePlatform()
{
	this->count = 0;
}

unsigned GamePlatform::getCount() const
{
	return this->count;
}


const Game* GamePlatform::getGame(unsigned index) const
{
	if (index >= 0 && index < this->count)
	{
		const Game* const ptr = &(this->library[index]);
			return ptr;
	}
	return nullptr;

	
}


bool GamePlatform::AddGame(const char* gameName,double price,bool isAvailable)
{
	bool gameAlreadySaved = false;
	
		for (size_t i = 0; i < this->count; i++)
		{
			if (strcmp(this->library[i].getTitle(), gameName) == 0)
			{
				gameAlreadySaved = true;
				break;
			}
				
		}

		if (gameAlreadySaved || this->count >= LIBRARY_SIZE)
			return false;

		this->library[count++] = Game(gameName, price, isAvailable);
		return true;
}
bool GamePlatform::RemoveGame(const char* gameName)
{
	bool gameAlreadySaved = false;

	for (size_t i = 0; i < this->count; i++)
	{
		if (strcmp(this->library[i].getTitle(), gameName) == 0)
		{
			gameAlreadySaved = true;
			break;
		}
	}
	if (gameAlreadySaved)
	{
		--count;
		return true;
	}
	else
	{
		std::cout << "Didn't find such a game to remove\n";
		return false;
	}


	
}


void GamePlatform::showCheapest() const
{
	if (this->count == 0)
	{
		std::cout << "There are no games in this platform\n";
		return;
	}

	unsigned indexCheapest = 0;
	double cheapestPrice = 10000;
	for (size_t i = 0; i < this->count; i++)
	{
		if (cheapestPrice > this->library[i].getPrice())
		{
			cheapestPrice = this->library[i].getPrice();
			indexCheapest = i;
		}
	}
	this->library[indexCheapest].print();

}

void GamePlatform::showMostExpensive() const
{
	if (this->count == 0)
	{
		std::cout << "There are no games in this platform\n";
		return;
	}

	unsigned indexMostExpensive = 0;
	double mostExpensive = -1;
	for (size_t i = 0; i < this->count; i++)
	{
		if (mostExpensive < this->library[i].getPrice())
		{
			mostExpensive = this->library[i].getPrice();
			indexMostExpensive = i;
		}
	}
	this->library[indexMostExpensive].print();
}
void GamePlatform::showFreeGames() const
{
	for (size_t i = 0; i < this->count; i++)
	{
		if (library[i].getPrice() == 0)
		{
			library[i].print();
			std::cout << "\n";
		}
	}
}



bool GamePlatform::saveGamesToFile() const
{
	if (this->count == 0)
		return false;

	std::ofstream out(GAME_PLATFORM_FILE, std::ios::out);
	if (!out)
	{
		std::cerr << "Problem opening file " << GAME_PLATFORM_FILE << "\n";
		return false;
	}
	out << this->count << "\n";
	for (size_t i = 0; i < this->count; i++)
	{
		library[i].saveGameToFile(out);
	}
	if (!out)
	{
		std::cerr << "Error writing to file " << GAME_PLATFORM_FILE << "\n";
		return false;
	}
	return true;
}
bool GamePlatform::loadGamesFromFile() 
{
	std::ifstream in(GAME_PLATFORM_FILE, std::ios::in);
	if (!in)
	{
		std::cerr << "Problem opening file reading" << GAME_PLATFORM_FILE << "\n";
		return false;
	}
	for (size_t i = 0; i < this->count; i++)
	{
		library[i].loadGameFromFile(in);
	}
	if (!in && !in.eof())
	{
		std::cerr << "Error reading from file " << GAME_PLATFORM_FILE << "\n";
		return false;
	}
	return true;
}



void GamePlatform::printAllGames() const
{
	for (size_t i = 0; i < this->count; i++)
	{
		std::cout << "Game number " << i << ":\n";
		this->library[i].print();
		std::cout << "\n";
	}
}


