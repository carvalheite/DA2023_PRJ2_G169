#ifndef DA2023_PRJ2_G169_REALWORLD_H
#define DA2023_PRJ2_G169_REALWORLD_H

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include "Graph.h"
using namespace std;

class RealWorld {
public:
    RealWorld();
    ~RealWorld();

    pair<vector<int>, double> solveTSP(Graph<int> &graph, int start);
    int nearestNeighbor(Graph<int> &graph, int current, const std::vector<bool> &visited);
    vector<int> twoOpt(const vector<int> &path, Graph<int> &graph);

private:
};

#endif //DA2023_PRJ2_G169_REALWORLD_H
