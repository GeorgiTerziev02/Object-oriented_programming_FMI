#include "User.h"

User::User(const MyString &userName, const MyString &password)
    : userName(userName), password(password)
{ }

const MyString& User::getUserName() const {
    return userName;
}

void User::setUserName(const MyString& userName) {
    if(userName.getLength() == 0) {
        return;
    }

    this->userName = userName;
}
void User::setPassword(const MyString& password) {
    if(password.getLength() == 0) {
        return;
    }

    this->password = password;
}