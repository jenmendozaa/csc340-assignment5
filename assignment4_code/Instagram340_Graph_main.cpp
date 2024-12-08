#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"

int main() {
	// Create a list of Users
	vector<User> users; 

	// Add 10 distinct users to the vector
	// TO DO 

	// Initialize a graph with n vertices (where n is the number of Users) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 


	// Add edges (userA, userB, weight)
	// TO DO 

	// Print the adjacency list
	g.printGraph();

	// Depth First traversal should print User information not just indices
	int start = 0;
	// Call DFT 
	// g.DFT(0, ...);


	bool found = false;
	// Depth First search
	string username1 = ""; //replace with a username that exists 
	// Call DFS 
	// TO DO:  
	// found = g.DFS(username1, ...);
	if(found){
		cout << username1 << " has been found in the graph!" << endl;
	}else{
		cout << username1 << " has not been found in the graph!" << endl;
	}

	string username2 = ""; //replace with a username that DOES NOT exist 
	// Call DFS 
	// TO DO:
	// found = g.DFS(username2, ...);
	if(found){
		cout << username1 << " has been found in the graph!" << endl;
	}else{
		cout << username1 << " has not been found in the graph!" << endl;
	}

	return 0;
}
