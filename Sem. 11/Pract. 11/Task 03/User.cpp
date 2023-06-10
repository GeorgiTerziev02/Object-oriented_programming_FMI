#include "User.h"

void User::setPassword(const MyString& password) {

	if (password.length() > PASSWORD_MAX_LENGTH) {
		throw std::length_error("Password is way too long!");
	}

	this->password = password;
}

User::User(int id, const MyString& password): Player(id){
	setPassword(password);
	isLoggedIn = false;
}

void User::login(int id, const MyString& password) {

	if (this->password == password && this->id == id) {
		isLoggedIn = true;
		std::cout << "User with id: " << id << " successfully logged in!" << std::endl;
	}
	else {
		std::cout << "Unsuccessful login! Incorrect id/password!" << std::endl;
	}
}

void User::checkIfLoggedIn() const {
	if (!isLoggedIn) {
		throw std::exception("User not logged in!");
	}
}

void User::completeMission(unsigned short missionPoints) {
	checkIfLoggedIn();
	Player::completeMission(missionPoints);
}

bool User::levelUp() {
	checkIfLoggedIn();
	return Player::levelUp();
}