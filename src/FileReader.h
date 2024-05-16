//
// Created by crvlh8 on 5/15/24.
//

#ifndef DA2023_PRJ2_G169_FILEREADER_H
#define DA2023_PRJ2_G169_FILEREADER_H

#include "Graph.h"

class FileReader {
public:
    explicit FileReader(Graph<int> *g);

    bool loadToyGraph(int n);
    bool loadRealGraph(int n);
    //bool loadExtraGraph(int n);

private:
    Graph<int> *g;
};


#endif //DA2023_PRJ2_G169_FILEREADER_H
