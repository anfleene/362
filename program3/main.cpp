#include "plane.h"
#include "event_list.h"
#include "event.h"
#include "server.h"

using namespace std;

int main ()
{
	//build an event list
	event_list el = event_list();
	//grab its pointer
	event_list *elst = &el;
	//build a server
	server s = server(elst);
	//creates the package queue
	queue<package> *q1;
	//create the plane queue
	queue<plane> *q2;
	//set the queues on the server
	q1 = s.get_package_queue();
	q2 = s.get_plane_queue();
	//set snapshot to -1
	int snapshotTime = -1;
	//prompt for snapshot time
	cout << "What Time would you Like a Snapshot of the model?" << endl;
	cin >> snapshotTime;
	//loops once for every event in the list until its empty or the next event is out of the time range
	while(!el.empty() && el.front().getTime() < event_list::END)
	{
		//first event
		event e = el.pop_front();
		//push new package to package queue if its a package event
		if(e.getType() == event::PKG_ARRIVAL)
		{
			q1->push(package(e.getDestination(), e.getTime()));
		}
		//push to new plane to plane queue if its a plane event
		else if(e.getType() == event::PLANE_ARRIVAL)
		{
			q2->push(plane(e.getDestination()));
		}
		//eos the server gets to work
		else
		{
			s.work(e.getTime());
		}
		//if this time is between the current event and the next event print the snapshot and prompt for another snapshot
		if(snapshotTime >= e.getTime() && snapshotTime <= el.front().getTime())
		{
			cout << "Current Time: " << el.front().getTime() << endl;
			s.print();
			cout << "What Time would you Like the next Snapshot?(Please select a Time greater than " << el.front().getTime() << ")" << endl;
			cin >> snapshotTime;
		}
		
	}
	//print one more time for the finished product
	s.print();
	return 0;
}