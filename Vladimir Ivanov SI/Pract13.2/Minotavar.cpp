#include "Minotavar.h"

void Minotavar::fightWithMinotavar() const
{
	std::cout << "Minotavar drink beer with Minotavar!" << std::endl;
}

void Minotavar::fightWithKentavar() const
{
	std::cout << "Minotavar lose from Kentavar!" << std::endl;
}

void Minotavar::fightWithSfinks() const
{
	std::cout << "Minotavar wins over Sfinks!" << std::endl;
}

void Minotavar::fight(Monster* monster2) const
{
	monster2->fightWithMinotavar();
}
