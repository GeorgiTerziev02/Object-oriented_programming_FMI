#pragma once
#include <iostream>
#include "Player.h"
class LoggedPlayer: public Player
{
	char password[8];
public:
	LoggedPlayer(const char* password);
	virtual bool levelUp() override;
	bool logIn(const char* passwordForLogIn,int IDForLogIn)const;
};

