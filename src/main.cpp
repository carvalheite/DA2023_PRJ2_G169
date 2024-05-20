#include <iostream>
#include "Graph.h"
#include "FileReader.h"
#include "backtraking.h"
#include "2approximation.h"

using namespace std;

int main() {
    Graph<int> g;
    FileReader fr(&g);
    fr.loadRealGraph(2);
    double res;
    vector<int> s;
    vector<int> t;
    auto prism = primMST(g,res);

    for(auto z : prism){
        cout << z->getInfo() <<"->";
    }
    cout << endl;

    cout << endl << res;


    return 0;

}
