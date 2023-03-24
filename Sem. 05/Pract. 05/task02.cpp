#include <iostream>
#include "Date.h"

int main()
{
	Date d1(31, 3, 2014); // 31.03.2014

	Date d2; //01.01.2000

	d1.addDays(1); // 01.04.2014

	d1.removeDays(1); //31.03.2014

	std::cout << d1.daysToChristmas() << std::endl;//269

	std::cout << d1.isLeap() << std::endl; //false (2014 is not a leap year)

	std::cout << d1.isAfter(d2); //false
}
