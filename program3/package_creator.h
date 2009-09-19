#ifndef PACKAGE_CREATOR_H
#define PACKAGE_CREATOR_H

#include "package.h"

class package_creator
{
public:
	package_creator(){	srand ( time(NULL) ); };
	package next_pkg();
};

#endif