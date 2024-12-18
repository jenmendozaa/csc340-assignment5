#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"

int main() {
	// Create a list of Users
	vector<User> users;

	// Add 10 distinct users to the vector
	// Create 10 distinct users
	users.push_back(User("Alice", "alice@example.com", "password123", "Loves photography", "alice.jpg"));
	users.push_back(User("Bob", "bob@example.com", "password123", "Foodie and traveler", "bob.jpg"));
	users.push_back(User("Charlie", "charlie@example.com", "password123", "Tech enthusiast", "charlie.jpg"));
	users.push_back(User("David", "david@example.com", "password123", "Music lover", "david.jpg"));
	users.push_back(User("Eve", "eve@example.com", "password123", "Fitness trainer", "eve.jpg"));
	users.push_back(User("Frank", "frank@example.com", "password123", "Nature lover", "frank.jpg"));
	users.push_back(User("Grace", "grace@example.com", "password123", "Artist and painter", "grace.jpg"));
	users.push_back(User("Hannah", "hannah@example.com", "password123", "Bookworm", "hannah.jpg"));
	users.push_back(User("Isaac", "isaac@example.com", "password123", "Math geek", "isaac.jpg"));
	users.push_back(User("Judy", "judy@example.com", "password123", "Loves animals", "judy.jpg"));


	// Initialize a graph with n vertices (where n is the number of Users) 
	// Indicate whether it is directed or undirected
	Graph<int> g(10, false);

	srand(time(0));

	// Add edges (userA, userB, weight)
	g.addEdge(0, 1, 5);  // Alice ↔ Bob
	g.addEdge(0, 2, 3);  // Alice ↔ Charlie
	g.addEdge(0, 3, 2);  // Alice ↔ David
	g.addEdge(1, 4, 6);  // Bob ↔ Eve
	g.addEdge(1, 5, 7);  // Bob ↔ Frank
	g.addEdge(2, 6, 4);  // Charlie ↔ Grace
	g.addEdge(2, 7, 2);  // Charlie ↔ Hannah
	g.addEdge(3, 8, 8);  // David ↔ Isaac
	g.addEdge(3, 9, 5);  // David ↔ Judy
	g.addEdge(4, 5, 3);  // Eve ↔ Frank
	g.addEdge(4, 6, 6);  // Eve ↔ Grace
	g.addEdge(5, 7, 7);  // Frank ↔ Hannah
	g.addEdge(6, 8, 4);  // Grace ↔ Isaac
	g.addEdge(7, 9, 6);  // Hannah ↔ Judy
	g.addEdge(8, 9, 3);  // Isaac ↔ Judy

	// Print the adjacency list
	g.printGraph();

	// Depth First traversal should print User information not just indices
	int start = 0;
	// Call DFT 
	g.DFT(0, users);



	// Depth First search
	string username1 = "David"; //replace with a username that exists
	// Call DFS
	// TO DO:  
	// found = g.DFS(username1, ...);
	bool found = g.DFS(0, username1, users);
	if(found){
		cout << username1 << " has been found in the graph!" << endl;
	}else{
		cout << username1 << " has not been found in the graph!" << endl;
	}

	string username2 = "Zara";  // Non-existing username
	found = g.DFS(0, username2, users);

	if (found) {
		cout << username2 << " has been found in the graph!" << endl;
	} else {
		cout << username2 << " has not been found in the graph!" << endl;
	}

	return 0;
}
