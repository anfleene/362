/*
*Name: Andrew Fleener
*Date: 12/07/09
*Description: This is the interface for the Directional graph class, it will only do a few things. First it can print the adj_matrix
*of all the nodes in the graph. Second it can locate the shortest path from a single node to all of the rest of the nodes. It uses
*Dijkstra's algorithm to produce these results. It will also printout the shortest path from node a to node b and the weight of that
*path
*/
#ifndef DIGRAPH
#define DIGRAPH
#include "utility.h"
class Digraph{
public:
	//default construct
	Digraph(){
		this->adj_mat = new vector<vector<int> >();
	};
	//normal construct
	//build an adj_matrix form a file
	Digraph(string);
	//destructor
	~Digraph();
	//build the adj_matrix from the file
	void LoadAdjacencyMatrix(string);
	//print the shortest path from a to b and the weight of that distance
	void printShortestPath(int, int);
	//locate all the shortest paths to the passed node
	void findShortestPaths(int);
	//print the adj_matrix
	void printAdjMatrix();
private:
	vector<vector<int> >* adj_mat;//this is the adjacency matrix of the graph
	vector<int>* distance;//this set of vectors contains the shortest path form i to j
	vector<bool>* found;//has the node been found yet?
	vector<int>* parent;//where did you come from
};
#endif

