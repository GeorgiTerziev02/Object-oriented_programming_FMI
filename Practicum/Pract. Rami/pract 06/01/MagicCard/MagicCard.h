#pragma once

constexpr size_t MAX_NAME_SIZE = 25;
constexpr size_t MAX_EFFECT_SIZE = 100;

enum class MagicType {
	Trap,
	Buff,
	Spell,
	Unknown
};

class MagicCard {
	MagicType type = MagicType::Unknown;
	char name[MAX_NAME_SIZE] = {};
	char effect[MAX_EFFECT_SIZE] = {};

public:
	MagicCard() = default;
	MagicCard(MagicType type, const char* name, const char* effect);

	bool isEmpty() const;
	void print() const;
};

