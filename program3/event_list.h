#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include "utility.h"
#include "package.h"
#include "plane.h"
#include "event.h"

class event_list
{
public:
	event_list(list<event>&);
	
private:
	void build_list();
	list<event> list;
};
#endif