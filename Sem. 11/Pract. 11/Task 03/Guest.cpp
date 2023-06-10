#include "Guest.h"
#include <iostream>

unsigned short Guest::MINUTES_ALLOWED = 300;

Guest::Guest(int id): Player(id) {
	minutesLeft = MINUTES_ALLOWED;
}

bool Guest::levelUp() {
	std::cout << "Guest players can't level up!" << std::endl;
	return false;
}