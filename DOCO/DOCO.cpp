#include "DOCO.h"
#include <random>
#include "map.h"
#include <string.h>
#include <iostream>
//#define DEBUG

using namespace std;

DOCO::DOCO()
{
	energy = 500;
	azimuthX = rand() % 2 - 1;
	azimuthY = rand() % 2 - 1;
	if (azimuthX == 0 && azimuthY == 0)
	{
		azimuthX += 1;
	}
}
DOCO::~DOCO()
{
}
DOCO::DOCO(map* newMap, int x, int y, int e)
{
	myMap = newMap;
	myMap->addDOCO(this, x, y);
	mapX = x;
	mapY = y;
	energy = e;
	azimuthX = rand() % 2 - 1;
	azimuthY = rand() % 2 - 1;
	if (azimuthX == 0 && azimuthY == 0)
	{
		azimuthX += 1;
	}
}

void DOCO::setLocation(int x, int y)
{
	mapX = x;
	mapY = y;
	return;
}
void DOCO::act()
{
	if (mapX == -1)
	{
		return;
	}
	
	//check for pellets
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!myMap->inRange(mapX + i, mapY + j))
			{
				continue;
			}
			else if (myMap->pelletCount(i + mapX,j + mapY) > 0)
			{
				energy -= 10;
				myMap->removeDOCO(mapX, mapY);
				mapX += i;
				mapY += j;
				myMap->addDOCO(this, mapX, mapY);
				addEnergy(myMap->feed(mapX, mapY));
				return;
			}
		}
	}
	if (!myMap->inRange(mapX + azimuthX,mapY + azimuthY) || myMap->isOccupied(mapX + azimuthX, mapY + azimuthY))
	{
		alterCourse();
#ifdef DEBUG
		std::cout << "Change course" << std::endl;
#endif
		/*myMap->removeDOCO(mapX, mapY);
		mapX += azimuthX;
		mapY += azimuthY;
		myMap->addDOCO(this, mapX, mapY);*/
		
	}
	move();

	// Death 
	if (energy == 0)
	{
		myMap->removeDOCO(mapX, mapY);
		mapX = -1; //skip future activity
	}
	return;
}

void DOCO::addEnergy(unsigned int e)
{
	energy += e;
	return;
}
void DOCO::alterCourse()
{
	//printAzimuth();
	struct pair {
		int x;
		int y;
	};
	vector<pair> pairs;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (myMap->inRange(mapX + i, mapY + j) && !myMap->isOccupied(mapX + i, mapY + j))
			{
				pair t;
				t.x = i;
				t.y = j;
				pairs.push_back(t);
			}
		}
	}

	if (pairs.size() == 0)
	{
		azimuthX = 0;
		azimuthY = 0;
	}
	else
	{
		pair select = pairs.at(rand() % pairs.size());
		azimuthX = select.x;
		azimuthY = select.y;
		//printAzimuth();
	}

	
	return;
}

string DOCO::getAzimuth()
{
//	std::cout << '(' << azimuthX << ',' << azimuthY << ')' << std::endl;
	std::string out;
	out.append("(");
	out.append(to_string(azimuthX));
	out.append(",");
	out.append(to_string(azimuthY));
	out.append(")");

	return out;
}

unsigned int DOCO::getEnergy()
{
	return energy;
}

void DOCO::move()
{
#ifdef DEBUG
	std::cout << "Standard move " << getAzimuth() << std::endl;
#endif
	if (azimuthX == 0 && azimuthY == 0)
	{
#ifdef DEBUG
		std::cout << "No direction\n";
#endif
		return;
	}
	else
	{
		energy -= 10;
		myMap->removeDOCO(mapX, mapY);
		mapX += azimuthX;
		mapY += azimuthY;
		myMap->addDOCO(this, mapX, mapY);
	}
}
