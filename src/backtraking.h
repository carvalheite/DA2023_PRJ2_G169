/**
 * @file DijkstraBacktracking.h
 * @brief This file contains the implementation of Dijkstra's algorithm and a backtracking algorithm for finding the shortest Hamiltonian cycle in a graph.
 */

#include <vector>
#include <iostream>
#include <numeric>
#include "../src/Graph.h"
#include "../src/MutablePriorityQueue.h"
#include "Timer.h"

#define DIJKSTRA_OPTIMIZATION_MIN_HEIGHT (8) // Minimum distance in levels from leaf nodes in which Dijkstra is called.

/**
 * @brief Runs Dijkstra's algorithm on a subgraph of the given graph starting from a specified vertex.
 *
 * @tparam T The type of the vertices.
 * @param g The graph.
 * @param startIndex The index of the starting vertex.
 */
template <class T>
void dijkstra_subgraph(Graph<T>& g, int startIndex) {
    MutablePriorityQueue<Vertex<T>> q;
    for (Vertex<T>* v : g.getVertexSet()) {
        if (!v->isVisited()) {
            v->setDist(std::numeric_limits<double>::infinity());
            v->setPath(nullptr);
        }
    }
    Vertex<T>* startVertex = g.findVertex(startIndex);
    startVertex->setDist(0);
    q.insert(startVertex);
    while (!q.empty()) {
        Vertex<T>* curr = q.extractMin();
        for (Edge<T>* e : curr->getAdj()) {
            Vertex<T>* eDest = e->getDest();
            if (eDest->isVisited()) {
                continue;
            }
            double newDist = curr->getDist() + e->getWeight();
            if (eDest->getDist() < newDist) {
                continue;
            }
            eDest->setDist(newDist);
            if (eDest->getPath() == nullptr) {
                q.insert(eDest);
            } else {
                q.decreaseKey(eDest);
            }
            eDest->setPath(e);
        }
    }
}

/**
 * @brief Runs Dijkstra's algorithm on the entire graph starting from a specified vertex.
 *
 * @tparam T The type of the vertices.
 * @param g The graph.
 * @param startIndex The index of the starting vertex.
 */
template <class T>
void dijkstra(Graph<T>& g, int startIndex) {
    MutablePriorityQueue<Vertex<T>> q;
    for (Vertex<T>* v : g.getVertexSet()) {
        v->setDist(std::numeric_limits<double>::infinity());
        v->setPath(nullptr);
    }
    Vertex<T>* startVertex = g.findVertex(startIndex);
    startVertex->setDist(0);
    q.insert(startVertex);
    while (!q.empty()) {
        Vertex<T>* curr = q.extractMin();
        for (Edge<T>* e : curr->getAdj()) {
            Vertex<T>* eDest = e->getDest();
            double newDist = curr->getDist() + e->getWeight();
            if (eDest->getDist() < newDist) {
                continue;
            }
            eDest->setDist(newDist);
            if (eDest->getPath() == nullptr) {
                q.insert(eDest);
            } else {
                q.decreaseKey(eDest);
            }
            eDest->setPath(e);
        }
    }
}

/**
 * @brief Recursively visits vertices to find the shortest Hamiltonian cycle using backtracking and Dijkstra's algorithm for optimization.
 *
 * @tparam T The type of the vertices.
 * @param g The graph.
 * @param bestPath The vector that stores the best path found so far.
 * @param bestDistance The best distance found so far.
 * @param path The current path being explored.
 * @param distance The current distance of the path being explored.
 */
template <class T>
void recursiveVisit(Graph<T>& g, std::vector<int>& bestPath, double& bestDistance, std::vector<int>& path, double distance) {
    Vertex<T>* v = nullptr;
    for (auto x : g.getVertexSet()) {
        if (x->getInfo() == path.back()) v = x;
    }
    if (v->getDist() >= (bestDistance - distance)) // Current node cannot complete cycle in less distance than bestPath.
        return; // Pruned.
    if (path.size() == g.getNumVertex()) { // Completed cycle.
        if (path[1] > path.back())
            return;
        Edge<T>* e = nullptr;
        for (auto edge : v->getAdj()) {
            if (edge->getDest()->getInfo() == 0) {
                e = edge;
                break;
            }
        }
        if (e == nullptr) {
            return; // Last vertex in path cannot reach starting node.
        }
        distance += e->getWeight();

        if (distance < bestDistance) {
            std::copy(path.begin(), path.end(), bestPath.begin());
            bestDistance = distance;
        }
        return;
    }
    v->setVisited(true);
    if (g.getNumVertex() - path.size() == DIJKSTRA_OPTIMIZATION_MIN_HEIGHT) { // Does not get broken in subbranches
        dijkstra_subgraph(g, path.front()); // Better pruning.
    }
    for (auto edge : v->getAdj()) {
        if (edge->getDest()->isVisited())
            continue; // Vertex already in path;
        if (g.getNumVertex() - path.size() > DIJKSTRA_OPTIMIZATION_MIN_HEIGHT) { // Needs calling again as subbranches will overwrite it.
            dijkstra_subgraph(g, path.front()); // Better pruning.
        }
        double nextDistance = distance + edge->getWeight();
        if (nextDistance < bestDistance) { // Maybe redundant?
            path.push_back(edge->getDest()->getInfo());
            recursiveVisit(g, bestPath, bestDistance, path, nextDistance);
            path.pop_back();
        }
    }
    v->setVisited(false);
}

/**
 * @brief Finds the shortest Hamiltonian cycle in the graph using a backtracking approach with Dijkstra's optimization.
 *
 * @tparam T The type of the vertices.
 * @param g The graph.
 * @param bestPath The vector that will store the best path found.
 * @return The distance of the shortest Hamiltonian cycle found.
 */
template <class T>
double backtracking(Graph<T>& g, std::vector<int>& bestPath) {
    for (auto v: g.getVertexSet()) {
        v->setVisited(false);
    }
    Timer timer;
    timer.start();
    bestPath.resize(g.getNumVertex());
    dijkstra(g, 0);
    std::iota(bestPath.begin(), bestPath.end(), 0);
    std::vector<int> tempPath = {0};
    tempPath.reserve(g.getNumVertex());
    dijkstra(g, 0);
    double bestDistance = std::numeric_limits<double>::infinity();
    recursiveVisit(g, bestPath, bestDistance, tempPath, 0);
}