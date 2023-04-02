#include "Spell.h"
#include <iostream>
#pragma warning(disable:4996)

Spell::Spell(const char* name, const char* effect, const SpellType type) {
	setName(name);
	setEffect(effect);
	setType(type);
}

void Spell::setName(const char* name) {
	if (strlen(name) < MAX_NAME_SYMBOLS) {
		strcpy(this->name, name);
	}
}
void Spell::setEffect(const char* effect) {
	if (strlen(effect) < MAX_EFFECT_SYMBOLS) {
		strcpy(this->effect, effect);
	}
}
void Spell::setType(const SpellType type) {
	this->type = type;
}

const char* Spell::getName() const {
	return name;
}
const char* Spell::getEffect() const {
	return effect;
}
const SpellType& Spell::getSpellType() const {
	return type;
}