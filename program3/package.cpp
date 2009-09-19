#include "package.h"

package::package()
{
	destination = package::UNKNOWN;
}
package::package(int dest)
{
	setDestination(dest);
}
void package::setDestination(int dest)
{
	if((dest == package::MEM ) || (dest == package::CHI))
	{
		this->destination = dest; 
	} 
	else
		{
			this->destination = package::UNKNOWN;
		}
}