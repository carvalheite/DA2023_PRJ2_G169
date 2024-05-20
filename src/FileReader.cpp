//
// Created by crvlh8 on 5/15/24.
//

#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

FileReader::FileReader(Graph<int> *g) {
    this->g = g;
}


bool FileReader::loadToyGraph(int n) {
    ifstream file;
    string str;
    char delim = '\n';
    switch (n){
        case 1:
            file.open("../graphs/Toy-Graphs/shipping.csv");
            break;
        case 2:
            file.open("../graphs/Toy-Graphs/stadiums.csv");
            break;
        case 3:
            file.open("../graphs/Toy-Graphs/tourism.csv");
            delim = ',';
            break;
        default:
            cout << "Invalid option" << endl;
            return false;
    }

    if (file.is_open()) {
        getline(file, str);
    } else {
        cout << "Failed to open file" << endl;
        return false;
    }

    while (getline(file, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());

        stringstream ss(str);
        string strOrig, strDest, strDist, oLabel, dLabel;
        getline(ss, strOrig, ',');
        getline(ss, strDest, ',');
        getline(ss, strDist, ',');

        if (n == 3) {
            getline(ss, oLabel, ',');
            getline(ss, dLabel, ',');
        }

        int orig = stoi(strOrig), dest = stoi(strDest);
        double dist = stod(strDist);

        if (g->findVertex(orig) == nullptr) {
            g->addVertex(orig);
            g->findVertex(orig)->setLabel(oLabel);
        }

        if (g->findVertex(dest) == nullptr) {
            g->addVertex(dest);
            g->findVertex(dest)->setLabel(dLabel);
        }

        g->addBidirectionalEdge(orig, dest, dist);
    }

    return true;
}

bool FileReader::loadRealGraph(int n) {
    ifstream edges, nodes;
    string str;
    switch (n){
        case 1:
            edges.open("../graphs/Real-world Graphs/graph1/edges.csv");
            nodes.open("../graphs/Real-world Graphs/graph1/nodes.csv");
            break;
        case 2:
            edges.open("../graphs/Real-world Graphs/graph2/edges.csv");
            nodes.open("../graphs/Real-world Graphs/graph2/nodes.csv");
            break;
        case 3:
            edges.open("../graphs/Real-world Graphs/graph3/edges.csv");
            nodes.open("../graphs/Real-world Graphs/graph3/nodes.csv");
            break;
        default:
            cout << "Invalid option" << endl;
            return false;
    }

    if (nodes.is_open()) {
        getline(nodes, str);
    } else {
        cout << "Failed to open nodes file" << endl;
        return false;
    }

    int nodesNo = 0, edgesNo = 0;
    while (getline(nodes, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());

        stringstream ss(str);
        string strId, strLat, strLon;
        getline(ss, strId, ',');
        getline(ss, strLat, ',');
        getline(ss, strLon, ',');

        int id = stoi(strId);
        double lat = stod(strLat), lon = stod(strLon);

        if (g->findVertex(id) == nullptr) {
            g->addVertex(id);
            g->findVertex(id)->setLatitude(lat);
            g->findVertex(id)->setLongitude(lon);
            nodesNo++;
        }
    }

    if (edges.is_open()) {
        getline(edges, str);
    } else {
        cout << "Failed to open edges file" << endl;
        return false;
    }

    while (getline(edges, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());

        stringstream ss(str);
        string strOrig, strDest, strDist;
        getline(ss, strOrig, ',');
        getline(ss, strDest, ',');
        getline(ss, strDist, ',');

        int orig = stoi(strOrig), dest = stoi(strDest);
        double dist = stod(strDist);

        g->addBidirectionalEdge(orig, dest, dist);
        edgesNo++;
    }

    return true;
}

bool FileReader::loadExtraGraph(int n) {
    set<int> check = {25, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800, 900};
    if (check.find(n) == check.end()) {
        cout << "Invalid option" << endl;
        return false;
    }
    ifstream edges, nodes;
    string str;
    nodes.open("../graphs/Extra_Fully_Connected_Graphs/nodes.csv");
    string path = "../graphs/Extra_Fully_Connected_Graphs/edges_" + to_string(n) + ".csv";
    edges.open(path);

    if (nodes.is_open()) {
        getline(nodes, str);
    } else {
        cout << "Failed to open nodes file" << endl;
        return false;
    }

    int nodesNo = 0, edgesNo = 0;
    while (getline(nodes, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());

        stringstream ss(str);
        string strId, strLat, strLon;
        getline(ss, strId, ',');
        getline(ss, strLat, ',');
        getline(ss, strLon, ',');

        int id = stoi(strId);
        double lat = stod(strLat), lon = stod(strLon);

        if (g->findVertex(id) == nullptr) {
            g->addVertex(id);
            g->findVertex(id)->setLatitude(lat);
            g->findVertex(id)->setLongitude(lon);
            nodesNo++;
        }
    }

    if (!edges.is_open()) {
        cout << "Failed to open edges file" << endl;
        return false;
    }

    while (getline(edges, str)) {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());

        stringstream ss(str);
        string strOrig, strDest, strDist;
        getline(ss, strOrig, ',');
        getline(ss, strDest, ',');
        getline(ss, strDist, ',');

        int orig = stoi(strOrig), dest = stoi(strDest);
        double dist = stod(strDist);

        g->addBidirectionalEdge(orig, dest, dist);
        edgesNo++;
    }

    return true;
}

