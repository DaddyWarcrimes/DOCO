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
#include "world.h"




int main()
{
    bool run = false;
    string dataFile = "DOCOData01.xml";
    int turns = -1;

    while (!run)
    {
        system("cls");
        string turnString;
        if (turns == -1)
        {
            turnString = "INDEFINITE";
        }
        else
        {
            turnString = to_string(turns);
        }
        
        std::cout << "Simulation will run based on datafile " << dataFile << ", for " << turnString << " turns."
            << std::endl << "1. Run with theses parameters" << std::endl << "2. Change datafile" << std::endl
            << "3. Edit turns" << std::endl;
        int selection;
        cin >> selection;
        switch (selection)
        {
        case 1:
            run = true;
            break;
        case 2:
            std::cout << "Enter new datafile name, including the file extension." << std::endl;
            cin >> dataFile;
            break;
        case 3:
            std::cout << "Enter number of turns. For indefinite, use -1." << std::endl;
            cin >> turns;
            break;
        default:
            std::cout << "Invalid selection, please try again" << std::endl;
            break;
        }
    }
    srand((unsigned int)time(0));
    world w(dataFile.c_str());
    system("cls");
    w.run(turns);


    /*previously working code
    DataParser* dp = dp->getInstance("DOCOData01.xml");

	map m(dp->getDOCOWorldWidth(),dp->getDOCOWorldHeight());

    std::cout << dp->getDOCOCount() << std::endl;

    std::cout << dp->getFoodCount() << std::endl;
    std::cout << dp->getObstacleCount() << std::endl;

    system("pause");

    for (int i = 0; i < dp->getDOCOWorldWidth() && i < dp->getDOCOWorldHeight(); i++)
    {
        m.addPellet(i, i);
    }
    system("cls");
    creaturelist l(dp->getDOCOCount());
    char getDir;
    int getX, getY;
    while (dp->getDOCOData(&getDir, &getX, &getY))
    {
        DOCO a(&m, getX, getY, 500);
        l.addDOCO(a);
    }

    for (int i = 0; i < 150; i++)
    {
        system("timeout 1 /nobreak > nul");
        system("cls");
        l.act();
        m.draw();
    }
    */
    return 0;
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
