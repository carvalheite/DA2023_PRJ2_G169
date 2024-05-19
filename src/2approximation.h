#include <vector>
#include <iostream>
#include <numeric>
#include <set>
#include "../src/Graph.h"
#include "../src/MutablePriorityQueue.h"
#include "./MutablePriorityQueue.h"

using namespace std;



template <class T>
std::vector<Vertex<T> *> primMST(Graph<T> &graph,double &tourDistance) {
    Timer timer;
    timer.start();
    for (Vertex<T>* vertex : graph.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setDist(std::numeric_limits<double>::infinity());
    }

    std::vector<Vertex<T>*> mst;
    Vertex<T>* startingNode = graph.findVertex(0);
    startingNode->setDist(0);

    MutablePriorityQueue<Vertex<T>> priorityQueue;
    priorityQueue.insert(startingNode);

    while (!priorityQueue.empty()) {
        Vertex<T>* processingNode = priorityQueue.extractMin();
        if (processingNode->isVisited()) continue;

        processingNode->setVisited(true);
        mst.push_back(processingNode);

        vector<Edge<T>*> adjacent = processingNode->getAdj();
        for (Edge<T>* neighbourEdge : adjacent) {
            Vertex<T>* neighbour = neighbourEdge->getDest();
            double weight = neighbourEdge->getWeight();

            if (!neighbour->isVisited() && weight < neighbour->getDist()) {
                if(std::numeric_limits<double>::infinity()==neighbour->getDist())priorityQueue.insert(neighbour);
                neighbour->setDist(weight);
                neighbour->setPath(neighbourEdge);
                priorityQueue.decreaseKey(neighbour);
            }
        }
    }

    //create a graph representing the mst
    Graph<int> mstGraph;
    for(Vertex<T>* vertex : mst){
        mstGraph.addVertex(vertex->getInfo());
        if(vertex->getPath()!= nullptr)mstGraph.addBidirectionalEdge(vertex->getPath()->getOrig()->getInfo(),vertex->getPath()->getDest()->getInfo(),vertex->getPath()->getWeight());
    }

    // Step 2: Create a tour by traversing the MST using DFS
    auto tour = mstGraph.dfs();
    tour.push_back(mstGraph.findVertex(0)->getInfo());

    //Tour by vertexes
    vector<Vertex<T>*> tourByPointer;
    for(auto v : tour){
        Vertex<T>* tempVertex =mstGraph.findVertex(v);
        tourByPointer.push_back(tempVertex);
        tempVertex->setVisited(false);
    }

    //remove duplicates
    vector<Vertex<T>*> HamiltonianCycle;
    for(auto v : tourByPointer){
        if(!v->isVisited()){
            HamiltonianCycle.push_back(v);
        }
    }


    //tour Distance
    for(size_t iter = 0;iter<HamiltonianCycle.size()-1;iter++){
        for(Edge<T>* edge : HamiltonianCycle[iter]->getAdj()){
            if(edge->getDest()==HamiltonianCycle[iter+1]){
                tourDistance+=edge->getWeight();
            }
        }
    }

    timer.stop();
    std::cout << "Function took: " << timer.getDurationInSeconds() << " s" << std::endl;
    return HamiltonianCycle;
}

template <class T>
void fullyConnect(Graph<T> &g){

    vector<Vertex<T>*> unvisited;

    //check if fully connected
    g.bfs(g.findVertex(0));
    bool allVisited = true;
    for(Vertex<T>* v : g.getVertexSet()){
        if(!v->isVisited()){
            allVisited = false;
            unvisited.push_back(v);
            g.bfs(v);
        }
    }
    if(allVisited)return;

    //make it fully connected

}