#include "PremiumPlayer.h"
#include <iostream>
PremiumPlayer::PremiumPlayer(const char* name, const char* password) {
	if (strlen(password) > 8)
		throw std::length_error("The password is too long");
	this->name = MyString(name);
	strcpy_s(this->password, password);
}
bool PremiumPlayer::levelUp() {
	if (this->getPoints() >= 256 && this->getStars() == Stars::oneStar) {
		this->setStars(Stars::twoStar);
		return true;
	}
	if (this->getPoints() >= 256 && this->getStars() == Stars::twoStar) {
		this->setStars(Stars::threeStar);
		return true;
	}
	if (this->getPoints() >= 256 && this->getStars() == Stars::threeStar) {
		this->setStars(Stars::fourStar);
		return true;
	}
	if (this->getPoints() >= 256 && this->getStars() == Stars::fourStar) {
		this->setStars(Stars::fiveStar);
		return true;
	}
	return false;
}
