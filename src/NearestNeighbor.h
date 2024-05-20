//
// Created by crvlh8 on 5/16/24.
//

#ifndef DA2023_PRJ2_G169_NEARESTNEIGHBOR_H
#define DA2023_PRJ2_G169_NEARESTNEIGHBOR_H

#include "Graph.h"

using namespace std;

/**
 * @brief Finds the approximate nearest neighbor path using the greedy algorithm.
 *
 * This function calculates the approximate nearest neighbor path starting from the specified vertex
 * in the given graph using the greedy algorithm. It returns a vector of vertices representing the
 * path in the order they are visited.
 *
 * @param g Pointer to the graph.
 * @param start The starting vertex for the path.
 * @return A vector of vertices representing the approximate nearest neighbor path.
 *
 * @complexity O(V^2), where V is the number of vertices in the graph.
 */
vector<Vertex<int>*> nearestNeighbor(Graph<int> *g, int start);

/**
 * @brief Calculates the total distance of a given path.
 *
 * This function calculates the total distance of a given path represented by a vector of vertices.
 * It considers the weights of edges between consecutive vertices if available, otherwise it calculates
 * the Haversine distance between the vertices.
 *
 * @param path The path for which distance is to be calculated.
 * @return The total distance of the path.
 *
 * @complexity O(n), where n is the number of vertices in the path.
 */
double calculateDistance(vector<Vertex<int>*> path);

#endif //DA2023_PRJ2_G169_NEARESTNEIGHBOR_H
