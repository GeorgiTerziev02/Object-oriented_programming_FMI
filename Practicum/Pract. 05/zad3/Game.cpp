#include "Game.h"
#include <cstring>
#include <iostream>



Game::Game() : price(0), isAvailable(false) 
{
	
}
Game::Game(const char* title, double price, bool isAvailable)
{
	if (setTitle(title)) std::cerr << "Failed due to bad title\n";
	if (setPrice(price)) std::cerr << "Failed negative  price\n";
	setAvailability(isAvailable);
}

const char* Game::getTitle() const
{
	return this->title;
}

bool Game::setTitle(const char* title)
{
	if (!title || title[0] == '\0') return false; 

	strncpy_s(this->title, title, MAX_TITLE - 1);
	this->title[MAX_TITLE - 1] = '\0'; 
	return true;
}


double Game::getPrice() const
{
	return this->price;
}
bool Game::setPrice(double price)
{
	if (price >= 0)
	{
		this->price = price;
		return true;
	}
	 return false;
}

bool Game::getAvailability() const
{
	return this->isAvailable;
}
bool Game::setAvailability(bool avail)
{
	this->isAvailable = avail;
	return true;
}

bool Game::isFree() const
{
	return isAvailable;
}
void Game::print() const
{
	std::cout << "Title is " << this->title << " " << "Price is " << this->price << " ";
	isAvailable ? std::cout << "Its available" : std::cout << "Its not available\n";
}

bool Game::saveGameToFile(std::ofstream& out) const
{
	out << title << "|" << price << " " <<  isAvailable << "\n";
	if (!out)
	{
		std::cerr  << "Error writing one game from the file\n";
		return false;
	}
}
bool Game::loadGameFromFile(std::ifstream& in)
{
	in.getline(title, 64, '|');
	in >> price >> isAvailable;
	
	if (!in && !in.eof())
	{
		std::cerr << "Error reading one game from the file\n";
		return false;
	}
	return true;
}
