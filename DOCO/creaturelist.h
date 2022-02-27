#pragma once
class DOCO;

class creaturelist
{
private:
	DOCO* list;
	int iterator;

public:
	creaturelist(int size);
	~creaturelist();
	void addDOCO(DOCO newDOCO);
	void act();
};

