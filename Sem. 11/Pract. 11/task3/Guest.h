#pragma once
#include "Player.h"
class Guest:public Player 
{
	size_t timeToPlay;
public:
	Guest(size_t timeToPlay);
	virtual bool levelUp() override;
};

