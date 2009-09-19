#ifndef TERMNINAL_H
#define TERMNINAL_H

#include "package.h"	
#include "plane.h"

class terminal
{
public:
	terminal();
	void package_arival();
	void chi_plane_arival();
	void mem_plane_arival();
	void maintain_forklift();
	void process_pkg();
	
private:
	stack<package> chi_dock;
	stack<package> mem_dock;
	queue<package> pkg_queue;
	queue<plane> plane_queue;
	forklift the_lift;
};
#endif