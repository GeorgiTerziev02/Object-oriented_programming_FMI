#pragma once
const unsigned short MAX_DESCRIPTION_LENGTH = 1024;
const unsigned short MAX_PASSWORD_LENGTH = 64;

class Secret {
	char _taskDescription[MAX_DESCRIPTION_LENGTH + 1]{};
	char _password[MAX_PASSWORD_LENGTH + 1]{};
	mutable size_t _failedLogins = 0;
	
public:
	Secret(const char* taskDescription, const char* password);
	Secret() = default;

	const char* getTask(const char* pwd) const;
	void setPassword(const char* newPassword, const char* oldPassword);
	void setTask(const char* newTask, const char* passwd);
	size_t getLoginFails() const;
};
