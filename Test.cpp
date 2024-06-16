/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */


#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>


using namespace std;
using namespace Algorithms;

TEST_CASE("Test isConnected")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::isConnected(g) == 1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(Algorithms::isConnected(g) == 0);
}

TEST_CASE("Test shortestPath")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 100},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {100, 0, 0, 1, 0}};
    g.setMatrix(graph3);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.setMatrix(graph4);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->4");

    vector<vector<int>> graph5 = {
        {0, -1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {1, 0, 0, -1, 0}};
    g.setMatrix(graph5);
    
    CHECK(Algorithms::shortestPath(g, 0, 0) == "0");
    
}
TEST_CASE("Test isContainsCycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
    

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph3);
    CHECK(Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    g.setMatrix(graph4);
    CHECK(Algorithms::isContainsCycle(g) == false);
}


TEST_CASE("Test isBipartite")
{
    Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph1);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.setMatrix(graph3);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.setMatrix(graph4);
    CHECK(isBipartite(g) == "0");

    vector<vector<int>> graph5 = {{0}};
    g.setMatrix(graph5);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0}, B={}");

    vector<vector<int>> graph6 = {
        {0, 1},
        {1, 0}
    };
    g.setMatrix(graph6);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0}, B={1}");

    vector<vector<int>> graph7 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph7);
    CHECK(isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}


TEST_CASE("Test negativeCycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph);
    CHECK(Algorithms::negativeCycle(g)=="No Negative Cycle");


    vector<vector<int>> graph2 = {
        {0, 1, 0, -100},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {-100, 0, 1, 0},
    };
    g.setMatrix(graph2);
    CHECK(Algorithms::negativeCycle(g)=="0->3->0");


    vector<vector<int>> graph3 = {
        {0, 1, 0, -100},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    g.setMatrix(graph3);
    CHECK(Algorithms::negativeCycle(g)=="2->3->0->1->2");
}
