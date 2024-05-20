#include <iostream>
#include "Graph.h"
#include "FileReader.h"
#include "NearestNeighbor.h"
#include <chrono>

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    auto startParsing = chrono::high_resolution_clock::now();
    fr.loadRealGraph(3);
    auto endParsing = chrono::high_resolution_clock::now();
    cout << "Parsing time: " << chrono::duration_cast<chrono::milliseconds>(endParsing - startParsing).count() << "ms" << endl;

    auto start = chrono::high_resolution_clock::now();
    vector<Vertex<int>*> path = nearestNeighbor(&g, 1);

    for (auto & i : path)
        cout << i->getInfo() << " ";
    cout << endl;
    cout << "Distance: " << calculateDistance(path) << endl;
    cout << "Number of vertices: " << g.getVertexSet().size() << endl;
    cout << "Number of visited cities: " << path.size() << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Results: " << endl;
    cout << "Execution time: " << chrono::duration_cast<chrono::seconds>(end - start).count() << "s" << endl;

    return 0;
}
