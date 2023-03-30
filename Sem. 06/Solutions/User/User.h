#pragma once

class User {
private:
	char* userName = nullptr;
	char* password = nullptr;

	void copyUserName(const char* userName);
	void copyPassword(const char* password);
public:
	User(const char* userName, const char* password);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	const char* getUserName() const;
	void setUserName(const char* userName);
	void setPassword(const char* password);

private:
	void copyFrom(const User& other);
	void free();
};