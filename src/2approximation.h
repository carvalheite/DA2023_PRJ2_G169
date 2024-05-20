/**
 * @file MSTGraph.h
 * @brief This file contains the implementation of the Minimum Spanning Tree (MST) algorithms and related helper functions.
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cfloat>
#include "../src/Graph.h"
#include "../src/MutablePriorityQueue.h"
#include "./MutablePriorityQueue.h"

using namespace std;

/**
 * @class UnionFind
 * @brief A class that implements the Union-Find (Disjoint Set Union) data structure.
 *
 * @tparam T The type of the elements in the Union-Find structure.
 */
template<typename T>
class UnionFind {
private:
    std::unordered_map<T, T> parent; /**< Stores the parent of each element. */

public:
    /**
     * @brief Constructs a UnionFind object with a given set of elements.
     *
     * @param elements A vector containing all the elements.
     */
    UnionFind(const std::vector<T>& elements) {
        for (const T& element : elements) {
            parent[element] = element;
        }
    }

    /**
     * @brief Finds the root of the element with path compression.
     *
     * @param element The element to find.
     * @return The root of the element.
     */
    T find(const T& element) {
        if (parent[element] == element) {
            return element;
        }
        return parent[element] = find(parent[element]);
    }

    /**
     * @brief Merges two sets containing the given elements.
     *
     * @param x The first element.
     * @param y The second element.
     */
    void merge(const T& x, const T& y) {
        T rootX = find(x);
        T rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

/**
 * @brief Ensures the graph is fully connected by adding high-weight edges between disconnected components.
 *
 * @tparam T The type of the vertices.
 * @param graph The graph to be made fully connected.
 */
template<typename T>
void ensureFullyConnected(Graph<T>& graph) {
    std::vector<Vertex<T>*> vertices = graph.getVertexSet();

    // Extract vertex information from the vertex pointers
    std::vector<T> vertexInfo;
    for (Vertex<T>* vertex : vertices) {
        vertexInfo.push_back(vertex->getInfo());
    }

    UnionFind<T> uf(vertexInfo);  // Initialize Union-Find with all vertices

    // Merge vertices based on existing edges
    for (Vertex<T>* vertex : vertices) {
        for (Edge<T>* edge : vertex->getAdj()) {
            Vertex<T>* neighbor = edge->getDest();
            uf.merge(vertex->getInfo(), neighbor->getInfo());
        }
    }

    // Add edges between disconnected components
    for (Vertex<T>* u : vertices) {
        for (Vertex<T>* v : vertices) {
            if (u != v && uf.find(u->getInfo()) != uf.find(v->getInfo())) {
                // Add an edge between u and v with a very high weight
                graph.addBidirectionalEdge(u->getInfo(), v->getInfo(), DBL_MAX);
                uf.merge(u->getInfo(), v->getInfo());
            }
        }
    }
}

/**
 * @brief Checks if the graph is fully connected.
 *
 * @tparam T The type of the vertices.
 * @param graph The graph to be checked.
 * @return True if the graph is fully connected, false otherwise.
 */
template<typename T>
bool isConnected(const Graph<T>& graph) {
    graph.bfs(0);

    for (Vertex<T>* v : graph.getVertexSet()) {
        if (!v->isVisited()) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Computes the Minimum Spanning Tree (MST) of the given graph using Prim's algorithm and returns a Hamiltonian cycle.
 *
 * @tparam T The type of the vertices.
 * @param graph The graph for which the MST is computed.
 * @param tourDistance A reference to a double that will store the total distance of the tour.
 * @return A vector of vertices representing the Hamiltonian cycle.
 */
template <class T>
std::vector<Vertex<T> *> primMST(Graph<T> &graph, double &tourDistance) {
    Timer timer;
    timer.start();

    if (!isConnected(graph)) {
        ensureFullyConnected(graph);
    }

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
                if (std::numeric_limits<double>::infinity() == neighbour->getDist()) priorityQueue.insert(neighbour);
                neighbour->setDist(weight);
                neighbour->setPath(neighbourEdge);
                priorityQueue.decreaseKey(neighbour);
            }
        }
    }

    // Create a graph representing the MST
    Graph<int> mstGraph;
    for (Vertex<T>* vertex : mst) {
        mstGraph.addVertex(vertex->getInfo());
        if (vertex->getPath() != nullptr) mstGraph.addBidirectionalEdge(vertex->getPath()->getOrig()->getInfo(), vertex->getPath()->getDest()->getInfo(), vertex->getPath()->getWeight());
    }

    // Step 2: Create a tour by traversing the MST using DFS
    auto tour = mstGraph.dfs();
    tour.push_back(mstGraph.findVertex(0)->getInfo());

    // Tour by vertices
    vector<Vertex<T>*> tourByPointer;
    for (auto v : tour) {
        Vertex<T>* tempVertex = mstGraph.findVertex(v);
        tourByPointer.push_back(tempVertex);
        tempVertex->setVisited(false);
    }

    // Remove duplicates
    vector<Vertex<T>*> HamiltonianCycle;
    for (auto v : tourByPointer) {
        if (!v->isVisited()) {
            HamiltonianCycle.push_back(v);
        }
    }

    // Tour Distance
    for (size_t iter = 0; iter < HamiltonianCycle.size() - 1; iter++) {
        for (Edge<T>* edge : HamiltonianCycle[iter]->getAdj()) {
            if (edge->getDest() == HamiltonianCycle[iter + 1]) {
                tourDistance += edge->getWeight();
            }
        }
    }

    timer.stop();
    std::cout << "Function took: " << timer.getDurationInSeconds() << " s" << std::endl;
    return HamiltonianCycle;
}


