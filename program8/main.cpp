#include "hashTable.h"

//build a vector<key> from a file of ints
void loadVectorFromFile(string filename, int size, vector<Key> &vec)
{
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
		Key k(el);
		//add a new element at the current position
		vec.at(i) = k;
	}
}

template <class T>
void insertIntoHashTable(HashTable<T> &ht, vector<T> &vec, int size){
	for(int i=0; i < size; i++){
		ht.insert(vec[i]);
	}
}

//search the hash table either starting at the front of the file vector or an offset from the back
template <class T>
double searchHashTable(HashTable<T> &ht, vector<T> &vec, int num_els, bool startBack){
	int start, end;
	if(startBack){
		start = vec.size() - num_els;
		end = vec.size();
	}else{
		start = 0;
		end = num_els;
	}
	Key::comparisons = 0;
	for(int i=start; i < end; i++){
		ht.search(vec[i]);
	}
	return double(Key::comparisons/num_els);
}

//does all the work, computes the averages and outputs them to the screen and adds them to the outfile
template <class T>
void AvgOut(vector<int> tbl_sizes, int num_fail_s, vector<T> &vec, ofstream &file){
	for(int i=0; i < tbl_sizes.size(); i++){
		int tbl_size = tbl_sizes[i];
		HashTable<Key> ht = HashTable<Key>();
		insertIntoHashTable(ht, vec, tbl_size);
		double average_un = searchHashTable(ht, vec, num_fail_s, true);
		double average_su = searchHashTable(ht, vec, tbl_size, false);
		int tbl_load = int((float(tbl_size)/num_fail_s) * 100);
		cout << tbl_load << "%"<< setw(30) << average_un << setw(27) << average_su << endl;		
		file << tbl_load << "%," << average_un << "," << average_su << endl;
	}
}


int main ()
{
	//set up outstreams
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
 	ofstream outf;
	outf.setf(ios::fixed);
	outf.setf(ios::showpoint);
	outf.precision(2);
	outf.open ("results.csv");
	//header row of output
	cout << "Table Load                " << "Unsuccessful" << setw(25) << "Successful" << endl;
	outf << "Table Load, Unsuccessful, Successful" << endl;
//Lab8a	
	vector<Key> lab8a;
	loadVectorFromFile("Lab8a.txt", 300, lab8a);
	HashTable<Key>::HASH_SIZE = 97;
	int a_size[] = {20, 50, 100, 200};
	vector<int> a_sizes = vector<int>(a_size, a_size + 4);
	//preform search for all sets at table size 100
	AvgOut(a_sizes, 100, lab8a, outf);

	//Lab8b
	vector<Key> lab8b;
	loadVectorFromFile("Lab8b.txt", 750, lab8b);
	HashTable<Key>::HASH_SIZE = 241;
	int b_size[] = {50, 125, 250, 500};
	vector<int> b_sizes = vector<int>(b_size, b_size + 4);
	//preform search for all sets at table size 250
	AvgOut(b_sizes, 250, lab8b, outf);

//close file
	outf.close();
	return 0;
}