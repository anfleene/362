#include "plane.h"
#include "package_creator.h"
#include "event_list.h"
#include "event.h"

using namespace std;

int main ()
{
	srand ( std::time(NULL) );
	event_list el = event_list();
	el.print();
	// event e = event(3, 24, 1);
	// e.print();
	return 0;
}