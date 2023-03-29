#include <cstring>
#include "User.h"

void copyCharArray(char*& dest, const char* source) {
	dest = new char[strlen(source) + 1];
	strcpy(dest, source);
}

User::User(const char* userName, const char* password) {
	setUserName(userName ? userName : "\0");
	setPassword(password ? password : "\0");
}

User::User(const User& other) {
	copyFrom(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

User::~User() {
	free();
}

const char* User::getUserName() const {
	return userName;
}

void User::setUserName(const char* userName) {
	if (userName == nullptr) {
		return;
	}

	if (this->userName != nullptr) {
		delete[] this->userName;
	}

	copyCharArray(this->userName, userName);
}

void User::setPassword(const char* password) {
	if (password == nullptr) {
		return;
	}

	if (this->password != nullptr) {
		delete[] this->password;
	}

	copyCharArray(this->password, password);
}

void User::copyFrom(const User& other) {
	copyCharArray(this->userName, other.userName);
	copyCharArray(this->password, other.password);
}

void User::free() {
	delete[] userName;
	delete[] password;
	userName = password = nullptr;
}