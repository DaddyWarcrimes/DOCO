#include "creaturelist.h"
#include "DOCO.h"
#include <iostream>

#define DEBUG

creaturelist::creaturelist(int size)
{
	list = new DOCO[size];
	iterator = 0;
}
creaturelist::~creaturelist()
{

}

void creaturelist::addDOCO(DOCO newDOCO)
{
	list[iterator] = newDOCO;
	iterator++;
}

void creaturelist::act()
{
	for (int i = 0; i < iterator; i++)
	{
		list[i].act();
	}
#ifdef DEBUG
	std::cout << "Current energy : ";
	for (int i = 0; i < iterator; i++)
	{
		std::cout << i << "=" << list[i].getEnergy() << " ";
	}
	std::cout << std::endl;
#endif
	
}
