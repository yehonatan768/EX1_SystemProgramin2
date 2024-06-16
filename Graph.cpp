/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#include <vector>
#include <iostream>
#include "Graph.hpp"
#include <iomanip>

/**
 * @brief Loads the graph from the given adjacency matrix.
 * 
 * @param g The adjacency matrix representing the graph.
 * @throws std::invalid_argument if the matrix is not square or contains self edges.
 */
void Graph::setMatrix(std::vector<std::vector<int>> g) {
    if (g.empty() || g.size() != g[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }

    for (size_t i = 0; i < g.size(); ++i) {
        if (g[i].size() != g.size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    this->g = std::move(g);
    this->size = this->g.size();
}

/**
 * @brief Prints the adjacency matrix representing the graph.
 */
void Graph::printGraph() {
    for (const auto& row : this->g) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Returns the adjacency matrix of the graph.
 * 
 * @return std::vector<std::vector<int>> The adjacency matrix of the graph.
 */
std::vector<std::vector<int>> Graph::getMatrix() {
    std::vector<std::vector<int>> ans = this->g;
    return ans;
}

