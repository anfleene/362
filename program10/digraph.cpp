#include "digraph.h"
#include <sstream>

Digraph::Digraph(string filename){
	LoadAdjacencyMatrix(filename);
	this->distance = new vector<int>();
	this->distance->resize(this->adj_mat->size());
	this->found = new vector<bool>();	
	this->found->resize(this->adj_mat->size());
	this->parent = new vector<int>();	
	this->parent->resize(this->adj_mat->size());
}
Digraph::~Digraph(){
	delete this->distance;
	delete this->found;
	delete this->parent;
	delete this->adj_mat;
}

void Digraph::LoadAdjacencyMatrix(string filename){
	this->adj_mat = new vector<vector<int> >();
	ifstream file;
	istringstream ins;
	int max, i, j, dist;
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	string line;
	while (! file.eof() )
    {
      getline (file,line);
			ins.str(line);
			ins >> i >> j >> dist;
			ins.clear();
			max = (i > j) ? i : j;
			if(max >= this->adj_mat->size()){
				this->adj_mat->resize(max+1);
				vector<vector<int> >::iterator it;
				for(it = this->adj_mat->begin(); it < this->adj_mat->end(); it++){
					(*it).resize(max+1);
				}
			}
			this->adj_mat->at(i).at(j) = dist;
    }
    file.close();
		for(int i=0; i < this->adj_mat->size(); i++){
			for(int j=0; j < this->adj_mat->size(); j++){
				if((i != j) && this->adj_mat->at(i).at(j) == 0)
					this->adj_mat->at(i).at(j) = numeric_limits<int>::max();
			}
		}
}

void Digraph::findShortestPaths(int node){
	//set initial distances
	for(int i=0; i < this->adj_mat->size(); i++){
		this->distance->at(i) = this->adj_mat->at(node).at(i);
		this->found->at(i) = false;
		this->parent->at(i) = node;
	}
	this->found->at(node) = true;
	this->distance->at(node) = 0;
	for(int v=0; v < this->found->size(); v++){
		this->found->at(v) = true;
		for(int u=v; u < this->found->size(); u++){
			if(	this->distance->at(v) != numeric_limits<int>::max() && 
					this->adj_mat->at(v).at(u) != numeric_limits<int>::max() && 
					this->distance->at(u) > (this->distance->at(v) + this->adj_mat->at(v).at(u))
				){
				this->distance->at(u) = abs(this->distance->at(v) + this->adj_mat->at(v).at(u));
				this->parent->at(u) = v;
			}
				
		}
	}
}

void Digraph::printShortestPath(int start, int finish){
	findShortestPaths(start);
	if(this->distance->at(finish) == numeric_limits<int>::max()){
		cout << "No Path Exists between nodes " << start << " and " << finish << endl;
		return;
	}
	int current = finish;
	stack<int> path = stack<int>();
	cout << "Shortest Path from "<< start << " to " << finish << ": ";
	while(current != start){
		path.push(current);
		current = this->parent->at(current);
	}
	path.push(start);
	while(!path.empty()){
		cout << path.top() << " ";
		path.pop();
	}
	cout << endl;
	cout << "Total weight: " << this->distance->at(finish) << endl << endl;
}

void Digraph::printAdjMatrix(){
	for(int i=0; i < this->adj_mat->size(); i++){
		for(int j=0; j < this->adj_mat->at(i).size(); j++){
			cout << this->adj_mat->at(i).at(j) << " ";
		}
		cout << endl;
	}
}

