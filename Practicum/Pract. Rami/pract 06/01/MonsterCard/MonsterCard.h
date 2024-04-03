#pragma once

class MonsterCard {
	char* name = nullptr;
	unsigned attackPoints = 0;
	unsigned defencePoints = 0;

	void copyName(const char* newName);
	void copyFrom(const MonsterCard& other);
	void free();

public:
	MonsterCard() = default;
	MonsterCard(const char* name, unsigned attack, unsigned defence);
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	void setName(const char* newName);
	void setAttack(unsigned attack);
	void setDefence(unsigned defence);

	bool isEmpty() const;
	void print() const;
};

