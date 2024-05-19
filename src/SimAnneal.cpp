//
// Created by crvlh8 on 5/16/24.
//

#include "SimAnneal.h"
#include <random>
#include "Graph.h"

using namespace std;

double calculateDistance(vector<Vertex<int>*> path, Vertex<int>* firstCity) {
    double cost = 0;
    cost += firstCity->haversineDistance(path[0]);
    for (int i = 0; i < path.size() - 2; i++) {
        cost += path[i]->haversineDistance(path[i + 1]);
    }
    cost += path[path.size() - 1]->haversineDistance(firstCity);
    return cost;
}

vector<Vertex<int>*> simulatedAnnealing(Graph<int> *g, int firstCity) {
    Vertex<int>* firstVertex = g->findVertex(firstCity);
    int cityNum = g->getVertexSet().size() - 1;
    vector<Vertex<int>*> currentPath, newPath;
    double currentCost, newCost, temperature = 10000, coolingRate = 0.1;

    for (auto vertex : g->getVertexSet()) {
        if (vertex != firstVertex)
            currentPath.push_back(vertex);
    }

    random_device rd;
    mt19937 gen(rd());
    shuffle(currentPath.begin(), currentPath.end(), gen);
    currentCost = calculateDistance(currentPath, firstVertex);

    uniform_real_distribution<double> distribution(0.0, 1.0);

    while (temperature > 1) {
        newPath = currentPath;
        int pos1, pos2;
        do {
            pos1 = rand() % cityNum;
            pos2 = rand() % cityNum;
        } while (pos1 == pos2);

        if (pos1 == firstCity or pos2 == firstCity)
            continue;
        while (pos1 == pos2)
            pos2 = rand() % cityNum;

        swap(newPath[pos1], newPath[pos2]);
        newCost = calculateDistance(newPath, firstVertex);

        double delta = newCost - currentCost;

        if (delta < 0 || exp(-delta / temperature) > distribution(gen)) {
            currentPath = newPath;
            currentCost = newCost;
        }

        temperature -= coolingRate;
    }

    return currentPath;
}