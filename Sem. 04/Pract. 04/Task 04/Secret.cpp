#include "Secret.h"
#include <cstring>
#pragma warning(disable : 4996)

Secret::Secret(const char* taskDescription, const char* password) {
	strcpy(this->_taskDescription, taskDescription);
	strcpy(this->_password, password);
	_failedLogins = 0;
}

const char* Secret::getTask(const char* pwd) const {
	if (strcmp(this->_password, pwd) == 0) {
		return this->_taskDescription;
	}

	this->_failedLogins++;
	return "";
}

void Secret::setPassword(const char* newPassword, const char* oldPassword) {
	if (strcmp(this->_password, oldPassword) == 0) {
		strcpy(this->_password, newPassword);
	}
	else {
		this->_failedLogins++;
	}
}

void Secret::setTask(const char* newTask, const char* passwd) {
	if (strcmp(this->_password, passwd) == 0) {
		strcpy(this->_taskDescription, newTask);
	}
	else {
		this->_failedLogins++;
	}
}

size_t Secret::getLoginFails() const {
	return this->_failedLogins;
}