//
// Created by crvlh8 on 5/16/24.
//

#ifndef DA2023_PRJ2_G169_SIMANNEAL_H
#define DA2023_PRJ2_G169_SIMANNEAL_H

#include "Graph.h"

using namespace std;

double calculateDistance(vector<Vertex<int>*> path, Vertex<int>* firstCity);
vector<Vertex<int>*> simulatedAnnealing(Graph<int> *g, int firstCity);

#endif //DA2023_PRJ2_G169_SIMANNEAL_H
