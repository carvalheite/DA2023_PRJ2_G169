//
// Created by crvlh8 on 5/16/24.
//

#ifndef DA2023_PRJ2_G169_NEARESTNEIGHBOR_H
#define DA2023_PRJ2_G169_NEARESTNEIGHBOR_H

#include "Graph.h"

using namespace std;

vector<Vertex<int>*> nearestNeighbor(Graph<int> *g, int start);
double calculateDistance(vector<Vertex<int>*> path);
#endif //DA2023_PRJ2_G169_NEARESTNEIGHBOR_H
