#include "columnsorter.h"
#include "timer.h"
//load a matrix from the file
void loadMatrixFromFile(string filename, int r, int s,vector<vector <short> > *vec)
{
	ifstream file;
	vec->resize(r);
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	short el;
	vector<short> row;
	row.resize(s);
	vector<short>::iterator row_it;
	vector<vector<short> >::iterator it;
	for(it=vec->begin(); it < vec->end(); it++)
	{
		for(row_it=row.begin(); row_it < row.end(); row_it++){
			file >> el;
			//add a new element at the current position
			(*row_it) = el;	
		}
		(*it) = row;
	}
}

//print the matrix to a file and std::out
void print_matrix(Matrix *mat, string filename, double elapsed){
		ofstream outf;
		outf.setf(ios::fixed);
		outf.setf(ios::showpoint);
		outf.precision(3);
		outf.open(filename.c_str());
		//format decimal output to 3 decimal places
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);
	vector<vector<short> >::iterator it;
	vector<short>::iterator row_it;
	for(it=mat->the_matrix->begin(); it < mat->the_matrix->end(); it++){
		for(row_it=(*it).begin(); row_it < (*it).end(); row_it++){
			cout << *row_it << " ";
			outf << *row_it << " ";
		}
		cout << endl;
		outf << endl;
	}
	//print the r, s, and elapsed time
	cout << "r value: " << mat->row_size << endl;
	outf << "r value: " << mat->row_size << endl;
	cout << "s value: " << mat->column_size << endl;
	outf << "s value: " << mat->column_size << endl;
	cout << "Elapsed Time: " << elapsed << endl;
	outf << "Elapsed Time: " << elapsed << endl;
		outf.close();
}
//check to see if the matrix is sorted
bool sortCheck(Matrix *mat){
	short prev;
	bool sorted = true;
	vector<short> all_values;
	vector<short> col;
	vector<short>::iterator col_it;
	//put all values into a vector in column order
	for(int i=0; i < mat->column_size; i++){
		col = mat->loadColumn(i);
		for(col_it=col.begin(); col_it < col.end(); col_it++){
			all_values.push_back((*col_it));
		}
	}
	//if i-1 is greater than i the list is not sorted
	for(int i=1; i < all_values.size(); i++){
		if(all_values.at(i-1) > all_values.at(i)){
			cout << all_values.at(i-1) << " > " << all_values.at(i) << endl;
			sorted = false;
		}
	}
	return sorted;
}
int main (){
	vector<vector<short> >*mat = new vector<vector<short> >();
	//r
	int row = 4000;
	//s
	int column = 25;
	//load the matrix
	loadMatrixFromFile("Lab9.txt", row, column, mat);
	Matrix *matrx = new Matrix(mat, row, column);
	ColumnSorter *cols =	new ColumnSorter(matrx);
	//start the timer
	Timer a_timer = Timer();
	//sort
	cols->sort();
	//calc the elapsed time
	double elapsed = a_timer.elapsed_time();
	//if sorted print the matrix and time elapsed
	if(sortCheck(cols->mat)){
			print_matrix(cols->mat, "result.txt", elapsed);
	}else{
		cout << "The matrix is not sorted" << endl;
	}
	return 0;
}