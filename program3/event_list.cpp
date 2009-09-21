#include "event_list.h"

event_list::event_list()
{
	build_list();
}

void event_list::build_list()
{
	build_pkg_list();
	build_chi_plane_list();
	build_mem_plane_list();
	insert_event(event::eos(event_list::FIRST_END_OF_SERVICE));
}

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
	
	this->e_list.merge(pkg_list);
}

void event_list::build_chi_plane_list()
{
	list<event> p_list;
	event first = event(event::PLANE_ARRIVAL, event_list::FIRST_CHI_PLANE, event::CHI);
	p_list.push_back(first);
	for(int i=p_list.back().getTime() + event_list::CHI_ARRIVAL_TIME; p_list.back().getTime() + event_list::CHI_ARRIVAL_TIME < END; i += event_list::CHI_ARRIVAL_TIME)
	{
		p_list.push_back(event::plane(i, event::CHI));
	}
	this->e_list.merge(p_list);
}

void event_list::build_mem_plane_list()
{
	list<event> p_list;
	event first = event(event::PLANE_ARRIVAL, event_list::FIRST_MEM_PLANE, event::MEM);
	p_list.push_back(first);
	for(int i=p_list.back().getTime() + event_list::MEM_ARRIVAL_TIME; p_list.back().getTime() + event_list::MEM_ARRIVAL_TIME < END; i += event_list::MEM_ARRIVAL_TIME)
	{
		p_list.push_back(event::plane(i, event::MEM));
	}
	this->e_list.merge(p_list);
}

void event_list::insert_event(event e)
{
	list<event> elist;
	elist.push_back(e);
	this->e_list.merge(elist);
}

void event_list::print()
{
	int i=0;
	list<event>::iterator it;
	for (it=this->e_list.begin(); it!=this->e_list.end(); ++it)
	{
		++i;
		event e = *it;
		cout << "------------------event: " << i << "------------------" << endl;
		e.print();
		cout << "------------------/event: " << i << "------------------" << endl;
	}
}