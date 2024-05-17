//
// Created by miguel on 17-05-2024.
//

#ifndef DA2023_PRJ2_G169_MENU_H
#define DA2023_PRJ2_G169_MENU_H


#include <iostream>
#include <string>
#include <iomanip>
#include "FileReader.h"
#include "Graph.h"
using namespace std;

class Menu {
private:
    Graph<int> g;
    FileReader data;
public:
    Menu();
    void run();
    void mainMenu();
    void ToyGraphsMenu();
    void RealworldGraphsMenu();
    void ExtraFullyConnectedGraphsMenu();
    void OperationsMenu(int mode);
};


#endif //DA2023_PRJ2_G169_MENU_H
