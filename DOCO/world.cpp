#include "world.h"
#include "map.h"
#include "creaturelist.h"
#include "DOCO.h"
#include "DataParser.h"
#include <iostream>


#define DEBUG


world::world(const char* fileName)
{
	DataParser* dp = dp->getInstance(fileName);
	myMap = new map(dp->getDOCOWorldWidth(), dp->getDOCOWorldHeight());
	int DOCOcount = dp->getDOCOCount();
	clist.init(DOCOcount);
	char getDir;
	int getX, getY;
	while (dp->getDOCOData(&getDir, &getX, &getY))
	{
		DOCO a(myMap, getX, getY, 500);
		clist.addDOCO(a);
	}

}
