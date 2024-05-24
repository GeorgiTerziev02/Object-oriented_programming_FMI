#include "Sfinks.h"

void Sfinks::fightWithMinotavar() const
{
	std::cout << "Sfinks lose from Minotavar!" << std::endl;
}

void Sfinks::fightWithKentavar() const
{
	std::cout << "Sfinks wins over Kentavar!" << std::endl;
}

void Sfinks::fightWithSfinks() const
{
	std::cout << "Sfinks drink beer with Sfinks!" << std::endl;
}

void Sfinks::fight(Monster* monster2) const
{
	monster2->fightWithSfinks();
}
