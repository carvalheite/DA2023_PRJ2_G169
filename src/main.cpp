#include <iostream>
#include "Graph.h"
#include "FileReader.h"
#include "backtraking.h"

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    fr.loadToyGraph(3);

    vector<int> res;
    double a = backtracking(g,res);
    cout << a<<endl;
    for(auto x : res){
        cout << "ID: " << x << endl;
    }

    return 0;
}
