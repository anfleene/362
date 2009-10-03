/*
*Name: Andrew Fleener
*Date: 9/22/09
*Description: This class is the largest class by far. It has control over nearly all of the data. It contains several stacks and queues
* that are used as the sorted packages stacks, and the incoming queues for packages and planes. This class also decides what to do on a 
* given end of service event and then preforms that action
*/
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
	stack<package>* get_chi_dock(){return this->chi_dock;};
	stack<package>* get_mem_dock(){return this->mem_dock;};
	queue<package>* get_package_queue(){return this->pkg_queue;};
	queue<plane>* get_plane_queue(){return this->plane_queue;};
	int get_num_pkgs_processed(){ return this->finished->size();};
	void print();
	void print_stats();
private:
	void print_package_queue();
	void print_plane_queue();
	void print_dock_stacks();
	void p_pkg(int);
	void p_plane(int);
	int average_process_time();
	void update_package_info(int);
	void s_forklift(int);
	void add_eos(int a_time);	
	stack<package>* chi_dock;
	stack<package>* mem_dock;
	queue<package>* pkg_queue;
	queue<plane>* plane_queue;
	queue<plane>* departed_planes;
	event_list* el;
	list<package>* finished;
	int longest_process_time;
	int shortest_process_time;
	double total_process_time;
};
#endif