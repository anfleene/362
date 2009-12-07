#include "digraph.h"
#include <sstream>

//construct Digraph
Digraph::Digraph(string filename){
	//build the adj matrix
	LoadAdjacencyMatrix(filename);
	//init distance
	this->distance = new vector<int>();
	this->distance->resize(this->adj_mat->size());
	//init found
	this->found = new vector<bool>();	
	this->found->resize(this->adj_mat->size());
	//init parent
	this->parent = new vector<int>();	
	this->parent->resize(this->adj_mat->size());
}

//destruct digraph
Digraph::~Digraph(){
	delete this->distance;
	delete this->found;
	delete this->parent;
	delete this->adj_mat;
}

//this method takes a file name and builds the adj matirx from it
void Digraph::LoadAdjacencyMatrix(string filename){
	//init matrix
	this->adj_mat = new vector<vector<int> >();
	//init file, string stream, and ints for file input
	ifstream file;
	istringstream ins;
	int max, i, j, dist;
	string line;
	//open the file
	file.open( filename.c_str());
	//bad file quit the program
	if ( !file )
	{ 
		exit(1);
	}
	//until you reach the end of the file
	while (! file.eof() )
    {
			//pull in the entire line
      getline (file,line);
			ins.str(line);
			//exstract the three ints from the line
			ins >> i >> j >> dist;
			//clear input
			ins.clear();
			max = (i > j) ? i : j;
			//if the adj_matrix is smaller than or equal to the largest value increase the size of the matrix to max+1
			if(max >= this->adj_mat->size()){
				this->adj_mat->resize(max+1);
				vector<vector<int> >::iterator it;
				//also resize all of the internal vectors to keep the matrix square
				for(it = this->adj_mat->begin(); it < this->adj_mat->end(); it++){
					(*it).resize(max+1);
				}
			}
			//add the distance between the two elements to the matrix
			this->adj_mat->at(i).at(j) = dist;
    }
    file.close();
		//if the distance between two points is not set, set it to inf(int max)
		//unless the i=j then the distance shold be 0
		for(int i=0; i < this->adj_mat->size(); i++){
			for(int j=0; j < this->adj_mat->size(); j++){
				if((i != j) && this->adj_mat->at(i).at(j) == 0)
					this->adj_mat->at(i).at(j) = numeric_limits<int>::max();
			}
		}
}

//this method finds the shortest paths between the argument and all other nodes
void Digraph::findShortestPaths(int node){
	//set initial distances
	for(int i=0; i < this->adj_mat->size(); i++){
		this->distance->at(i) = this->adj_mat->at(node).at(i);
		//no node has been found yet
		this->found->at(i) = false;
		//set the parent to node 
		this->parent->at(i) = node;
	}
	//the node has already been found
	this->found->at(node) = true;
	//the distance to node is 0
	this->distance->at(node) = 0;
	//find all elements in adj_matrix
	for(int v=0; v < this->found->size(); v++){
		this->found->at(v) = true;
		//find the shortest distnace form node to v
		//using all values in the adj_matrix
		for(int u=v; u < this->found->size(); u++){
			//if dist at v is inf and distance at adj_mat[v][u] && dist[u] is > dist[v] + adj_mat[v][u]
			if(	this->distance->at(v) != numeric_limits<int>::max() && 
					this->adj_mat->at(v).at(u) != numeric_limits<int>::max() && 
					this->distance->at(u) > (this->distance->at(v) + this->adj_mat->at(v).at(u))
			){
				//change the distance at u to dist[v] + adj_mat[v][u] and update the parent
				this->distance->at(u) = abs(this->distance->at(v) + this->adj_mat->at(v).at(u));
				this->parent->at(u) = v;
			}//end if
				
		}//end u loop
	}//end v loop
}//end func

void Digraph::printShortestPath(int start, int finish){
	//set up shortest paths
	findShortestPaths(start);
	//die fast if dist is inf
	if(this->distance->at(finish) == numeric_limits<int>::max()){
		cout << "No Path Exists between nodes " << start << " and " << finish << endl;
		return;
	}
	//start form the end
	int current = finish;
	stack<int> path = stack<int>();
	cout << "Shortest Path from "<< start << " to " << finish << ": ";
	//until you reach the root node
	while(current != start){
		//add the current node to the stack
		path.push(current);
		//update current
		current = this->parent->at(current);
	}
	//at the root node to the stack
	path.push(start);
	//pop the stack and print the node
	while(!path.empty()){
		cout << path.top() << " ";
		path.pop();
	}
	//add a pretty line
	cout << endl;
	//print the distance form start to finish
	cout << "Total weight: " << this->distance->at(finish) << endl << endl;
}

//print out the adj_matrix
void Digraph::printAdjMatrix(){
	for(int i=0; i < this->adj_mat->size(); i++){
		for(int j=0; j < this->adj_mat->at(i).size(); j++){
			cout << this->adj_mat->at(i).at(j) << " ";
		}
		cout << endl;
	}
}

