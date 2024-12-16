#include "Graph.h"

// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);
}
#include "Graph.h"

// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);  // Resize the vector of LinkedBag
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {
    // Prevent self-edges
    if (u == v) {
        std::cout << "Self-edges are not allowed: (" << u << ", " << v << ")" << std::endl;
        return;
    }

    // Add the edge if it doesn't already exist
    if (!adjList[u].contains({v, weight})) {
        adjList[u].addToEnd({v, weight});
    }

    // If the graph is undirected, add the reverse edge
    if (!directed) {
        if (!adjList[v].contains({u, weight})) {
            adjList[v].add({u, weight});
        }
    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const {
    return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ": ";
        std::vector<std::pair<int, T>> neighbors = adjList[i].toVector();  // Convert LinkedBag to vector
        for (const auto& neighbor : neighbors) {
            std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Get neighbors of a vertex
template <typename T>
std::vector<std::pair<int, T>> Graph<T>::getNeighbors(int vertex) const {
    return adjList[vertex].toVector();  // Return neighbors as a vector
}

// Depth-First Traversal
template <typename T>
void Graph<T>::DFT(int start, const std::vector<User>& users) const {
    // Ensure the starting vertex is within bounds
    if (start < 0 || start >= V) {
        std::cerr << "Invalid start vertex: " << start << std::endl;
        return;
    }

    std::vector<bool> visited(V, false);  // To keep track of visited vertices
    DFTRecursive(start, visited, users);
    std::cout << std::endl;
}

// Utility function for Depth-First Traversal (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, std::vector<bool>& visited, const std::vector<User>& users) const {
    visited[v] = true;

    // Print the user's information instead of the index
    std::cout << "Visiting User: " << users[v].getUsername()
              << ", Email: " << users[v].getEmail() << std::endl;

    // Recur for all the vertices adjacent to this vertex
    std::vector<std::pair<int, T>> neighbors = adjList[v].toVector();
    for (const auto& neighbor : neighbors) {
        if (!visited[neighbor.first]) {
            DFTRecursive(neighbor.first, visited, users);
        }
    }
}

// Depth-First Search
template <typename T>
bool Graph<T>::DFS(int start, const std::string& targetUsername, const std::vector<User>& users) const {
    // Ensure the starting vertex is within bounds
    if (start < 0 || start >= V) {
        std::cerr << "Invalid start vertex: " << start << std::endl;
        return false;
    }

    std::vector<bool> visited(V, false);  // To keep track of visited vertices
    return DFSRecursive(start, targetUsername, visited, users);
}

// Utility function for Depth-First Search (Recursive)
template <typename T>
bool Graph<T>::DFSRecursive(int v, const std::string& targetUsername, std::vector<bool>& visited, const std::vector<User>& users) const {
    visited[v] = true;

    // Check if the current user's username matches the target
    if (users[v].getUsername() == targetUsername) {
        std::cout << "User found: " << users[v].getUsername()
                  << ", Email: " << users[v].getEmail() << std::endl;
        return true;
    }

    // Recursively search unvisited neighbors
    std::vector<std::pair<int, T>> neighbors = adjList[v].toVector();
    for (const auto& neighbor : neighbors) {
        if (!visited[neighbor.first]) {
            if (DFSRecursive(neighbor.first, targetUsername, visited, users)) {
                return true;  // Return true if the target is found
            }
        }
    }

    return false;  // Return false if not found
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {
    adjList[u].push_back({v, weight});
    if (!directed) {
        adjList[v].push_back({u, weight});
    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const{
	return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (const auto& neighbor : adjList[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

// Get neighbors of a vertex
template <typename T>
const list<pair<int, T>>& Graph<T>::getNeighbors(int vertex) const {
    return adjList[vertex];
}


// DFS Traversal (Recursive approach)
template <typename T>
void Graph<T>::DFT(int start) const {
    vector<bool> visited(V, false); // To keep track of visited vertices
    DFTRecursive(start, visited);
    cout << endl;
}

// Utility function for DFS (Recursive)
template <typename T>
void Graph<T>::DFTRecursive(int v, vector<bool>& visited) const {
    visited[v] = true;
    cout << v << " "; // Visit the current vertex

    // Recur for all the vertices adjacent to this vertex
    for (const auto& neighbor : adjList[v]) {
        if (!visited[neighbor.first]) {
            DFTRecursive(neighbor.first, visited);
        }
    }
}

// -----------------------------------------------------
// Depth First Search (by username)
// TO DO
// Add DFS implementation
// Add DFSRecursive implementation
