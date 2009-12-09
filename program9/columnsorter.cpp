#include "columnsorter.h"

ColumnSorter::ColumnSorter(){
	this->mat = new Matrix();
}
ColumnSorter::ColumnSorter(Matrix* mat){
	this->mat = mat;
}
ColumnSorter::ColumnSorter(vector<vector<short> > *vec, int r, int s){
	this->mat = new Matrix(vec, r, s);
}
ColumnSorter::~ColumnSorter(){
	delete this->mat;
}

//this method completes the entire sort
void ColumnSorter::sort(){
	sortAllColumns();
	transColToRow();
	sortAllColumns();
	transRowToCol();
	sortAllColumns();
	shiftRight();
	sortAllColumns();
	shiftLeft();
}

//this method sorts each column in the matrix
void ColumnSorter::sortAllColumns(){
	for(int i=0; i < this->mat->column_size; i++){
		sortColumn(i);	
	}
}

//this will make a column into a vector, sort it and put it back into the matrix
void ColumnSorter::sortColumn(int c_pos){
	vector<short> col = this->mat->loadColumn(c_pos);
	quickSort(col);
	this->mat->updateColumn(c_pos, col);
}

//this method transposes every column into rows, keeping the shape of the matrix
void ColumnSorter::transColToRow(){
	vector<short> all_values;
	vector<short> col;
	vector<short>::iterator col_it;
	vector<vector<short> >::iterator mat_it;
	//loop through the columns
	for(int i=0; i < this->mat->column_size; i++){
		col = this->mat->loadColumn(i);
		//loop through all the rows of the column
		for(col_it=col.begin(); col_it < col.end(); col_it++){
			//add the values all_values vec
			all_values.push_back((*col_it));
		}
	}
	vector<short>::iterator all_values_it = all_values.begin();
	vector<short>::iterator row_it;
	//loop through the rows in the matrix
	for(mat_it=this->mat->the_matrix->begin(); mat_it < this->mat->the_matrix->end(); mat_it++){
		//loop through the values in the row
		for(row_it=(*mat_it).begin(); row_it < (*mat_it).end(); row_it++){
			//update the values in the row
			*row_it = *all_values_it;
			all_values_it++;
		}
	}
}

//this method transposes every row into columns, keeping the shape of the matirx
void ColumnSorter::transRowToCol(){
	vector<short> all_values;
	vector<short> row;
	vector<short>::iterator row_it;
	vector<vector<short> >::iterator mat_it;
	//load each row
	for(int i=0; i < this->mat->row_size; i++){
		row = this->mat->loadRow(i);
		//loop through teh values in the row
		for(row_it=row.begin(); row_it < row.end(); row_it++){
			//add values into all_values
			all_values.push_back((*row_it));
		}
	}
	vector<short>::iterator all_values_it = all_values.begin();
	vector<short>::iterator col_it;
	vector<short> col;
	//loop through and load the columns
	for(int i=0; i < this->mat->column_size; i++){
 		col = this->mat->loadColumn(i);
		//loop through the values in the column
		for(col_it=col.begin(); col_it < col.end(); col_it++){
			//update the value in the column
			*col_it = *all_values_it;
			all_values_it++;
		}
		//update the matrix column
		this->mat->updateColumn(i, col);
	}
}

void ColumnSorter::shiftRight(){
	vector<short> all_values;
	vector<short> col;
	vector<short>::iterator col_it;
	vector<vector<short> >::iterator mat_it;
	//put all values into a vector in column order
	for(int i=0; i < this->mat->column_size; i++){
		col = this->mat->loadColumn(i);
		for(col_it=col.begin(); col_it < col.end(); col_it++){
			all_values.push_back((*col_it));
		}
	}
	//add -inf and +inf to the front and back halfway on both ends
	for(int i=0; i < (this->mat->row_size/2); i++){
		all_values.insert(all_values.begin(), numeric_limits<short>::min());
		all_values.push_back(numeric_limits<short>::max());
	}
	
	//add another column
	for(mat_it=this->mat->the_matrix->begin(); mat_it < this->mat->the_matrix->end(); mat_it++){
		(*mat_it).resize((*mat_it).size() +1);
	}
	vector<short>::iterator all_values_it = all_values.begin();
	//loop through the columns
	for(int i=0; i < this->mat->column_size +1; i++){
		col.clear();
		//loop through the rows
		for(int j=0; j < this->mat->row_size; j++){
			this->mat->the_matrix->at(j).at(i) = *all_values_it;
			all_values_it++;
		}
	}
}

void ColumnSorter::shiftLeft(){
	vector<short> all_values;
	vector<short> col;
	vector<short>::iterator col_it;
	vector<vector<short> >::iterator mat_it;
	//put all values into a vector in column order
	for(int i=0; i < this->mat->column_size + 1; i++){
		col = this->mat->loadColumn(i);
		for(col_it=col.begin(); col_it < col.end(); col_it++){
			all_values.push_back((*col_it));
		}
	}
	//remove -inf and +inf to the front and back halfway on both ends
		all_values.erase(all_values.begin(), all_values.begin()+(this->mat->row_size/2));
		
	vector<short>::iterator all_values_it = all_values.begin();
	//loop through the columns
	for(int i=0; i < this->mat->column_size; i++){
		col.clear();
		//loop through the rows
		for(int j=0; j < this->mat->row_size; j++){
			this->mat->the_matrix->at(j).at(i) = *all_values_it;
			all_values_it++;
		}
	}
	//remove the extra column from the matrix
	for(mat_it=this->mat->the_matrix->begin(); mat_it < this->mat->the_matrix->end(); mat_it++){
		(*mat_it).resize((*mat_it).size() - 1);
	}
}

//this preforms a quicksort
void ColumnSorter::quickSort(vector<short> &vec){
	recursiveQuickSort(vec, 0, vec.size()-1);
}

//the recursive quicksort
void ColumnSorter::recursiveQuickSort(vector<short> &vec, int left, int right) {
      int i = left, j = right;
      int tmp;
//set the pivot
      int pivot = vec.at((left + right) / 2);
      while (i <= j) {
            while (vec.at(i) < pivot)
                  i++;
            while (vec.at(j) > pivot)
                  j--;
            if (i <= j) {
									//swap i and j
                  tmp = vec.at(i);
                  vec.at(i) = vec.at(j);
                  vec.at(j) = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            recursiveQuickSort(vec, left, j);
      if (i < right)
            recursiveQuickSort(vec, i, right);
}