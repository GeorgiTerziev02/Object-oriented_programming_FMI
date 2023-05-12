#include "PremiumPlayer.h"

unsigned short PremiumPlayer::LEVEL_GAP = 256;

PremiumPlayer::PremiumPlayer(int id, const MyString& username, const MyString& password): User(id, password) {
	this->username = username;
}

bool PremiumPlayer::increaseLevel(Stars nextLevel) {
	if (points >= LEVEL_GAP) {
		points -= LEVEL_GAP;
		stars = nextLevel;
		std::cout << "Player with id: " << id << " and username: " << username << " increased level!" << std::endl;
		return true;
	}
	std::cout << "Not enough points to level up!" << std::endl;

	return false;
}