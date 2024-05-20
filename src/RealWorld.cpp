#include "RealWorld.h"

RealWorld::RealWorld() {}

RealWorld::~RealWorld() {}

std::pair<std::vector<int>, double> RealWorld::solveTSP(Graph<int> &graph, int start) {
    std::vector<bool> visited(graph.getNumVertex(), false);
    std::vector<int> path;
    double total_dist = 0.0;
    int current = start;
    while (path.size() < graph.getNumVertex()) {
        path.push_back(current);
        visited[current] = true;
        int next_node = nearestNeighbor(graph, current, visited);
        if (next_node == -1) {
            for (auto edge : graph.findVertex(current)->getAdj()) {
                if (edge->getDest()->getInfo() == next_node){
                    total_dist += edge->getWeight();
                }
            }
            path.push_back(start);
            break;
        }
        for (auto edge : graph.findVertex(current)->getAdj()) {
            if (edge->getDest()->getInfo() == next_node){
                total_dist += edge->getWeight();
            }
        }        current = next_node;
    }
    if (isnan(total_dist)  || isinf(total_dist)) {
        cout << "Graph is not connected" << endl;
    }
    return {path, total_dist};
}

int RealWorld::nearestNeighbor(Graph<int> &graph, int current, const std::vector<bool> &visited) {
    double nearestDist = std::numeric_limits<double>::max();
    int nearestNode = -1;

    for (auto edge : graph.findVertex(current)->getAdj()) {
        int nextNode = edge->getDest()->getInfo();
        double dist = edge->getWeight();
        if (!visited[nextNode] && dist < nearestDist) {
            nearestDist = dist;
            nearestNode = nextNode;
        }
    }
    return nearestNode;
}

