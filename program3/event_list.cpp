#include "event_list.h"

event_list::event_list()
{
	build_list();
}

void event_list::build_list()
{
//builds the list of packages
	build_pkg_list();
//builds the list chicago planes
	build_chi_plane_list();
//builds the list of memphis planes
	build_mem_plane_list();
//add the first end of service event
	push(event::eos(event_list::FIRST_END_OF_SERVICE));
}

//this method builds an event list of packages
void event_list::build_pkg_list()
{
	list<event> pkg_list = list<event>();
	event first = event(event::PKG_ARRIVAL, event_list::FIRST_PKG, event::MEM);
	pkg_list.push_back(first);
	//loops once for the last pkg event's time plus 10 until the last event's time plus 10 is greater than 2000
	for(int i=pkg_list.back().getTime() + event_list::PKG_ARRIVAL_TIME; (pkg_list.back().getTime() + event_list::PKG_ARRIVAL_TIME) < event_list::END; i += event_list::PKG_ARRIVAL_TIME)
	{
		//creates a new package arival event with time set to i and a destination randomly selected by 50/50 chance
		pkg_list.push_back(event::pkg(i));
	}
//merge into todo list this is sorted automatically	
	this->todo.merge(pkg_list);
}

//build list of chicago plane arivals
void event_list::build_chi_plane_list()
{
	list<event> p_list;
	event first = event(event::PLANE_ARRIVAL, event_list::FIRST_CHI_PLANE, event::CHI);
	p_list.push_back(first);
//loops once for every chicago arival (last arival + 150) while that time is less than 2000
	for(int i=p_list.back().getTime() + event_list::CHI_ARRIVAL_TIME; p_list.back().getTime() + event_list::CHI_ARRIVAL_TIME < END; i += event_list::CHI_ARRIVAL_TIME)
	{
		p_list.push_back(event::plane(i, event::CHI));
	}
	//merge and sort with todo
	this->todo.merge(p_list);
}

//builds a list of memphis planes
void event_list::build_mem_plane_list()
{
	list<event> p_list;
	event first = event(event::PLANE_ARRIVAL, event_list::FIRST_MEM_PLANE, event::MEM);
	p_list.push_back(first);
	//loops once for every memphis arival (last ariabal + 180) while time is less than 2000
	for(int i=p_list.back().getTime() + event_list::MEM_ARRIVAL_TIME; p_list.back().getTime() + event_list::MEM_ARRIVAL_TIME < END; i += event_list::MEM_ARRIVAL_TIME)
	{
		p_list.push_back(event::plane(i, event::MEM));
	}
	//merge and sort with todo
	this->todo.merge(p_list);
}

//push a new event into the list in right location
void event_list::push(event e)
{
	//dont insert any events past the end time(2000)
	if(e.getTime() < event_list::END)
	{
		//create a new list then merge that list in so that the event is sorted into the list automatically
		list<event> elist;
		elist.push_back(e);
		this->todo.merge(elist);
	}
}

//pop the first event off the list
event event_list::pop_front()
{
	//grab the first event
	event e = this->todo.front(); 
	//pop it from the list
	this->todo.pop_front();
	//add it to the finished pile 
	this->finished.push_back(e);
	return e;
}

//print out the todo list and the finished list
void event_list::print()
{
	cout << "*********************************************************" << endl;
	cout << "******************Events Left to Finish******************" << endl;
	cout << "*********************************************************" << endl;
	print(this->todo);
	cout << "*********************************************************" << endl;
	cout << "*********************Finished Events*********************" << endl;
	cout << "*********************************************************" << endl;
	print(this->finished);
}

//print an event list
void event_list::print(list<event> el)
{
	//loop through each event and print it
	int i=0;
	list<event>::iterator it;
	for (it=el.begin(); it!=el.end(); ++it)
	{
		++i;
		event e = *it;
		cout << "Event #: " << i << endl;
		e.print();
	}
}