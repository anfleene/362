#include "plane.h"
#include "event_list.h"
#include "event.h"
#include "server.h"

using namespace std;

int main ()
{
	srand ( std::time(NULL) );
	event_list el = event_list();
	event_list *elst = &el;
	server s = server(elst);
	queue<package> *q1;
	queue<plane> *q2;
	q1 = s.get_package_queue();
	q2 = s.get_plane_queue();
	int snapshotTime = -1;
	cout << "What Time would you Like a Snapshot of the model?" << endl;
	cin >> snapshotTime;
	while(!el.empty() && el.front().getTime() < event_list::END)
	{
		event e = el.pop_front();
		if(snapshotTime >= e.getTime() && snapshotTime <= el.front().getTime())
		{
			cout << "Current Time: " << el.front().getTime() << endl;
			s.print();
			cout << "What Time would you Like the next Snapshot?(Please select a Time greater than " << el.front().getTime() << ")" << endl;
			cin >> snapshotTime;
		}
		if(e.getType() == event::PKG_ARRIVAL)
		{
			q1->push(package(e.getDestination()));
		}
		else if(e.getType() == event::PLANE_ARRIVAL)
		{
			q2->push(plane(e.getDestination()));
		}
		else
		{
			s.work(e.getTime());
		}
	}
	// s.print();
	// event e = event(3, 24, 1);
	// e.print();
	return 0;
}