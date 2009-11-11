#include "avl_tree.h"

template <class T>
void print(Key<T> &k){
	cout << k << " " << endl;
}

void loadVectorFromFile(string filename, vector<Key<int> > &vec)
{
	int size = 500;
	ifstream file;
	vec.resize(size);
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	int el;
	for(int i=0; i < size; i++)
	{
		file >> el;
		Key<int> k(el);
		//add a new element at the current position
		vec.at(i) = k;
	}
}

void buildAvlTree(vector<Key<int> > &vec, AVL_tree<Key<int> > &avl_tree){
	int size = 200;
	for(int i=0; i < size; i++){
		avl_tree.insert(vec.at(i));
	}
}

void buildSearchTree(vector<Key<int> > &vec, Search_tree<Key<int> > &s_tree){
	int size = 200;
	for(int i=0; i < size; i++){
		if(s_tree.tree_search(vec.at(i)) != success )
			s_tree.insert(vec.at(i));
	}
}

// void avl_search(vector<Key<int> > &vec, AVL_tree<Key<int> > &avl_tree){
// 	int size = 500;
// 	for(int i=0; i < size; i++){
// 		avl_tree.tree_search(vec.at(i));
// 	}
// }

void search(vector<Key<int> > &vec, Search_tree<Key<int> > &search_tree){
	int size = 500;
	for(int i=0; i < size; i++){
		search_tree.tree_search(vec.at(i));
	}
}

vector<double> comparisons(vector<Key<int> > &vec){
	AVL_tree<Key<int> > aTree;
	buildAvlTree(vec, aTree);
	Search_tree<Key<int> > sTree;
	buildSearchTree(vec, sTree);
	Key<int>::comparisons = 0;
	search(vec, aTree);	
	int avl_comps = Key<int>::comparisons;
	Key<int>::comparisons = 0;
	search(vec, sTree);
	int bst_comps = Key<int>::comparisons;	
	double num_comps = 500;
	vector<double> comps;
	comps.resize(3);
	comps.at(0) = (bst_comps/num_comps);
	comps.at(1) = (avl_comps/num_comps);
	comps.at(2) = (comps.at(1)/ comps.at(0));
	return comps;
}

int main ()
{
	vector<Key<int> > vec_a;
	vector<Key<int> > vec_b;
	vector<Key<int> > vec_c;
	loadVectorFromFile("Lab7a.txt", vec_a);
	loadVectorFromFile("Lab7b.txt", vec_b);
	loadVectorFromFile("Lab7c.txt", vec_c);
	
	vector<double> comp_a = comparisons(vec_a);
	vector<double> comp_b = comparisons(vec_b);
	vector<double> comp_c = comparisons(vec_c);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << "               " << "Average search compares" << setw(25) << "Average search compares" << setw(20) << "Col. 1 as %" << endl;
	cout << setw(30) << "average tree" << setw(25) << "AVL tree" << setw(27) << "of col. 2" << endl;		
	cout << "Trial 1" << setw(20) << comp_a.at(0) << setw(27) << comp_a.at(1) << setw(26) << comp_a.at(2) << endl;		
	cout << "Trial 2" << setw(20) << comp_b.at(0) << setw(27) << comp_b.at(1) << setw(26) << comp_b.at(2) << endl;		
	cout << "Trial 3" << setw(20) << comp_c.at(0) << setw(27) << comp_c.at(1) << setw(26) << comp_c.at(2) << endl;			

return 0;
}