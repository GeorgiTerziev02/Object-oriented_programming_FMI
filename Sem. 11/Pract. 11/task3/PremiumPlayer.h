#pragma once
#include "Player.h"
#include "MyString.h"
class PremiumPlayer: public Player
{
	MyString name;
	char password[8];
public:
	PremiumPlayer(const char* name, const char* password);
	virtual bool levelUp()override;
};

