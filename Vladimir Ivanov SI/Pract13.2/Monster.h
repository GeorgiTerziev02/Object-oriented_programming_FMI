#pragma once

class Monster {
public:
	virtual void fightWithMinotavar() const = 0;
	virtual void fightWithKentavar() const = 0;
	virtual void fightWithSfinks() const = 0;
	virtual void fight(Monster* monster2) const = 0;

private:

};