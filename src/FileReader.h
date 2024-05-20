//
// Created by crvlh8 on 5/15/24.
//

#ifndef DA2023_PRJ2_G169_FILEREADER_H
#define DA2023_PRJ2_G169_FILEREADER_H

#include "Graph.h"

/**
 * @class FileReader
 * @brief Handles loading graphs from files into a Graph object.
 */
class FileReader {
public:
    /**
     * @brief Constructs a FileReader with a given graph.
     * @param g Pointer to a Graph object.
     */
    explicit FileReader(Graph<int> *g);

    /**
     * @brief Loads a toy graph from a file.
     * @param n The number indicating which toy graph to load.
     * @return true if the graph is loaded successfully, false otherwise.
     * @complexity O(V + E) where V is the number of vertices and E is the number of edges in the graph.
     */
    bool loadToyGraph(int n);

    /**
     * @brief Loads a real-world graph from a file.
     * @param n The number indicating which real-world graph to load.
     * @return true if the graph is loaded successfully, false otherwise.
     * @complexity O(V + E) where V is the number of vertices and E is the number of edges in the graph.
     */
    bool loadRealGraph(int n);

    /**
    * @brief Loads a Extra graph from a file.
    * @param n The number indicating which real-world graph to load.
    * @return true if the graph is loaded successfully, false otherwise.
    * @complexity O(V + E) where V is the number of vertices and E is the number of edges in the graph.
    */
     bool loadExtraGraph(int n);

private:
    Graph<int> *g; ///< Pointer to the Graph object to be populated.
};

#endif // DA2023_PRJ2_G169_FILEREADER_H
