#ifndef DIGRAPH
#define DIGRAPH
#include "utility.h"
class Digraph{
public:
	Digraph(){
		this->adj_mat = new vector<vector<int> >();
	};
	Digraph(string);
	~Digraph();
	void LoadAdjacencyMatrix(string);
	void printShortestPath(int, int);
	void findShortestPaths(int);
	void printAdjMatrix();
private:
	vector<vector<int> >* adj_mat;//this is the adjacency matrix of the graph
	vector<int>* distance;//this set of vectors contains the shortest path form i to j
	vector<bool>* found;//has the node been found yet?
	vector<int>* parent;//where did you come from
};
#endif

