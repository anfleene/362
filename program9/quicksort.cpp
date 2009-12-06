#include "utility.h"
#include "timer.h"

void recursiveQuickSort(vector<short> *vec, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = vec->at((left + right) / 2);
      /* partition */
      while (i <= j) {
            while (vec->at(i) < pivot)
                  i++;
            while (vec->at(j) > pivot)
                  j--;
            if (i <= j) {
                  tmp = vec->at(i);
                  vec->at(i) = vec->at(j);
                  vec->at(j) = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            recursiveQuickSort(vec, left, j);
      if (i < right)
            recursiveQuickSort(vec, i, right);
}

void quickSort(vector<short> *vec){
	recursiveQuickSort(vec, 0, vec->size()-1);
}

void loadMatrixFromFile(string filename, int size, vector<short> *vec)
{
	ifstream file;
	file.open( filename.c_str());
	if ( !file )
	{ 
		exit(1);
	}
	short el;
	vec->resize(size);
	vector<short>::iterator it;
	for(it=vec->begin(); it < vec->end(); it++)
	{
	
			file >> el;
			//add a new element at the current position
			(*it) = el;	
	}
}

int main(){
	vector<short> *vec = new vector<short>();
	loadMatrixFromFile("Lab9.txt", 100000, vec);
	Timer a_timer = Timer();
	quickSort(vec);
	double elapsed = a_timer.elapsed_time();
	vector<short>::iterator it;	
	for(it=vec->begin(); it < vec->end(); it++)
		cout << *it << endl;
	cout << "Elapsed Time: " << elapsed << endl;
return 0;
}