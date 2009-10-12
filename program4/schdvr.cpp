/*
*Name: Andrew Fleener
*Date: 10/6/09
*Description: This is the client program for the ordered list search class
*/
#include "ordered_list.h"
#include "key.h"
#include <iomanip>

//builds a vector of Keys from a file passed a string
vector<Key> loadVectorFromFile(string filename)
{
	vector<Key> vec;
	ifstream file;
	file.open( filename.c_str());
	//cant open file
	if ( file.fail() )
	{ 
	    cerr << "Unable to open file " << filename;
	    exit(1);   // call system to stop
	}
	int i;
	//while there is another int
	while(file >> i)
	{
		Key a_key (i);
		//add a new element at the current position
		vec.push_back(a_key);
	}
	//keep VS(the devil) happy
	file.close();
	file.clear();
	return vec;
}
//build an ordered list of odd ints from 1 - n
Ordered_list<Key> build_o_list(int n){
	Ordered_list<Key> ol;
	for(int i=1; i <= n; i+= 2){
			Key k (i);
		ol.insert(k);
	}
	return ol;
}

//preform a searches on an ordered list
double do_search(string type, Ordered_list<Key> &ol, vector<Key> &search){
	//reset comparisons
	Key::comparisons = 0;
	//run once for every search term in the vector
	for(int i=0; i < search.size(); i++){
		Key k = search.at(i);
		int pos;
		Error_code error_c;
		//search using:
		//sequentail
		if(type.compare("seq") == 0){
			error_c = ol.sequential_search(k, pos);
		//short sequential
		}else if(type.compare("short_seq") == 0){
			error_c = ol.short_sequential_search(k, pos);
		//binary 1
		}else if(type.compare("b1") == 0){
			error_c = ol.binary1(k, pos);
		//binary 2
		}else if(type.compare("b2") == 0){
			error_c = ol.binary2(k, pos);
		//dont search and exit because there was bad input
		}else{
			cout << "There Was an error" << endl;
			exit(1);
		}
	}
	//return the average of total number of comparisions/# of searches
	return (Key::comparisons/search.size());
}

//preform all four searches for a given vector ex: 10odd or 10even
ofstream & all_searches(string filename, Ordered_list<Key> &o_list, ofstream &output){
	//build the vector from the file passed in
	vector<Key> v_key = loadVectorFromFile(filename);
	//preform all the searches
	double seq_ave = do_search("seq", o_list, v_key);
	double short_seq_ave = do_search("short_seq", o_list, v_key);
	double bin1_ave = do_search("b1", o_list, v_key);
	double bin2_ave = do_search("b2", o_list, v_key);
	//print the averages
	cout << setw(20) << seq_ave << setw(15) << short_seq_ave << setw(15) << bin1_ave << setw(15) << bin2_ave << endl;
	//put the averages into the outfile stream
	output << setw(20) << seq_ave << setw(15) << short_seq_ave << setw(15) << bin1_ave << setw(15) << bin2_ave;
	//return the outfile stream
	return output ;
}
int main(){
	//set up pretty formating
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	//create a new file outstream
	ofstream outfile;
  	outfile.open ("results.txt");
	//make its formatting pretty
	outfile.setf(ios::fixed);
	outfile.setf(ios::showpoint);
	outfile.precision(3);
	//print header the row to cout and the fileout
	cout << setw(35) << "Sequential" << setw(15) << "Short Seq" << setw(15) << "Binary 1" << setw(15) << "Binary 2" << endl;
	outfile << setw(35) << "Sequential" << setw(15) << "Short Seq" << setw(15) << "Binary 1" << setw(15) << "Binary 2" << endl;
	//build and ordered list of odd ints from 1 to 20
	Ordered_list<Key> ol = build_o_list(20);
	//begin 10 number searches
	cout << "10 Successes:";
	outfile << "10 Successes:";
	//search 10 success 
	all_searches("odd10.txt", ol, outfile) << endl;
	cout << "10 Failures:";
	outfile << "10 Failures:";	
	//search 10 failures
	all_searches("even10.txt", ol, outfile) << endl;	
	ol = build_o_list(200);
	cout << "100 Successes:";
	outfile << "100 Successes:"; 
	//search 100 success 
	all_searches("odd100.txt", ol, outfile) << endl;
	cout << "100 Failures:";
	outfile << "100 Failures:";
	//search 100 failures
	all_searches("even100.txt", ol, outfile)<< endl;
	ol = build_o_list(2000);
	cout << "1000 Successes:";
	outfile << "1000 Successes:";
	//search 1000 success 
	all_searches("odd1000.txt", ol, outfile) << endl;
	cout << "1000 Failures:";
	outfile << "1000 Failures:";
	//search 1000 failures
	all_searches("even1000.txt", ol, outfile) << endl;
	//close the open file outstream
	outfile.close();
return 0;
}