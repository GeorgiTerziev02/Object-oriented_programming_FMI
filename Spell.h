#pragma once
const size_t MAX_NAME_SYMBOLS = 25;
const size_t MAX_EFFECT_SYMBOLS = 100;

enum class SpellType {
	trap,
	buff,
	spell
};

class Spell
{
private:
	char name[MAX_NAME_SYMBOLS] ="";
	char effect[MAX_EFFECT_SYMBOLS]="";
	SpellType type;
public:
	Spell() = default;
	Spell(const char* name, const char* effect, const SpellType type);

	void setName(const char* name);
	void setEffect(const char* effect);
	void setType(const SpellType type);

	const char* getName() const;
	const char* getEffect() const;
	const SpellType& getSpellType() const;
};


