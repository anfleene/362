#include "plane.h"
#include "package_creator.h"
#include "utility.h"

using namespace std;

int main ()
{
	package pkg;
	plane *p = new plane(1);
	package_creator pc = package_creator();
	for(int i=0; i < 25; i++)
	{
		pkg = pc.next_pkg();
		p->loadPkg(pkg);
	}  
	return 0;
}