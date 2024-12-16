#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>  // For std::pair
#include "LinkedBagDS/LinkedBag.h"  // Include LinkedBag
#include "User.h"

using namespace std;

// Template class for a Graph
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool directed = false);

    // Add an edge
    void addEdge(int u, int v, T weight = T());

    // Get number of nodes
    int getNumVertices() const;

    // Print the adjacency list
    void printGraph() const;

    // Get neighbors of a vertex (as a vector)
    vector<pair<int, T>> getNeighbors(int vertex) const;

    // Depth First Traversal
    void DFT(int start, const std::vector<User>& users) const;
    void DFTRecursive(int v, std::vector<bool>& visited, const std::vector<User>& users) const;

    // Depth First Search
    bool DFS(int start, const string& targetUsername, const vector<User>& users) const;
    bool DFSRecursive(int v, const string& targetUsername, vector<bool>& visited, const vector<User>& users) const;

private:
    int V;                          // Number of vertices
    bool directed;                  // Whether the graph is directed or undirected
    vector<LinkedBag<pair<int, T>>> adjList;  // Adjacency list using LinkedBag
};

#include "Graph.cpp"  // Include implementation
#endif // GRAPH_H
