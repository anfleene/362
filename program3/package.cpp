#include "package.h"

package::package(int dest)
{
	setDestination(dest);
}
void package::setDestination(int dest)
{
		this->destination = dest; 
}

void package::print()
{
	cout << "<package>" << endl;
	cout << "Destination: " << event::destination_string(this->destination) << endl;
	cout << "</package>" << endl << endl;
}