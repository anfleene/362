/*
*Name: Andrew Fleener
*Date: 9/22/09
*Description: The event list object is basically a wrapper class for list<event> however it containts several functions designed for
*building the initial event list, it uses a few static constants that describe the paramters requred to build the event list
* this class contains several methods such as push and pop_front that are modified to behave the way i would like
*/
#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include "event.h"

class event_list
{
public:
	static const int PKG_ARRIVAL_TIME = 10;
	static const int CHI_ARRIVAL_TIME = 150;
	static const int MEM_ARRIVAL_TIME = 180;
	static const int FIRST_PKG = 5;
	static const int FIRST_CHI_PLANE = 80;
	static const int FIRST_MEM_PLANE = 100;
	static const int FIRST_END_OF_SERVICE = 8;
	static const int END = 2000;
	event_list();
	void push(event);
	event front(){return this->todo.front();};
	event pop_front();
	bool empty(){return this->todo.size() <= 0;};
	void print();
	list<event> get_list(){return this->todo;};
	
private:
 	void print(list<event>);
	void build_list();
	void build_pkg_list();
	void build_chi_plane_list();
	void build_mem_plane_list();
	void print(list<event>*);
	list<event> todo;
	list<event> finished;
};

#endif