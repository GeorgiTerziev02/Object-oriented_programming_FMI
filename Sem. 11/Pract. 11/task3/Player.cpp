#include "Player.h"

void Player::sedID(int ID) {
	this->ID = ID;
}
void Player::setPoints(int points) {
	this->points = points;
}
void Player::setStars(Stars newStar) {
	stars = newStar;
}
void Player::missionCompleted(int points) {
	this->points += points;
}
int Player::getID()const  {
	return ID;
}
int Player::getPoints()const {
	return points;
}
Stars Player::getStars()const  {
	return stars;
}