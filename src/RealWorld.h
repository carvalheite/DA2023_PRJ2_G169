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

/**
 * @class RealWorld
 * @brief A class to solve the Traveling Salesman Problem (TSP) using a nearest neighbor heuristic.
 */
class RealWorld {
public:
    /**
     * @brief Constructor for RealWorld class.
     */
    RealWorld();

    /**
     * @brief Destructor for RealWorld class.
     */
    ~RealWorld();

    /**
     * @brief Solves the Traveling Salesman Problem (TSP) for the given graph starting from a specified vertex.
     *
     * This function implements a heuristic approach to solve the TSP by always choosing the nearest unvisited neighbor.
     *
     * @param graph The graph representing the cities and distances between them.
     * @param start The starting vertex for the TSP tour.
     * @return A pair containing the path (vector of vertices) and the total distance of the tour.
     *
     * @throws invalid_argument if the graph is not connected.
     *
     * @complexity O(V^2), where V is the number of vertices in the graph.
     */
    pair<vector<int>, double> solveTSP(Graph<int> &graph, int start);

    /**
     * @brief Finds the nearest unvisited neighbor for the current vertex.
     *
     * This function finds the nearest unvisited neighbor of a given vertex in the graph.
     *
     * @param graph The graph representing the cities and distances between them.
     * @param current The current vertex.
     * @param visited A vector indicating whether each vertex has been visited.
     * @return The index of the nearest unvisited neighbor.
     *
     * @complexity O(E), where E is the number of edges connected to the current vertex.
     */
    int nearestNeighbor(Graph<int> &graph, int current, const std::vector<bool> &visited);
};

#endif //DA2023_PRJ2_G169_REALWORLD_H
