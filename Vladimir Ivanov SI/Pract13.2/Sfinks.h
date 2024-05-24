#pragma once
#include <iostream>
#include "Monster.h"

class Sfinks : public Monster {
public:
	void fightWithMinotavar() const override;
	void fightWithKentavar() const override;
	void fightWithSfinks() const override;
	void fight(Monster* monster2) const override;

private:
	
};