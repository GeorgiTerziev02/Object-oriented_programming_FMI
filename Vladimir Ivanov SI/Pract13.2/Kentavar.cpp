#include "Kentavar.h"

void Kentavar::fightWithMinotavar() const
{
	std::cout << "Kentavar wins over Minotavar!" << std::endl;
}

void Kentavar::fightWithKentavar() const
{
	std::cout << "Kentavar drink beer with Kentavar!" << std::endl;
}

void Kentavar::fightWithSfinks() const
{
	std::cout << "Kentavar lose from Sfinks!" << std::endl;
}

void Kentavar::fight(Monster* monster2) const
{
	monster2->fightWithKentavar();
}
