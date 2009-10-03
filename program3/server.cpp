#include "server.h"

//builds a new server and initializes all of the stacks and queues and lists
server::server(event_list* elst)
{
	this->el = elst;
	this->chi_dock = new stack<package>;
	this->mem_dock = new stack<package>;
	this->pkg_queue = new queue<package>;
	this->plane_queue = new queue<plane>;
	this->departed_planes = new queue<plane>;
	this->finished = new list<package>;
	
}

//this method determines what the server should do next now that an end of service event has occured
void server::work(int time_a)
{
	if(this->plane_queue->size() > 0)
	{
		p_plane(time_a);
	}
	else if(this->pkg_queue->size() > 0)
	{
		p_pkg(time_a);
	}
	else
	{
		s_forklift(time_a);
	}
	
}

//this method processes a package
void server::p_pkg(int time_a)
{
	//create a new eos for the correct time
	add_eos(time_a + package::PROCESS_TIME);
	package p = this->pkg_queue->front();
	//pop it out of the queue
	this->pkg_queue->pop();
	//sort it and push it onto the right stack
	if(p.getDestination() == package::CHI)
	{
		this->chi_dock->push(p);
	}
	else
	{
		this->mem_dock->push(p);
	}
}

//this method processes a plane 
void server::p_plane(int time_a)
{
	//set departure time and create an eos
	int departure_time = time_a + plane::PROCESS_TIME;
	add_eos(departure_time);
	stack<package>* pkgs;
	//get the next plane in the queue and pop it
	plane p = this->plane_queue->front();
	this->plane_queue->pop();
	
	//grab the stack that for the planes destination
	if(p.getDestination() == plane::CHI)
	{
		pkgs = this->chi_dock;
	}
	else
	{
		pkgs = this->mem_dock;
	}
	
	//load the plane with packages while the plaine isn't full and there are packages in the stack
	while(p.isNotFull() && pkgs->size() != 0)
	{
		//set the departure time of the package
		package *pkg  = &pkgs->top();
		pkg->setTimeOut(departure_time);
		//update package stats
		update_package_info(pkg->totalTime());
		//push the package onto the plane
		p.loadPkg(pkg);
		//add the package to the finished list
		this->finished->push_back(*pkg);
		//pop it off it's dock
		pkgs->pop();
	}
	//push the plane onto the finished stack
	this->departed_planes->push(p);
}

//this method updates the stats of the server
void server::update_package_info(int t)
{
	//if no short time is set set it to the current one
	if(this->shortest_process_time == 0)
	{
		this->shortest_process_time = t;
	}
	//as long as the time is a valid one
	if(t != -1)
	{	
		//if this took the longest update it
		if(t > this->longest_process_time)
			this->longest_process_time = t;
		//if this took the shortest update it
		if(t < this->shortest_process_time)
			this->shortest_process_time = t;
		//add the time to the total process time
		this->total_process_time += t;
	}
}

//add an eos 6 units after the current time
void server::s_forklift(int time_a)
{
	add_eos(time_a + forklift::PROCESS_TIME);
}

//builds an end of service event(this is a helper method that shortens the call)
void server::add_eos(int a_time)
{	
	this->el->push(event::eos(a_time));
}

//print everything
void server::print()
{
	cout << "*********************************************************" << endl;
	cout << "**********************Event List*************************" << endl;
	cout << "*********************************************************" << endl;
	this->el->print();
	
	print_package_queue();

	print_dock_stacks();

	print_plane_queue();

	print_stats();
	
}

//print just the server stats
void server::print_stats()
{
	cout << "*********************************************************" << endl;
	cout << "*********************Statistics**************************" << endl;
	cout << "*********************************************************" << endl;
	cout << "Total Number of Packages Processed: "<< this->finished->size() << endl;
	cout << "Minimum Package Process Time: " << this->shortest_process_time << endl;
	cout << "Maximum Package Process Time: " << this->longest_process_time << endl;
	cout << "Average Package Process Time: " << average_process_time() << endl;
}

//calculate the average process time of the server
int server::average_process_time()
{
	double average;
	average = this->total_process_time/this->finished->size();
	return (int)average;
}

//print out the package queue
void server::print_package_queue()
{
	cout << "*********************************************************" << endl;
	cout << "*********************Package Queue***********************" << endl;
	cout << "*********************************************************" << endl;
	queue<package> temp = *this->pkg_queue;
	
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Package #: " << i << endl;
		package p = temp.front();
		p.print();
		temp.pop();
		i++;
	}
}

//print out the plane queues
void server::print_plane_queue()
{
	cout << "*********************************************************" << endl;
	cout << "**********************Plane Queue************************" << endl;
	cout << "*********************************************************" << endl;
	queue<plane> temp = *this->plane_queue;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Plane #: " << i << endl;
		temp.front().print();
		temp.pop();
		i++;
	}
	cout << "*********************************************************" << endl;
	cout << "********************Departed Planes**********************" << endl;
	cout << "*********************************************************" << endl;	
	queue<plane> temp2 = *this->departed_planes;
	i=1;
	while(temp2.size() != 0)
	{
		cout << "Plane #: " << i << endl;
		temp2.front().print();
		temp2.pop();
		i++;
	}
}

//print out the dock stacks
void server::print_dock_stacks()
{
	cout << "*********************************************************" << endl;
	cout << "*********************Chicago Stack***********************" << endl;
	cout << "*********************************************************" << endl;
	stack<package> temp = *this->chi_dock;
	int i=1;
	while(temp.size() != 0)
	{
		cout << "Package #: " << i << endl;
		temp.top().print();
		temp.pop();
		i++;		
	}
	
	cout << "*********************************************************" << endl;
	cout << "*********************Memphis Stack***********************" << endl;
	cout << "*********************************************************" << endl;
	stack<package> temp2 = *this->mem_dock;
	i=1;
	while(temp2.size() != 0)
	{
		cout << "Package #: " << i << endl;
		temp2.top().print();
		temp2.pop();
		i++;		
	}
}