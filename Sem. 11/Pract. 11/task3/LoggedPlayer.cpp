#include "LoggedPlayer.h"


LoggedPlayer::LoggedPlayer(const char* password) {
	if (strlen(password) > 8)
		throw std::length_error("Password is too long");
	strcpy_s(this->password, password);
}
bool LoggedPlayer::levelUp() {
	if (this->getPoints() >= 256 && this->getStars() == Stars::oneStar) {
		this->setStars(Stars::twoStar);
		return true;
	}
	if (this->getPoints() >= 512 && this->getStars() == Stars::twoStar) {
		this->setStars(Stars::threeStar);
		return true;
	}
	if (this->getPoints() >= 1024 && this->getStars() == Stars::threeStar) {
		this->setStars(Stars::fourStar);
		return true;
	}
	if (this->getPoints() >= 2048 && this->getStars() == Stars::fourStar) {
		this->setStars(Stars::fiveStar);
		return true;
	}
	return false;
}
bool LoggedPlayer::logIn(const char* passwordForLogIn, int IDForLogIn)const {
	if ((strcmp(password, passwordForLogIn) == 0) && (this->getID() == IDForLogIn))
		return true;
	return false;
}