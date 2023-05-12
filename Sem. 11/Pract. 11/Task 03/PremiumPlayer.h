#pragma once
#include "User.h"

class PremiumPlayer : public User 
{
private:

	static unsigned short LEVEL_GAP;
	MyString username;

	bool increaseLevel(Stars nextLevel) override;

public:

	PremiumPlayer(int id, const MyString& username, const MyString& password);
};

