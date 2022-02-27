#include "map.h"
#include "location.h"
#include <iostream>
#include <string.h>

using namespace std;

map::map()
{
	maxX = 28;
	maxY = 24;
	populateGrid();
}

map::~map()
{}

map::map(int mx, int my)
{
	maxX = mx;
	maxY = my;
	populateGrid();
}

void map:: populateGrid()
{
	grid = new location*[maxY];
	for (int i = 0; i < maxX; i++)
	{
		grid[i] = new location[maxX];
		for (int j = 0; j < maxY; j++)
		{
			location t;
			grid[i][j] = t;
		}
	}
}

int map::getMaxX()
{
	return maxX;
}

int map::getMaxY()
{
	return maxY;
}

void map::addDOCO(DOCO* newDOCO, int x, int y)
{
	grid[x][y].addDOCO(newDOCO);
}

void map::removeDOCO(int x, int y)
{
	grid[x][y].removeDOCO();
}

bool map::inRange(int x, int y)
{
	//std::cout << "Range check: " << x << "<" << maxX << " " << y << "<" << maxY << std::endl;
	return (x >= 0 && y >= 0 && x < maxX && y < maxY);
}

bool map::isOccupied(int x, int y)
{
	return grid[x][y].isOccupied();
}

void map::addPellet(int x, int y)
{
//	std::cout << "Adding pellet to (" << x << ',' << y << ')' <<std::endl;
	grid[x][y].addPellet();
	return;
}

void map::draw()
{
	std::cout << "  ";
	for (int i = 0; i < maxX; i++)
	{
		std::cout << i / 10;
	}
	std::cout << std::endl << "  ";
	for (int i = 0; i < maxX; i++)
	{
		std::cout << i % 10;
	}
	std::cout << endl;
	for (int i = 0; i < maxY && i < 100; i++)
	{
		if (i < 10)
		{
			std::cout << ' ';
		}
		cout << i;

		for (int j = 0; j < maxX; j++)
		{
			if (grid[j][i].isOccupied())
			{
				std::cout << "*";
			}
			else if (pelletCount(j, i) == 0)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;

	}
	
}
int map::pelletCount(int x, int y)
{
	return (grid[x][y].pelletCount());
}
int map::feed(int x, int y)
{
	return grid[x][y].feed();
}
