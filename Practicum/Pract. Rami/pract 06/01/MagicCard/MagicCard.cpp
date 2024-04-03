#include "MagicCard.h"

#include <iostream>
#pragma warning(disable: 4996);

MagicCard::MagicCard(MagicType type, const char* name, const char* effect) {
	this->type = type;

	if (strlen(name) < MAX_NAME_SIZE) {
		strcpy(this->name, name);
	}

	if (strlen(effect) < MAX_EFFECT_SIZE) {
		strcpy(this->effect, effect);
	}
}

bool MagicCard::isEmpty() const {
	if (type == MagicType::Unknown && strcmp(name, "") == 0 && strcmp(effect, "") == 0) {
		return true;
	}

	return false;
}

void MagicCard::print() const {
	std::cout << name << ": " << effect << ", type: " << (int)type << std::endl;
}
