// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "location.h"
#include "creature.h"
#include "map.h"
#include "DataParser.h"
#include "DOCO.h"
#include <random>
#include "creaturelist.h"




int main()
{
    srand((unsigned int)time(0));
    DataParser* dp = dp->getInstance("DOCOData01.xml");

	map m(dp->getDOCOWorldWidth(),dp->getDOCOWorldHeight());

    std::cout << dp->getDOCOCount() << std::endl;

    std::cout << dp->getFoodCount() << std::endl;
    std::cout << dp->getObstacleCount() << std::endl;

    system("pause");

    for (int i = 0; i < dp->getDOCOWorldWidth() && i < dp->getDOCOWorldHeight(); i++)
    {
        m.addPellet(i, i);
       // std::cout << m.pelletCount(i, i) << std::endl;
    }
    system("cls");
    /*DOCO a(&m, , 20, 500);
    DOCO b(&m, 14, 3, 500);
    DOCO d(&m, 2, 3, 500);*/
    creaturelist l(dp->getDOCOCount());
    char getDir;
    int getX, getY;
    while (dp->getDOCOData(&getDir, &getX, &getY))
    {
        DOCO a(&m, getX, getY, 500);
        l.addDOCO(a);
    }
    
   //   return 0;
    /*l.addDOCO(a);
    l.addDOCO(b);
    l.addDOCO(d);*/
    m.draw();
    for (int i = 0; i < 150; i++)
    {
        system("timeout 1 /nobreak > nul");
        system("cls");
        //a.act();
        //b.act();
        //d.act();
        l.act();
        m.draw();
        //std::cout << "Current energy a:" << a.getEnergy() << " b: " << b.getEnergy() << " d: " << d.getEnergy() << std::endl;
    }
    
    //std::cout << m.inRange(0,1) << "-" << m.inRange(-1,0) << m.inRange(1,-1) << m.inRange(80,1) << m.inRange(1,90) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
