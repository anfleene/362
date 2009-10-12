#ifndef UTILITY_H
#define UTILITY_H

/**
**NAME: Andrew Fleener
**Course: CSCI 362
**Assignment: Program 1
**Class: utility
**Description: This is the interface for the utility class
**/
//Gives ANSI version of standard includes
//Also defines enumerated type for error
//messages 

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
#include <string>
#include <vector>

using namespace std;


enum Error_code { success, fail, exceeds_range, 
not_present, duplicate_error, underflow, overflow };

#endif //UTILITY_H
