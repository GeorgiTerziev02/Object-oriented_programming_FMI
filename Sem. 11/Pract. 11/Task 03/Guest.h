#pragma once
#include "Player.h"

class Guest : public Player
{
private:

	static unsigned short MINUTES_ALLOWED;
	unsigned short minutesLeft;

public:

	Guest(int id);

	bool levelUp() override;

	//perhaps a method that reduces the time left after completing a mission can be added 
};