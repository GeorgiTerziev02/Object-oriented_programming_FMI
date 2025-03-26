#pragma once
#include "Zadacha.h"
#include <fstream>
const unsigned MAX_ZADACHI = 20;

class Kontrolno
{
private:
	unsigned countZadachi;
	Zadacha test[MAX_ZADACHI];



public:
	Kontrolno (unsigned countZadachi, const Zadacha* test);
	unsigned getCountZadachi() const;
	double getTestZadachaPoints(unsigned index) const ;
	void writeKontrolnoToFile(std::ofstream& out) const;
	void readKontrolnoFromFile(std::ifstream& in);
	double totalPointsKontrolno() const;
	
};





