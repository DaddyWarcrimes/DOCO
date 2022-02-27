#pragma once
#include "map.h"


class map;
class creaturelist;
class DOCO;
class DataParser;

class world
{
private: 
	map* myMap;
	creaturelist clist;

public:
	world(const char* fileName)
};
