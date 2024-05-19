#include <iostream>
#include "Graph.h"
#include "FileReader.h"
#include "backtraking.h"
#include "2approximation.h"

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    fr.loadToyGraph(3);
    double res;
    vector<int> s;

    primMST(g,res);

    cout  <<res;
    cout << "\nBacktracking: " << backtracking(g,s);
    return 0;

}
