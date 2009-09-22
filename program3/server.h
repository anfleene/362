#ifndef SERVER_H
#define SERVER_H

#include "event_list.h"
#include "plane.h"
#include "forklift.h"

class server
{
public:
	server(event_list*);
	void work(int);
	stack<package>* get_chi_dock(){stack<package> *s; s = &this->chi_dock; return s;};
	stack<package>* get_mem_dock(){stack<package> *s; s = &this->mem_dock; return s;};
	queue<package>* get_package_queue(){queue<package> *q; q = &this->pkg_queue; return q;};
	queue<plane>* get_plane_queue(){queue<plane> *q; q = &this->plane_queue; return q;};
	void print();
	void print(queue<package> &);
	void print(queue<plane> &);
	void print(stack<package> &);
private:
	void p_pkg(int);
	void p_plane(int);
	void s_forklift(int);
	void add_eos(int a_time);	
	stack<package> chi_dock;
	stack<package> mem_dock;
	queue<package> pkg_queue;
	queue<plane> plane_queue;
	queue<plane> departed_planes;
	event_list* el;
};
#endif