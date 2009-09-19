#include "package_creator.h"
#include "utility.h"

using namespace std;

package package_creator::next_pkg()
{
	int dest = rand() % 2 + 1;
	package p = package(dest);
	return p;
}