
#include <iostream>
#include <string.h>
#include "location.h"
#include "pellet.h"
#include <vector>

using namespace std;

location::location()
{
	occupant = nullptr;
	//std::cout << "location constructor\n";
}

location::~location()
{
}

void location::addDOCO(DOCO* newDOCO)
{
	occupant = newDOCO;
	return;
}

void location::removeDOCO()
{
	occupant = nullptr;
	return;
}

bool location::isOccupied()
{
	return !(occupant == nullptr);
	return false;
}

int location::pelletCount()
{
	return ((int)pellets.size());
}

void location::addPellet()
{
	if (pellets.size() == 3)
	{
		return;
	}
	pellet p; 
	pellets.push_back(p);
	return;
}

int location::feed()
{
	int sum = 0;
	for (int i = 0; i < pellets.size(); i++ )
	{
		sum += pellets.at(i).getEnergy();
	}
	pellets.clear();
	return (sum);
}