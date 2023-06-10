#include "Player.h"
#include <iostream>

Player::Player(int id) {
	this->id = id;
	this->points = 0;
	this->stars = Stars::one;
}

Player::~Player() {}

void Player::completeMission(unsigned short missionPoints) {
	this->points += missionPoints;
	std::cout << "Player with id: " << id << " successfully completed mission for " << missionPoints << " points." 
		<< std::endl;
}

bool Player::increaseLevel(Stars nextLevel) {

	if (points >= nextLevel) {
		points -= nextLevel;
		stars = nextLevel;
		std::cout << "Player with id: " << id << " increased level!" << std::endl;
		return true;
	}
	std::cout << "Not enough points to level up!" << std::endl;
	return false;
}

bool Player::levelUp() {

	switch (stars) {

		case Stars::one : 
			return increaseLevel(Stars::two);

		case Stars::two :
			return increaseLevel(Stars::three);

		case Stars::three :
			return increaseLevel(Stars::four);

		case Stars::four :
			return increaseLevel(Stars::five);

		default :
			return false;
	}
}