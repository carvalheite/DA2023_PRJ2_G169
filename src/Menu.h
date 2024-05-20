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
#include "RealWorld.h"
#include "NearestNeighbor.h"
#include <chrono>
#include "Timer.h"
#include "2approximation.h"
#include "backtraking.h"
using namespace std;

class Menu {
private:
    Graph<int> g;
    FileReader data;
public:
    /**
    * @brief Constructs the Menu and initializes the Graph and DataHandler.
    */
    Menu();

    /**
    * @brief Runs the main menu.
    */
    void run();
    /**
     * @brief Displays the main menu and handles user input.
     */

    void mainMenu();

    /**
    * @brief Displays the Toy Graphs menu and handles user input.
    */
    void ToyGraphsMenu();

    /**
    * @brief Displays the Real-world Graphs menu and handles user input.
    */
    void RealworldGraphsMenu();

    /**
    * @brief Displays the Extra Fully Connected Graphs menu and handles user input.
    */
    void ExtraFullyConnectedGraphsMenu();

    /**
    * @brief Displays the Operations menu and handles user input.
    *
    * @param mode The mode indicating the current type of graph being used.
    */
    void OperationsMenu(int mode);

    /**
    * @brief Runs the TSP in the Real World algorithm and displays the result.
    *
    * @param start The starting vertex for the TSP algorithm.
    */
    void runTSPAlgorithm(int start);
};


#endif //DA2023_PRJ2_G169_MENU_H


