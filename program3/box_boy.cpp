#include "box_boy.h"

box_boy::box_boy(event_list el)
{
	this->todo = el;
}

box_boy::work()
{
	event e = this->todo.pop_front;
	process(e);
	this->finished.push_back(e);
}

box_boy::process(event e)
{
	if(e.getType() == event::PKG_ARRIVAL)
	{
		queue_pkg(e);
	}
	else if(e.getType() = event::PLANE_ARRIVAL)
	{
		queue_plane(e);
	}
	else
	{
		p_eos(e);
	}
}

box_boy::queue_pkg(event e)
{
	package p = package(e.destination);
	pkg_queue.push_back(p);
	
}

box_boy::p_pkg(int time_a)
{
	add_eos(time_a + package::PROCESS_TIME);
}

box_boy::queue_plane(event e)
{
	plane p = plane(e.destination);
	plane_queue.push_back(p);
}

box_boy::p_plane(int time_a)
{
	add_eos(time_a + plane::PROCESS_TIME);
}