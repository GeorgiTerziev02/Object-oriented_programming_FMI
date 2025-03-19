#pragma once
#include <fstream>
const unsigned MAX_TITLE = 64;
class Game
{
public:

	Game();
	Game(const char* title, double price, bool isAvailable);

	const char* getTitle() const;
	bool setTitle(const char* title);

	double getPrice() const;
	bool setPrice(double price);

	bool getAvailability() const;
	bool setAvailability(bool avail);

	bool saveGameToFile(std::ofstream& out) const;
	bool loadGameFromFile(std::ifstream& in);

	bool isFree() const;	
	void print() const;

private:
	char title[MAX_TITLE];
	double price;
	bool isAvailable;

};

