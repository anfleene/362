#include "digraph.h"
bool again()
{
	string yesNo;
	cout << "Again?(y/n) "<< endl;
	cin >> yesNo;
	return (yesNo == "y" || yesNo == "Y") ? true : false;
}

int main(){
	Digraph dg = Digraph("graphsample.txt");
	int start, finish;
	do{
		cout << endl;
		cout << "Enter The Starting Node: ";
		cin >> start
		cout << "Enter The Ending Node: ";
		cin >> finish;
		dg.printShortestPath(start, finish);
	}while(again());
	return 0;
}