#include <climits>
#include "NearestNeighbor.h"

double calculateDistance(vector<Vertex<int>*> path){
    double distance = 0;
    for(int i = 0; i < path.size() - 1; i++){
        if (path[i]->getEdge(path[i + 1]->getInfo()) != nullptr)
            distance += path[i]->getEdge(path[i + 1]->getInfo())->getWeight();
        else
            distance += path[i]->haversineDistance(path[i + 1]);
    }
    if (path[path.size() - 1]->getEdge(path[0]->getInfo()) != nullptr)
        distance += path[path.size() - 1]->getEdge(path[0]->getInfo())->getWeight();
    else
        distance += path[path.size() - 1]->haversineDistance(path[0]);
    return distance;
}

vector<Vertex<int>*> nearestNeighbor(Graph<int> *g, int start){
    for (auto & i : g->getVertexSet())
        i->setVisited(false);

    vector<Vertex<int>*> path;
    vector<Vertex<int>*> vertices = g->getVertexSet();

    Vertex<int> *current = g->findVertex(start);
    current->setVisited(true);

    while(path.size() < vertices.size() - 1){
        double min = INT_MAX;
        Vertex<int> *next = nullptr;

        for(auto v : vertices){
            if(!v->isVisited()){
                double dist;
                if (current->getEdge(v->getInfo()) == nullptr)
                    dist = current->haversineDistance(v);
                else
                    dist = current->getEdge(v->getInfo())->getWeight();

                if(dist < min){
                    min = dist;
                    next = v;
                }
            }
        }

        if (next != nullptr) {
            path.push_back(current);
            current = next;
            current->setVisited(true);
        }
    }

    path.push_back(current);
    path.push_back(g->findVertex(start));
    return path;
}