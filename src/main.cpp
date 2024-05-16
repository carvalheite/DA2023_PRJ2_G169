#include <iostream>
#include "Graph.h"
#include "FileReader.h"

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    fr.loadRealGraph(1);

    Vertex<int> *v1 = g.findVertex(1);
    Vertex<int> *v2 = g.findVertex(2);

    cout << "Haversine distance between 1-2 is " << v1->haversineDistance(v2) << endl;

    return 0;
}
