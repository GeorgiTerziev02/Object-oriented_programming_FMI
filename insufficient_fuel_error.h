#pragma once
#include <stdexcept>
#include "MyString.h"
class insufficient_fuel_error: public std::logic_error
{
	MyString message;
public:
	insufficient_fuel_error(const MyString& msg) : logic_error(msg.c_str()) {
	}
	const char* what()const {
		return message.c_str();
	}
};

