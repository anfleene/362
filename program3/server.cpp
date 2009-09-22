#include "server.h"

server::server(event_list* elst)
{
	this->el = elst;
}

void server::work(int time_a)
{
	if(this->plane_queue.size() > 0)
	{
		p_plane(time_a);
	}
	else if(this->pkg_queue.size() > 0)
	{
		p_pkg(time_a);
	}
	else
	{
		s_forklift(time_a);
	}
	
}

void server::p_pkg(int time_a)
{
	add_eos(time_a + package::PROCESS_TIME);
	package p = this->pkg_queue.front();
	this->pkg_queue.pop();
	if(p.getDestination() == package::CHI)
	{
		this->chi_dock.push(p);
	}
	else
	{
		this->mem_dock.push(p);
	}
}

void server::p_plane(int time_a)
{
	add_eos(time_a + plane::PROCESS_TIME);
	stack<package> pkgs;
	plane p = this->plane_queue.front();
	this->plane_queue.pop();
	if(p.getDestination() == plane::CHI)
	{
		pkgs = this->chi_dock;
	}
	else
	{
		pkgs = this->mem_dock;
	}
	while(p.isNotFull() && pkgs.size() != 0)
	{
		p.loadPkg(pkgs.top());
		pkgs.pop();
	}
	this->departed_planes.push(p);
}

void server::s_forklift(int time_a)
{
	add_eos(time_a + forklift::PROCESS_TIME);
}

void server::add_eos(int a_time)
{	
	this->el->insert_event(event::eos(a_time));
}

void server::print()
{
	cout << "*********************************************************" << endl;
	cout << "**********************Event List*************************" << endl;
	cout << "*********************************************************" << endl;
	this->el->print();
	cout << "*********************************************************" << endl;
	cout << "*********************Package Queue***********************" << endl;
	cout << "*********************************************************" << endl;
	print(this->pkg_queue);
	cout << "*********************************************************" << endl;
	cout << "*********************Chicago Stack***********************" << endl;
	cout << "*********************************************************" << endl;
	print(this->chi_dock);
	cout << "*********************************************************" << endl;
	cout << "*********************Memphis Stack***********************" << endl;
	cout << "*********************************************************" << endl;
	print(this->mem_dock);
	cout << "*********************************************************" << endl;
	cout << "**********************Plane Queue************************" << endl;
	cout << "*********************************************************" << endl;
	print(this->plane_queue);
	cout << "*********************************************************" << endl;
	cout << "********************Departed Planes**********************" << endl;
	cout << "*********************************************************" << endl;
	print(this->departed_planes);
	
}

void server::print(queue<package> &pkgs)
{
	queue<package> temp = pkgs;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Package #: " << i << endl;
		temp.front().print();
		temp.pop();
		i++;
	}
}

void server::print(queue<plane> &planes)
{
	queue<plane> temp = planes;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Plane #: " << i << endl;
		temp.front().print();
		temp.pop();
		i++;
	}
}

void server::print(stack<package> &pkgs)
{
	stack<package> temp = pkgs;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Package #: " << i << endl;
		temp.top().print();
		temp.pop();
		i++;		
	}
}