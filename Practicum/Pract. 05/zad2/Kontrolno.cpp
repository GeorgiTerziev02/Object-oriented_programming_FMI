#include "Kontrolno.h"
#include <iostream>




Kontrolno::Kontrolno(unsigned countZadachi, const Zadacha* test)
{
	this->countZadachi = (countZadachi <= MAX_ZADACHI) ? countZadachi : MAX_ZADACHI;

	if (test) 
	{ 
		for (unsigned i = 0; i < this->countZadachi; i++) 
		{
			this->test[i] = test[i];
		}
	}
	else 
	{ 
		for (unsigned i = 0; i < this->countZadachi; i++) 
		{
			this->test[i] = Zadacha();
		}
	}
}

double Kontrolno::getTestZadachaPoints(unsigned index) const
{
	if (index >= countZadachi)
	{
		std::cerr << "Invalid index";
		return -1;
	}
	return this->test[index].getPoints();
}

unsigned Kontrolno::getCountZadachi() const
{
	return this->countZadachi;
}

void Kontrolno::writeKontrolnoToFile(std::ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(&*this), sizeof(Kontrolno));
	if (!out)
	{
		std::cerr << "Problem writing Kontrolno to file\n";
		return;
	}
}
void Kontrolno::readKontrolnoFromFile(std::ifstream& in)
{
	in.read(reinterpret_cast<char*>(&*this), sizeof(Kontrolno));
	if (!in)
	{
		std::cerr << "Problem reading Kontrolno to file\n";
		return;
	}
}
double Kontrolno::totalPointsKontrolno() const
{
	double total = 0;
	for (unsigned i = 0; i < countZadachi; i++)
	{
		total += test[i].getPoints();
	}
	return total;
}
