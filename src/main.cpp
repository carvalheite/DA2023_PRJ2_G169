#include <iostream>
#include "Graph.h"
#include "FileReader.h"
#include "SimAnneal.h"
#include <chrono>

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    auto startParsing = chrono::high_resolution_clock::now();
    fr.loadRealGraph(1);
    auto endParsing = chrono::high_resolution_clock::now();
    cout << "Parsing time: " << chrono::duration_cast<chrono::milliseconds>(endParsing - startParsing).count() << "ms" << endl;

    vector<double> distances;
    auto start = chrono::high_resolution_clock::now();
    distances.push_back(calculateDistance(simulatedAnnealing(&g, 1), g.findVertex(1)));
    auto end = chrono::high_resolution_clock::now();
    cout << "Best result: " << fixed << *min_element(distances.begin(), distances.end()) << endl;
    cout << "Execution time: " << chrono::duration_cast<chrono::seconds>(end - start).count() << "s" << endl;

    return 0;
}
