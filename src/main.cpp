#include <iostream>
#include "Graph.h"
#include "FileReader.h"

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    fr.loadRealGraph(3);

    for (auto vertex : g.getVertexSet()){
        for (auto edge : vertex->getAdj()) {
            cout << vertex->getInfo() << " -> " << edge->getDest()->getInfo() << " : " << edge->getWeight() << endl;
        }
    }

    return 0;
}
