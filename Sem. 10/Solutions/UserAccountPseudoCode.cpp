#include "MyString/MyString.h"

class NotAuthenticatedUser {
public:
	void playGameForFun() { }
};

class AuthenticatedUser : public NotAuthenticatedUser {
	MyString password;
	MyString name;
public:
	void playGameForRank() { }
};

class PaidAccount : public AuthenticatedUser {
public:
	void buyPayToWinStuff() { }
};