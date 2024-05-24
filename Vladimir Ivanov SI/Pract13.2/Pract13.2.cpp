#include <iostream>
#include "Monster.h"
#include "Minotavar.h"
#include "Kentavar.h"
#include "Sfinks.h"

int main()
{
    Monster** monstersArray = new Monster*[15];
	for (size_t i = 0; i < 15; i++)
	{
		int index = rand() % 3;
		switch (index)
		{
		case 0: monstersArray[i] = new Minotavar();
			break;
		case 1: monstersArray[i] = new Kentavar();
			break;
		case 2: monstersArray[i] = new Sfinks();
			break;
		default:
			break;
		}
	}

	monstersArray[2]->fight(monstersArray[9]);
	monstersArray[4]->fight(monstersArray[10]);
	monstersArray[5]->fight(monstersArray[1]);
	monstersArray[8]->fight(monstersArray[7]);

}