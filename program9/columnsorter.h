#ifndef COLUMN_SORTER
#define COLUMN_SORTER

#include "utility.h"

struct Matrix {
	vector<vector<short> >* the_matrix;
	int row_size;
	int column_size;
	
	Matrix(){
		this->the_matrix = new vector<vector<short> >();
		this->row_size = 0;
		this->column_size =0;
	};
	
	Matrix(int r, int s){
		this->the_matrix = new vector<vector<short> >();
		this->row_size = r;
		this->column_size = s;
	}
	
	Matrix(vector< vector<short> > *vec, int r, int s){
		this->the_matrix = vec;
		this->row_size = r;
		this->column_size = s;
	};
	
	~Matrix(){delete this->the_matrix;};
	
	//load a column at the pos
	vector<short> loadColumn(int pos){
		vector<short> vec;
		vector<vector<short> >::iterator it;
		//loop the rows
		for(it=this->the_matrix->begin(); it < this->the_matrix->end(); it++){
			//add the value at the pos to the return vector
			vec.push_back((*it).at(pos));
		}
		return vec;
	};
	
	int size(){
		//number of rows
		return this->the_matrix->size();
	};
	
	vector<short> at(int pos){
		//vector at pos
		return this->the_matrix->at(pos);
	};
	
	//updates all the values in this column with the passed vector
	void updateColumn(int pos, vector<short> vec){
		for(int i=0; i < vec.size(); i++){
			this->the_matrix->at(i).at(pos) = vec.at(i);
		}
	};
	
	//insert a new column into the matix
	void insertColumn(vector<short> vec){
		vector<short> row;
		for(int i=0; i < vec.size(); i++){
			row = this->the_matrix->at(i);
			if(this->row_size == row.size())
				row.resize((row.size()+1));
			this->the_matrix->at(i).push_back(vec.at(i));
		}
	};
	
	//grab a row at the passed position
	vector<short> loadRow(int pos){
		return the_matrix->at(pos);
	};
	//update the row at pos with the values in vec
	void updateRow(int pos, vector<short> vec){
		the_matrix->at(pos) = vec;
	};
	
	//insert a new row at the end of the matrix
	void insertRow(vector<short> vec){
		if(this->column_size == this->the_matrix->size())
			this->the_matrix->resize((this->the_matrix->size()+1));
		this->the_matrix->push_back(vec);
	};
	
};

class ColumnSorter{
public:
	//constructors
	ColumnSorter();
	ColumnSorter(Matrix*);
	ColumnSorter(vector<vector<short> >*, int, int);
	//destructor
	~ColumnSorter();
	//sort the matrix
	void sort();
	//the matrix in this class
	Matrix* mat;
private:
	//sort each column individually
	void sortAllColumns();
	//sort a column at the passed position
	void sortColumn(int);
	//a quicksort for this sorter
	void quickSort(vector<short>&);
	//this does the recursion of the quicksort
	void recursiveQuickSort(vector<short>&, int, int);
	//transposes columns to rows
	void transColToRow();
	//transposes rows to columns
	void transRowToCol();
	//shifts half a column with -inf values and fills the rest of the new column with +inf
	void shiftRight();
	//returns the list back to normal by removing all the +-inf's
	void shiftLeft();
};
#endif
