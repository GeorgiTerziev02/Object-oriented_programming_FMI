#pragma once

class Monster
{
private:
	char* name;
	size_t attackPoints;
	size_t defensePoints;
	
	void copy(const Monster& other);
	void free();
public:
	Monster() = default;
	Monster(const char* name,size_t attackPoints,size_t defensePoints);
	Monster(const Monster& other);

	void setName(const char* name);
	void setAttackPoints(size_t attackPoints);
	void setDefensePoints(size_t defensePoints);

	const char* getName() const;
	size_t getAttackPoints() const;
	size_t getDefensePoints() const;

	Monster& operator=(const Monster& other);
	~Monster();
};

