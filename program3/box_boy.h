#ifndef BOX_BOY_H
#define BOX_BOY_H

class box_boy
{
public:
	box_boy(event_list);
	void work();
	
private:
	void process(event);
	void queue_pkg(event);
	void queue_plane(event);
	void p_pkg();
	void p_plane(event);
	void s_forklift(event);
	void add_eos(int a_time);	
	stack<package> chi_dock;
	stack<package> mem_dock;
	queue<package> pkg_queue;
	queue<plane> plane_queue;
	event_list todo;
	event_list finished;
};
#endif