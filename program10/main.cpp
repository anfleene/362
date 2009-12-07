#include "digraph.h"
//do you want to rerun the program?
bool again()
{
	string yesNo;
	cout << "Again?(y/n) "<< endl;
	cin >> yesNo;
	return (yesNo == "y" || yesNo == "Y") ? true : false;
}

int main(){
	//init digraph
	Digraph dg = Digraph("graphsample.txt");
	//init start and finish nodes
	int start, finish;
	do{
		//prompt for input
		cout << endl;
		cout << "Enter The Starting Node: ";
		cin >> start;
		cout << "Enter The Ending Node: ";
		cin >> finish;
		//locate and print the shortest path
		dg.printShortestPath(start, finish);
	}while(again());
	return 0;
}