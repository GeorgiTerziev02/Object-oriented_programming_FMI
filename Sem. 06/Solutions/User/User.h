#pragma once
#include "../MyString/MyString.h"

class User {
private:
    MyString userName;
    MyString password;
public:
    // No need of Big4(rule of three) the default behaviour is enough
    User(const MyString& userName, const MyString& password);

    const MyString& getUserName() const;
    // No getter for password, we don't want to expose it

    void setUserName(const MyString& userName);
    void setPassword(const MyString& password);
};