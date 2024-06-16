/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

/**
 * @brief Class representing a graph.
 */
class Graph {
    int size; /**< The number of vertices in the graph. */
    std::vector<std::vector<int>> g; /**< The adjacency matrix representing the graph. */

public:
    /**
     * @brief Loads the graph from the given adjacency matrix.
     * 
     * @param g The adjacency matrix representing the graph.
     * @throws std::invalid_argument if the matrix is not square or contains self edges.
     */
    void setMatrix(std::vector<std::vector<int>> g);

    /**
     * @brief Prints the adjacency matrix representing the graph.
     */
    void printGraph();

    /**
     * @brief Returns the adjacency matrix of the graph.
     * 
     * @return std::vector<std::vector<int>> The adjacency matrix of the graph.
     */
    std::vector<std::vector<int>> getMatrix();

};

#endif // GRAPH_HPP
