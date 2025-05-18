#include <iostream>

struct Rock;
struct Paper;
struct Scissors;

struct Move {
	// 1 - win
	// 0 - draw
	// -1 - lose
	virtual int fight(const Move* other) const = 0;
	virtual int fightRock(const Rock* other) const = 0;
	virtual int fightPaper(const Paper* other) const = 0;
	virtual int fightScissors(const Scissors* other) const = 0;

	virtual ~Move() {};
};

struct Rock : Move {
	int fight(const Move* other) const override {
		// minus is needed for correct results
		return -other->fightRock(this);
	}

	int fightRock(const Rock* other) const override {
		return 0;
	}
	int fightPaper(const Paper* other) const override {
		return -1;
	}
	int fightScissors(const Scissors* other) const override {
		return 1;
	}
};

struct Paper : Move {
	int fight(const Move* other) const override {
		return -other->fightPaper(this);
	}

	int fightRock(const Rock* other) const override {
		return 1;
	}
	int fightPaper(const Paper* other) const override {
		return 0;
	}
	int fightScissors(const Scissors* other) const override {
		return -1;
	}
};

struct Scissors : Move {
	int fight(const Move* other) const override {
		return -other->fightScissors(this);
	}

	int fightRock(const Rock* other) const override {
		return -1;
	}
	int fightPaper(const Paper* other) const override {
		return 1;
	}
	int fightScissors(const Scissors* other) const override {
		return 0;
	}
};


int main() {
	Move* a = new Rock();
	Move* b = new Scissors();

	a->fight(b); // 1
}
