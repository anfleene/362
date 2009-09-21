#include "package.h"

package::package(int dest)
{
	setDestination(dest);
}
void package::setDestination(int dest)
{
		this->destination = dest; 
}